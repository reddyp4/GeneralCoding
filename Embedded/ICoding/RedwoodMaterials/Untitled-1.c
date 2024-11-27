/* 
How to develop:
These are a few things that have worked for me to make this less of a problem.

1 Use anything to physically identify what, how, who and when the controller was 
programmed. Post-it notes, tape and a marker, paint pens, and printed labels all 
work well. This is good because it works even when the controller does not have 
power. However, a team needs to be trained not to reprogram without updating the tags. 

2 If there are LED's on the board, establish a flash pattern to indicate what is 
running on the board. For example 1 to 10 quick flashes for a number followed by a 
long wait can be used to spell out a reference number in a few seconds. This can 
be something done at reset or repeated while operating. Either way it provides a 
quick way to ensure the right software is running.

3 If there is a serial data bus on the board, have a message that is transmitted 
identifying the software build. This message can be repeatedly broadcast or sent 
in response to a query. The message can be updated at compile time using compiler 
macros like __FILE__, __DATE__, & __TIME__ [1][2][3]. 

4 If there is not a spare LED or a serial data bus, a spare digital output can 
be programmed to output a sequence of pulses that identify a software version. 
Then if this is done consistently across development, integrators can use an 
oscilloscope to determine which software is running. Things like frequency and 
duty cycle can provide a unique value that is decoded with a modern scope. 
More complex waveforms are also possible. 

5 Since software often gets tweaked (changed) in development, its also handy 
to have a ROM (EEPROM) checksum [4] available. This value can be made available 
through a flashing LED, a serial data bus, or a signal line. Verifying a checksum 
detects if the wrong software is running even if other indicators say otherwise. 

6 If the software drives something visual like a display, gauge, relay, or 
safe mechanical movement, then a wake-up 'WOW' mode [5] can be made unique to 
each version of software making it possible to determine what is running on a 
controller. 

Any other methods I'm missing?

*/