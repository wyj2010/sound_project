#include "sound.h"
#include "comm.h"
#include <stdio.h>
#include <math.h>

/*
	Function definition of displayWAVheader()
	This function prints out all the information of the recorded .wav file.
	Input argument:
		char filename[]: the name of the file
	Return argument: none
*/
void displayWAVheader(char filename[]){
	WAVHeader myhdr;	//an instance of defined struct
	FILE *fp;
	fp = fopen(filename, "r");	//open a file for reading
	if(fp == NULL){		//if fopen is failed
		printf("ERROR of opening file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fclose(fp);
	printID(myhdr.chunkID);
	printf("Chunk size: %d\n", myhdr.chunkSize);
	printID(myhdr.format);
	printID(myhdr.subchunk1ID);
	printf("Subchunk 1 size: %d\n", myhdr.subchunk1Size);
	printf("Audio format: %d\n", myhdr.audioFormat);
	printf("Number of channels: %d\n", myhdr.numChannels);
	printf("Sample rate: %d\n", myhdr.sampleRate);
	printf("Byte rate: %d\n", myhdr.byteRate);
	printf("Block align: %d\n", myhdr.blockAlign);
	printf("Bits per sample: %d\n", myhdr.bitsPerSample);
	printID(myhdr.subchunk2ID);
	printf("Sub chunk 2 size: %d\n", myhdr.subchunk2Size);
}
/*
	Function definition of printID()
	This function prints out a string of ID for the displayWAVheader().
	Input argument:
		char id[]: four characters in string format
	Return argument: none
*/
void printID(char id[]){
	int i;
	for(i=0; i<4; i++){
		printf("%c", id[i]);
	}
	printf("\n");
}
/*
	Function definition of displayBar()
	This function opens "test.wav" and read the data part of the file. The sample
	should be in S16_LE format, and there are 16k of them. The function processes
	every 200 samples and calculate their RMS values and render the value as a bar.
	Input argument:
		char filename[]: the name of the file for the bar graph
	Return argument: none
*/
void displayBar(char filename[]){
	int i, j;
	FILE *fp;
	short int samples[SAMPLERATE];
	double sum_200, rms_80[80], dB;
	WAVHeader myhdr;	//dummy header to skip over the reading from the file
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("ERROR opening the file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
 	fread(&samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	//all the samples of 1sec are read to the array samples[], we need to run a loop 80 times for 80 bars
	//this loop will calculate a RMS value of 200 samples
	clearScreen();
	for(i=0; i<80; i++){
		for(j=0, sum_200=0.0; j<200; j++){
			sum_200 += samples[j+i*200]*samples[j+i*200];
		}
		rms_80[i] = sqrt(sum_200/200);
		dB = 20*log10(rms_80[i]);
#ifdef DEBUG	//if the header file has a DEBUG defined, the program will run in debug mode
		printf("RMS[%d] = %10.4f = %10.4fdB\n", i, rms_80[i], dB);
#else			//if not then the program prints out the bar graph
		bar(i, dB);
#endif
	}	//end of for
	//write information at the top of the terminal screen
	gotoxy(0,0);
	printf("%c[1;%dm",ESC, 37);
	fflush(stdout);
	//name of the file in white color
	printf("%s	", filename);
	printf("%c[1;%dm",ESC, 32);
	fflush(stdout);
	//channel number in green color
	printf("Channel = %dHz	", myhdr.numChannels);
	printf("%c[1;%dm",ESC, 36);
	fflush(stdout);
	//sample rate in cyan color
	printf("Sample Rate = %d	", myhdr.sampleRate);
	printf("%c[1;%dm",ESC, 35);
	fflush(stdout);
	//duration of the .wav file in magenta color
	printf("Duration = %ds\n", myhdr.subchunk2Size/(myhdr.sampleRate*myhdr.bitsPerSample/8));
	printf("%c[1;%dm",ESC, 37);
	fflush(stdout);
#ifdef COMM
	sendToServer(rms_80);
#endif
}	//end of function
