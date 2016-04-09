OBJ =  main.o wavFunc.o vtscreen.o waveinfo.o
APPNAME = waveApp
INCLUDE = vtscreen.h sound.h 

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm

%.o : %.c $(INCLUDE)
	gcc -c -o $@ $<

clean :
	rm $(OBJ) $(APPNAME)

