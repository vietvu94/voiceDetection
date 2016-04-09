#include <stdio.h>
#include "sound.h"
#include "vtscreen.h"

//Function to display wav file information

void displayheader(WAVHDR hdr){
	float duration;
	char tems[100];
	unsigned int i;
 
	duration = (float) hdr.subchunk2Size/hdr.sampleRate/hdr.blockAlign;
	gotoxy(1,1);
	printf ("[");
	colorstring ("Duration: ", GREEN, bg(BLACK));
	sprintf(tems,"%.2f", duration);
	colorstring(tems, YELLOW,bg(BLACK));

	gotoxy(45,1);
	printf("][");
	colorstring ("Channel Number: ", GREEN, bg(BLACK));
	sprintf(tems,"%.2d",hdr.numChan);
	colorstring(tems, YELLOW,bg(BLACK));

	gotoxy (90,1);
	printf("]");

	gotoxy (1,2);
	printf ("[");
	colorstring ("Sample Rate: ", GREEN, bg(BLACK));
	sprintf(tems,"%d",hdr.sampleRate);
	colorstring(tems, YELLOW,bg(BLACK));

	gotoxy (45,2);
	printf ("][");
	colorstring ("Bits per sample: ", GREEN, bg(BLACK));
	sprintf(tems,"%d",hdr.bitsPerSample);
	colorstring(tems, YELLOW,bg(BLACK));

	gotoxy (90,2);
	printf ("]");

	gotoxy (1,3);
	for (i=0; i < 90; i++) 
		colorstring("_", RED, bg(BLACK)); 

}// end function
