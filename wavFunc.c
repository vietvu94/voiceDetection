#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sound.h"
#include "vtscreen.h"


//Function to read the wav file and function call to calculate the RMS power. 
WAVHDR readBytesWAV(FILE *fp){
	int buffsize, i,j;
	WAVHDR myhdr;
	short *buff;
	double duration;
	fread(&myhdr, sizeof(myhdr),1,fp); //read WAV header
	definescroll (1,30);
	displayheader(myhdr);

	// End program if wave file has others bits per sample values than 16.
	if(myhdr.bitsPerSample !=16){
		printf("Bits per sample is not 16, can't read\n");
		exit(0);
	}// end if
	buffsize = myhdr.bitsPerSample/8 * myhdr.sampleRate/25 * myhdr.numChan;
	duration = (double) myhdr.subchunk2Size/myhdr.sampleRate/myhdr.blockAlign;
	buff = malloc(buffsize);
	for(i=0;i<duration*25;++i){
		fread(buff,buffsize,1, fp);

		//Code running when the channel number is 1.
		if (myhdr.numChan == 1){

			getRMS1channel(myhdr, i, j, buff);
		}// end if

		//Code running when the channel number is 2.
		else if(myhdr.numChan == 2){

			getRMS2channel(myhdr, i, j, buff);
		}//end if
		// Cannot calculate RMS power of the wav files with other number channels yet.
		else{
			printf ("Number of channel unknown!!\n");
		}
	}
	free(buff);
	return myhdr;
}



// Function  to calculate the RMS power for 1-channel-wav files and represent it in dB and BLOCK.
void getRMS1channel(WAVHDR a,int  b,int c, short *d){
	int64_t sum=0;
	for (c=0; c<a.sampleRate/25;++c){
		sum += d[c]* d[c];
	} 
	double db = 20*log10(sqrt(sum/(double)c));
	gotoxy(1,b+5);
	printf(" %.2f dB", db);
	// For loop to represent the power by BLOCK 
	for(c = 0; c< db/3; c++){
		gotoxy(c+12, b+5);
		// Change the color when the power gets stronger. 
		if( c <= 10 )
			setcolor(WHITE, YELLOW);
		else if( c<= 21 )
			setcolor(WHITE, GREEN);
		else
			setcolor(WHITE, RED);
		printf("%s", BLOCK);
		resetcolor();
	} // end for
}//end function


//Function to calculate the RMS power for 2-channel-wav files and represent it in dB and BLOCK
void getRMS2channel(WAVHDR a,int  b,int c, short *d){
	int64_t sum1=0, sum2=0;
	for (c=0; c<a.sampleRate/100;++c){
		sum1 += d[c*2]*d[c*2];
		sum2 += d[c*2+1]*d[c*2+1];
	}
	double db1 = 20*log10(sqrt(sum1/(double)c));
	double db2 = 20*log10(sqrt(sum2/(double)c));

	gotoxy(1,b+5);
	printf(" %.2f dB", db1);
	//For loop to represent the left channel RMS power by BLOCK
	for(c = 0; c< db1/3; c++){
		gotoxy(c+12, b+5);
		// Change the color when the power gets stronger.
		if( c <= 10 )
			setcolor(WHITE, YELLOW);
		else if( c<= 21 )
			setcolor(WHITE, GREEN);
		else
			setcolor(WHITE, RED);
		printf("%s", BLOCK);
		resetcolor();
	}// end for

	//For loop to represent the left channel RMS power by BLOCK
	for(c = 0; c < db2/3 ; c++){
		gotoxy(80-c,b+5);
		// Change the color when the power gets stronger.
		if( 90-c >= 80)
			setcolor(WHITE, YELLOW);
		else if(90-c >=70)
			setcolor(WHITE, GREEN);
		else if( 90 - c < 70)
			setcolor(WHITE, RED);
		printf("%s", BLOCK);
			resetcolor();
	}//end for

	gotoxy(85,b+5);
	printf(" %.2f dB",  db2);
	puts("");
}//end function



