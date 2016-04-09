#ifndef __SOUND_H
#define __SOUND_H

#include <stdint.h>
typedef struct{
	char chunkID[4];   // contains letter "RIFF" in ASCII form
	uint32_t chunkSize;  //The size of the rest of the chunk
	char format[4];  // contains letter "WAVE"
	char subchunk1ID[4];  //contains letter "fmt"
	uint32_t subchunk1Size;  //16 for PCM
	uint16_t audioFormat; // 1 for PCM, other values for compressed format
	uint16_t numChan; // Num channels: 1 for mono, 2 for stereo
	uint32_t sampleRate; //8000, 44100
	uint32_t byteRate; // == sampleRate * numChannels * bitsPerSample /8
	uint16_t blockAlign; //== numChannels * bitsPerSample/8
	uint16_t bitsPerSample; //8 bits = 8, 16 bits = 16, etc
	char  subchunk2ID[4]; // contains letter "data"
	uint32_t subchunk2Size; // (number of bytes in data) == NumSamples * NumChannels * BitsPerSample/8 
}WAVHDR; //to define a new data type


//All function prototypes
WAVHDR readBytesWAV(FILE *); 
void displayheader(WAVHDR);
void getRMS1channel(WAVHDR a, int b, int c, short *d);
void getRMS2channel(WAVHDR a, int b, int c, short *d);

#endif
