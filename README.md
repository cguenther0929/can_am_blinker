# Can-am Blinker Controller (STM32) 
The source contained within this repository is intended for the Can-am Blinker Controller.  

## Architecture
Bare metal -- application written in C.       

## Dependencies
* STM32Cube IDE: v1.16.0
   

## Tagged Versions 
* v0.0.1 -- Compiles. The health LED will blink.  There is no CLI interface due to compilation errors.  

* v0.0.2 -- Some files didn't appear to be properly tracked.  Compiles. The health LED will blink.  There is no CLI interface due to compilation errors.

* v0.0.3 -- CLI stuff was added back in and the solution compiles.  To obviate compilation errors,console functions were added to uart files (pulled from console files).

* v0.0.4 -- A good amount of blinker logic has been added in and the source compiles.  
