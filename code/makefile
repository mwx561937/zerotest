SrcFiles=$(wildcard *.c)
ObjFiles=$(patsubst %.c,%.o,$(SrcFiles))
Lib=-lpthread
all:main
main:$(ObjFiles)
	gcc -o $@ $(SrcFiles) $(Lib)
%.o:%.c
	gcc -c $<

.PHONY:clean all

clean:
	rm -f *.o
	rm -f main 
