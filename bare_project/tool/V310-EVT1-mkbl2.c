#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ./mkbl2  u-boot.bin   bl2.bin   14436 
// argv[0]  argv[1]      argv[2]   argv[3]
int main (int argc, char *argv[])
{
	FILE		*fp;
	unsigned char	src;
	char		*Buf, *a;
	int		BufLen;
	int		nbytes, fileLen;
	unsigned int	checksum = 0;
	int		i;

	if (argc != 4)
	{
		printf("Usage: mkbl1 <source file> <destination file> <size> \n");
		return -1;
	}

	BufLen = atoi(argv[3]);
	Buf = (char *)malloc(BufLen);
	memset(Buf, 0x00, BufLen);

	fp = fopen(argv[1], "rb");
	if( fp == NULL)
	{
		printf("source file open error\n");
		free(Buf);
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	fileLen = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	nbytes = fread(Buf, 1, BufLen, fp);
	if (nbytes < 0) {
		printf("fread error...\n");
		exit(1);
	}

	fclose(fp);

	for(i = 0;i < (14 * 1024) - 4;i++)
	{
		checksum += (unsigned char)(Buf[i]);
	}
	*(unsigned int*)(Buf+i) = checksum;

	fp = fopen(argv[2], "wb");
	if (fp == NULL)
	{
		printf("destination file open error\n");
		free(Buf);
		return -1;
	}

	a	= Buf;
	nbytes	= fwrite( a, 1, BufLen, fp);

	if ( nbytes != BufLen )
	{
		printf("destination file write error\n");
		free(Buf);
		fclose(fp);
		return -1;
	}

	free(Buf);
	fclose(fp);

	return 0;
}
