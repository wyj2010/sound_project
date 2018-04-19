//#define DEBUG
//constant definition
#define SAMPLERATE 16000
#define ESC 0x1b
//header file for processing sound (WAV) file
//define the WAV header
typedef struct {
	char chunkID[4];	//"RIFF"
	unsigned int chunkSize;	//4 bytes
	char format[4];	//"WAVE"
	char subchunk1ID[4];	//"fmt "
	unsigned int subchunk1Size;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	char subchunk2ID[4];	//"data"
	unsigned int subchunk2Size;
}WAVHeader;
//function prototypes
void displayWAVheader(char filename[]);
void printID(char []);
void displayBar(char filename[]);
