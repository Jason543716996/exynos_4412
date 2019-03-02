.PHONY:clean

TARGET		:= arm
BIN		:= $(TARGET).bin
ASM		:= start.o
C_OBJS		:= main.o led.o lib.o
CROSS_COMPILE	:= arm-linux-
LD_ADD		:= 0x50000000

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
