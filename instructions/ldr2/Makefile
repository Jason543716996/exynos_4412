
all:
	arm-linux-gcc -c start.S -I.
	arm-linux-gcc -c main.c -I.
#-Ttext指定了代码段的起始地址为0x50000000.
	arm-linux-ld start.o main.o -Ttext=0x50000000 -o arm
#从arm可执行文件中拷贝出除过头信息以外的二进制可执行文件到arm.bin
	arm-linux-objcopy -O binary arm arm.bin
	arm-linux-objdump -d arm > arm.S
clean:
	rm -f start.o main.o arm.*

