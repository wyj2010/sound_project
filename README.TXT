# ----------------------------------- SOUND SENSOR PROJECT -----------------------------------

This project is meant to collect sound level at a proximity of a Raspberry Pi
device. The RPi is equipped with a USB sound card (C-Media Electronics, Inc. Audio Adapter)
and a microphone. The sound is recorded at 16000Hz sample rate and every second will produce
80 pieces of RMS value as a bar-diagram. In the sound file, 8 pieces of data will be printed
out by a .php file to a .txt file.

Table of Content
1. Configuration
	1.1. Raspberry Pi 3 (Model B) 1GB RAM
	1.2. 16GB SD Card pre-installed with NOOBS for Raspberry Pi
	1.3. Straight-through RJ45 cable
	1.4. USB Sound Card (C-Media Electronics, Inc. Audio Adapter)
	1.5. Microphone
	1.6. Power cable
	1.7. HDMI cable for first setting
2. Installation
	2.1. Insert the SD card to the Pi, plug in the RJ45 cable then the power cable
	2.2. Initialize the RPi, change the default display setting and network
	2.3. Make sure you will receive an email with an IP address by the RPi
	2.4. Setup the USB Sound Card as default (fix the bug of arecord if necessary)
	2.5. Plug in the microphone
3. Operation
	3.1. Open a terminal screen (PuTTY) and type in the IP address, log in as "pi"
	3.2. Go to the folder "appdev" with the command "cd appdev" and list all the file in the
		 folder "ls"
	3.3. Type in the command "make" to compile all the source codes
	3.4. Run the sound.a file by typing the command "./sound.a"
	3.5. With the microphone already plugged in, you can clap/snap your finger/make any sound
		 and see the bar-diagram changes on the terminal screen. The duration of recording is
		 1 second. The program will calculate the rms value for every 200 samples of data for
		 a total of 80 values. In the meantime, 8 pieces of data will be saved to file
		 sound_log.txt
	3.6. Stop recording by pressing Ctrl+C
4. Manifest (list of files and short description of their roles)
	a. main.c
		The root file which contains all the functions of other *.c files.
	b. sound.c (included header files sound.h and comm.h)
		Display the information from the header file and the bar-diagram of the recorded file.
	c. screen.c (included header files screen.h and comm.h)
		For displaying the bar-diagram.
	d. comm.c (included header file comm.h)
		Send the data to the school server.
	e. makefile
		Compile all the source codes.
	f. sound.php
		Store to the server to process the data received and display to the user
5. License
	Raspberry Pi Foundation UK Registered Charity 1129409
	Transcend Information Inc.
	Source codes Copyright by Chau Nguyen, assisted by Dr. Gao Chao
6. Contact information
	Chau Nguyen,
	Department of Information Technology
	Vaasa University of Applied Sciences
	Wolffintie 30, Vaasa, Finland
	Home: http://www.cc.puv.fi/~e1700688
	Email: e1700688(at)edu.vamk.fi
