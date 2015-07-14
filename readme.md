# WaveBot

## What is WaveBot?
The simple answer is comes when asking what is better than having a robot? Having a robot that waves at you! It combines the internet connected nature of the Spark Core, an electric motor, and Lego to create a custom robot. Easily edit the shape/function of the robot by simply swapping out the bricks!


## How do I make a WaveBot?
Simply have the listed materials, follow the steps, and make any additions you want!


## Materials needed?
1. Spark Core
	* A Photon or WiFi shielded Arduinowould also work but will not be covered
	* https://www.particle.io/prototype#hardware
2. An Azure Account
	* WaveBot can be completed entirely on the free teir
	* http://azure.microsoft.com
3. Legos
	* I choose Legos because I felt that most people already have them
		- Other building materials could be used including 3D printing parts
	* 
4. A 3.3V or 5V electric motor and temperature sensor
	* Notice: I used 3.3V for everything however with slight modifications a 5V version can be achieved
5. Wires, resistors, transistor, LEDs, and breadboard
	* 12 wires
	* 3 560 Ohm Resistors
	* 1 10 OhN Resistor
	* 1 p2n2 222A transistor
	* 2 LEDs (Eyes if you want them)
	* Breadboard (The one included with the Spark Core is what I used)


## Helpful stuff
* [Spark Core Docs](http://docs.particle.io/core/)


## Assembly!
### 1) Connect your Spark Core to WiFi
Follow any of the below guides and make sure you have a Spark/Particle account:
	* [Spark Core Docs](http://docs.particle.io/core/start/)
	* [Windows Computer](https://github.com/mspcontent/Spark-Core-Configuration)

### 2) Preform a check of this connection
Complete the [Blink an LED](http://docs.particle.io/core/examples/#blink-an-led) exercise

### 3) Setup your Azure Mobile Service (Backend to recieve temperature data)
Follow Brian Sherwin's guide to do so [here](http://briansherwin.com/blog/2015/04/azuremobileservice-library-published-to-spark-io/).
	* Select the 
	* This allows for easy extensibility in the future
		* Allowing for the expansion to a website which allowed a user to enter a duration for a wave and activite WaveBot remotely

### 4) Build your desired robot
I have included images of my wave bot however feel free to create the robot that fits you!
My bot is escentially a hollow box 8x6x11 (Width x Depth x Height)

<img src="https://github.com/3ygun/WaveBot/blob/master/images/WP_20150518_002.jpg" height="400px" alt="WaveBot front">
<img src="https://github.com/3ygun/WaveBot/blob/master/images/WP_20150518_005.jpg" height="400px" alt="WaveBot moving arm">
<img src="https://github.com/3ygun/WaveBot/blob/master/images/WP_20150518_009.jpg" height="400px" alt="WaveBot other arm">
<img src="https://github.com/3ygun/WaveBot/blob/master/images/WP_20150518_006.jpg" height="400px" alt="WaveBot head">

### 5) Build out your circuit on the breadboard
Here is what mine looks like (Better diagram will to come)

<img src="https://github.com/3ygun/WaveBot/blob/master/images/WP_20150518_008.jpg" height="400px" alt="WaveBot circuit">

### 6) Make the nessasary changes to waveBot.cpp and "Flash" the finished code to the Core
You will need to modify waveBot.cpp to include the necessary Azure stuff. Once you have modified these lines flash the code to the Spark Core and watch your robot wave! 
