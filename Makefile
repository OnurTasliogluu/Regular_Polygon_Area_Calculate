LD_FLAGS:=-lm
CUSTOM_INC:=-I./inc
OBJECTS:=polygon.o

polygon:	$(OBJECTS)
	$(CC)	$(LDFLAGS)	$(CUSTOM_INC)	$(OBJECTS)	main.c	$(LD_FLAGS)	-o	polygon

polygon.o:
	$(CC)	$(CFLAGS)	-c	src/polygon.c	$(CUSTOM_INC)

clean:
	rm	*.o	polygon