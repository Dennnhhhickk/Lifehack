all: main.o File.o
	gcc -m32 File.o main.o -o main

main.o: main.c
	gcc -c -m32 main.c

File.o: File.asm
	nasm -f elf File.asm

clean:
	rm -rf *.o main
