# tiny_hal -> Switch 'em all  

It's a quick and dirty program to check if I correctly soldered the QFN package on homemade PCBs.  

Sets up all the pins as push-pull output 10MHz (except PD1|SWIO).  
They're toggled every 500ms, slow enough to catch weird comportement.  

I advise to use an oscilloscope to check as you might get the right value on a multimeter but funky stuff on the scope.  

List of stuff you should **not** have:  
 - Ringing  
 - Overshoot/Undershoot  
 - Low state above 0V  
 - High state below VCC  
 - State not switching  

All of these indicate **bad connection** to the chip.  

In my case it was coming from low quality new flux from ali. I'll keep using the mysterious russian flux I got years ago on ebay.  
*Btw it's only mysterious because I cannot read cyrillic. It's F5 flux, a formulation without rosin:*  
`Composition: diethylamine hydrochloride, isopropyl alcohol, glycerin`  
