#include <iostream> 
#include <math.h> 
#include "wav.hpp"
#include <fstream>

using namespace std;

int main(){ 

	// UP
	double NPS = 350/60;

	// Ode To Joy
	//double NPS = 140/60;
	
	double SAMPLE_RATE = 41400;
	
	ifstream myfile;
	myfile.open("up.txt");
	//myfile.open("odetojoy.txt");
	int lines=0;
	string t;
	while(getline(myfile, t)){
		lines++;
	}
	double** freqs = new double*[lines]; // each element is a pointer to an array.

	for(int i = 0; i < lines; ++i)
		freqs[i] = new double[2]; // build rows
	int i=0;
	double beats=0;
	myfile.clear();
	myfile.seekg(0, myfile.beg);
	while(getline(myfile, t)){
		freqs[int(floor(i/2))][i%2] =stod(t);
		i++;
		if(i%2==0){beats+=stod(t);}
	}
	int lengthOfList=i/2;
	myfile.close();
	
	
	// freqs = { {init freq, time}}
	
	//NPS = 1.3;
	double LENGTH = beats/NPS;
	
   WavSound sound1; // helper 
   // your code goes here 
   int numOfSamples = LENGTH * SAMPLE_RATE;
   double frequency;
   int* waveform = new int[numOfSamples]; // creates the array 
   // and here 
   double dt = 1/SAMPLE_RATE;
   double v;
   double time;
   double va;
   int count=0;
   int count2=0;
   int lengthOfNote;
   int increaseTime=40;
   for (int j=0; j < lengthOfList; j++){ //Every note
	   count2=0;
	   frequency = freqs[j][0];
	   lengthOfNote = freqs[j][1];
	   for (int t=0; t<lengthOfNote; t++){ // Length of note
		   for (int i=0; i < SAMPLE_RATE/NPS; i++){  //Each number in period
				time = count2*dt;
				if(frequency==0){waveform[count]=0;}
				else{
					if(count2>SAMPLE_RATE/NPS/increaseTime){va = pow(0.9999, count2 -SAMPLE_RATE/NPS/increaseTime);}
					else{va=pow(2,count2/(SAMPLE_RATE/NPS/increaseTime))-1;};
					
					v = 6000*sin(2*M_PI * frequency * time+M_PI/2)*va;
					waveform[count] = v;
				}
				count++;
				count2++;
		   } 
		}
	}
	
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
   sound1.MakeWavFromInt("music.wav",SAMPLE_RATE, waveform, numOfSamples); 
   delete[](waveform); 
   return 0; 
}
