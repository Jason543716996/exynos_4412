.PHONY:clean

TARGET		:= arm
BIN		:= $(TARGET).bin
ASM		:= start.o
C_OBJS		:= main.o lib.o mmu.o rtc.o gic.o vector.o i2c.o tp.o
CROSS_COMPILE	:= arm-linux-
LD_ADD		:= 0x50000000

CC		:= $(CROSS_COMPILE)gcc
LD		:= $(CROSS_COMPILE)ld
OBJCOPY		:= $(CROSS_COMPILE)objcopy
LD_FLAGS	:= -L/opt/FriendlyARM/toolschain/4.5.1/lib/gcc/arm-none-linux-gnueabi/4.5.1/ -lgcc

####################################
all : $(TARGET)
	$(OBJCOPY) -O binary $< $(BIN)	

$(TARGET) : $(ASM) $(C_OBJS)
	$(LD) $(ASM) $(C_OBJS) -Ttext=$(LD_ADD) $(LD_FLAGS) -o $@	
%.o : %.S
	$(CC) -c $< -o $@ -Iinclude
	
%.o : %.c
	$(CC) -c $< -o $@ -Iinclude

clean:
	rm -f *.o $(BIN)
