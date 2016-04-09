#voiceDetection
CONTENTS OF THIS FILE
---------------------
   
 * Introduction
 * Requirements
 * Installation
 * Descriptions
 * Troubleshooting
 * FAQ
 * Authors


INTRODUCTION
------------
The software detects sound at the surrounding area by a microphone and then 
displays its power in decibel every one second. 

 * To submit bug reports or feature suggestions, please send me an email: 
   	kamilight94@gmail.com



REQUIREMENTS
------------
This software requires the following things to run :
 * A Raspberry Pi.
 * A terminal emulator applicatior, for example, PuTTY.
 * An USB Audio Device.
 * A microphone.


INSTALLATION
------------
 * If you don't have PuTTY simply download and install with this link: 
	http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html

 * If it's your first time setting up Raspberry Pi, you can see it here: 
	http://www.raspberrypi.org/help/noobs-setup/

 * If it's your first time plug in the USB Audio Device into your Raspberry Pi,
   please follow these instructions: 
   http://computers.tutsplus.com/articles/using-a-usb-audio-device-with-a-raspberry-pi--mac-55876

 * Extract project1.tar file by command: $tar -xvf project1.tar

 * Use make utility to create waveApp file: $make

 * Run the program by entering command: $./waveApp 



DESCRIPTIONS
------------

The project.tar includes these files: 
 * main.c	: includes main();
	          record system command, open sample.wav file 
		  and call function readbytesWAV().

 * sound.h	: define typedef WAVHDR and includes function prototype of wavFunc.c 
		  and waveinfo.c.

 * vtscreen.h	: define COLORS and includes all function prototype of vtscreen.c 

 * vtscreen.c	: includes all functions related to screen display.
	definescroll()	: define the scroll
	restorescroll()	: restore the scroll
	setcolor()	: background and forground color changing
	clearscreen ()	: clear the screen
	gotoxy ()	: move the cursor
	colorstring ()	: text color changing
	resetcolor ()	: reset color fommatting

 * waveinfo.c	: includes displayhearder(); 
		  display wav file infomation: Duration, Channel Number, Sample Rate, Bits/sample.

 * wavFunc.c	: includes readBytesWAV(), getRMS1channel(), getRMS2channel();
	readBytesWAV()	: read the wav file. 
	getRMS1channel(): calculate the RMS power if channel number is 1. 
	getRMS2channel(): calculate the RMS power if channel number is 2. 

 * makefile	: make utility
	using $ make command will create .o files and waveApp.
	using $ make clean command will delete all .o files and waveApp.



TROUBLESHOOTING
---------------
 * If after running the program, the screen displays "Segmentation fault":
	- The reason is because of the microphone, either something's wrong with it 
	or you didn't plug in correctly. 
	- Therefore, the program can't record any sound which prevents it from 
	create the sample.wav file.
	- The program will read an sample.wav which it doesn't have. This leads to 
	this "Segmentation fault"

 * If after running the program, the screen displays the same pattern RMS power: 
	- Same reason as above fault, something's wrong with your microphone.
	- The program can't record a new wav file, it just read and analyse one same
	old file.  


 * If you're running your Raspberry Pi, and then plug in the USB sound card, you will
   need to reboot it so that the USB sound card can be used by this command: 
	 $sudo reboot 


FAQ
---


Q: Why whenever I compile by using make, I have some warning: universal character names
   are only valid in C++ and C99 ? How can I fix it ? 


A: It's fine if you have that warning. Everything is still run normally. This happens 
   simply bacause I used an Unicode Character 'LIGHT SHADE' (u/2591) in the source
   code to represent the power. (BLOCK) 



Q: Why do I have some weird characters after the power number in decibel? 

A: Because I used an Unicode Character to represent the power. If you want to see it 
   correctly, right click mouse at the taskbar of PuTTY. Choose change settings then 
   click Translation, change the Remote character set into UTF-8. 


AUTHORS 
-------

 - Student: Viet Vu 
 - Supervisor: Dr. Gao Chao 
 - Sound Project of Application Development course in Vaasan Ammattikrokeakoulu. 





