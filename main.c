#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "sound.h"

int main(void){
	int ret;
	while(1){
		//record 1sec of sound into test.wav
		ret = system("arecord -q -r16000 -c1 -f S16_LE -d1 test.wav");
		if(WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT)) break;
		//open the .wav file and read samples
		displayWAVheader("test.wav");
		//display necessary information (duration, header, etc.)
		//calculate fast dBs
		displayBar("test.wav");
		//send fast dBs to web (php program on www.cc.puv.fi)
		//break;	//for testing, just run the loop once
	}
}
