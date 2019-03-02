
all:
	arm-linux-gcc -c -mapcs led.S
	arm-linux-ld led.o -Ttext=0x50000000 -o arm
#从arm可执行文件中拷贝出除过头信息以外的二进制可执行文件到arm.bin
	arm-linux-objcopy -O binary arm arm.bin
	arm-linux-objdump -d arm > arm.S
clean:
	rm -f led.o main.o arm.*

