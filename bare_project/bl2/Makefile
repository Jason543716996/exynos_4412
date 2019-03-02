.PHONY:clean

TARGET		:= arm
BIN		:= $(TARGET).bin
ASM		:= start.o clock_init_tiny4412.o mem_init_tiny4412_r1.o
C_OBJS		:= main.o
CROSS_COMPILE	:= arm-linux-
LD_ADD		:= 0x02023400  #iROM_Booting.pdf P14

CC		:= $(CROSS_COMPILE)gcc
LD		:= $(CROSS_COMPILE)ld
OBJCOPY		:= $(CROSS_COMPILE)objcopy

####################################
all : $(TARGET)
	$(OBJCOPY) -O binary $< $(BIN)	

$(TARGET) : $(ASM) $(C_OBJS)
	$(LD) $(ASM) $(C_OBJS) -Ttext=$(LD_ADD) -o $@	
%.o : %.S
	$(CC) -c $< -o $@ -Iinclude
	
%.o : %.c
	$(CC) -c $< -o $@ -Iinclude

clean:
	rm -f *.o $(BIN)
