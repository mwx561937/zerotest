SrcFiles=$(wildcard *.c)
ObjFiles=$(patsubst %.c,%.o,$(SrcFiles))
all:main
main:$(ObjFiles)
	gcc -o $@ -I ../include $(SrcFiles)
%.o:%.c
	gcc -c -I ../include $<

.PHONY:clean all

clean:
	rm -f *.o
	rm -f main 
