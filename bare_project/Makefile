
all:
	make -C ./proj/;
	make -C ./bl2/;
	mv ./proj/arm.bin ./target/
	./tool/mkbl2  ./bl2/arm.bin  ./target/bl2.bin  14336
clean:
	make -C ./proj/ clean
	make -C ./bl2/ clean
