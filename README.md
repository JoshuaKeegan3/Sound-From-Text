# Sound-From-Text


### Sampling rate
The sampling rate of 41400 hz is industry standard because it is twice the frequency the human ear can theoretically hear (well just over). This means that every frequency that can be heard can be represented. If sampling rate is less than the highest hearable frequency, notes could be completely skipped over. If the sample rate is between the highest hearable frequency and 2 times the highest hearable frequency, the program could still skip important information. For example if the sample rate is = to the highest hearable frequency, the same point on the wave would be sampled every time. This would lead to a flat line or no sound. This missed information can lead to sharp changes in sound or different notes to no sound as in the previous example. The frequency is 2 times so no information is missed because there is sampling twice a wave length. This means that both a positive and negative gradient of the wave is measured and that either a trough or a peak occurred in-between points. It is possible to extrapolate from this to create a wave form. The extra 1400 added to 20,000*2 means that we are guaranteed to not get two values where the gradient is 0 in each wavelength creating a potential straight line (at y=0).
### Total Samples
The total number of samples is the length of the program(s)*sample rate(s^-1). This works because it is _ samples per second over _ seconds. 
### Variable types
I just made everything doubles ay. It was lazy however everything that I was preforming an operation with, I just made a double this while taking up more space in memory was an easy way of making sure that I got no errors when preforming operations. This was a hack and I would be more thoughtful next time. This meant that everything was a double except for the number of samples which was an integer. By errors in calculations I mean losing decimal places due to the result being considered an integer after multiplying by an integer.

### Alternative method

Count the samples and every 41400 samples in other words every 1 second change the frequency variable to something different. To do this I would do count_var mod 41400

### Attack, Sustain, Decay and Release parameters.

I made a piano sound. Piano has a large attack, no sustain, a long decay and no release. For this reason I used an exponential decay algorithm. This started with a high value meaning that my attack was instant then decreased quickly at first and then slower over time. Upon playing the next note the sound for the current note simple stops because there is no release. I made it an instant attack because through testing I couldn’t notice a difference of a sharp attack and an instant attack. I did however notice that there were more artefacts and clipping when I was using a sharp attack.
