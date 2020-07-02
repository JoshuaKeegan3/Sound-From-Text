#include <iostream> 
#include <math.h> 
#include "wav.hpp" 
 
using namespace std; 

double LENGTH = 60;
double SAMPLE_RATE = 41400;
 
int main(){ 
   WavSound sound1; // helper 
   // your code goes here
   int numOfSamples = LENGTH * SAMPLE_RATE;
   double frequency = 2000;
   int* waveform = new int[numOfSamples]; // creates the array 
   // and here 
   double dt = 1/SAMPLE_RATE;
   double v;
   double vt;
   double ft;
   for (int i=0; i < numOfSamples; i++){  
		double time = i*dt;
		ft = 200 * sin(4*M_PI * time);
		v = 5000*sin(2*M_PI * frequency * time + ft);
		waveform[i] = v;
   } 
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
   sound1.MakeWavFromInt("siren.wav",SAMPLE_RATE, waveform, numOfSamples); 
   delete[](waveform); 
   return 0; 
} 

