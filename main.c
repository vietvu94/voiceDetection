
#include <stdio.h>
#include <string.h>
#include "vtscreen.h"
#include "sound.h"

//function main begins program execution 
int main (){
	FILE *fp;
	char command[50];

	while(1){    //make an infinite loop
		system("arecord -q -f S16_LE -c1 -d1 -r44100 sample.wav");
		clearscreen();
		fp = fopen ("sample.wav", "r"); //"r" : to read file in read-only-mode 
		readBytesWAV(fp);
		fclose(fp);
	}
} //end main  
