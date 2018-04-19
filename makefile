OBJ = main.o sound.o screen.o comm.o
APPNAME = sound.a
TAR = sound.tar

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm -lcurl

%.o : %.c
	gcc -c -o  $@ $<

clean :
	rm $(OBJ) $(APPNAME)
archive :
	tar cf $(TAR) *
