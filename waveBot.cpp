#include "AzureMobileService/AzureMobileService.h"  // Import the required Azure libraries

// Setup the Azure information
#define MYSERVICE "name_of_your_mobile_service"
#define MYKEY "key_of_your_mobile_service"

// Create the local variables and assign the needed pins
AzureMobileService ams; // The Azure Mobile Service (AMS) interaction variable
int tempPin = A0; // Setup the temperature reading pin
int motorPin = A4;  // Setup the motor speed writing pin
int motorSpeed = 0; // Setup the variable that holds current motor speed
int ledEye1 = D0;  // Setup the LED that controls the 1st eye
int ledEye2 = D1;  // Setup the LED that controls the 2nd eye
int led2 = D7; // Setup the LED that serves as a sanity/is it running check


// Finalize setup
void setup() {  
  pinMode(ledEye1, OUTPUT); // Finalize the 1st eye LED
  pinMode(ledEye2, OUTPUT); // Finalize the 2nd eye LED
  pinMode(led2, OUTPUT);  // Finalize the sanity check
  pinMode(motorPin, OUTPUT);  // Finalize the motor control
  // The temperature sensor doesn't require a finalize setup just read from it when needed
  
  ams.configure(MYSERVICE, MYKEY);  // Finalize the AMS details
}
 
// Loop the execute temperature reads and waving actions
void loop() {

  /*
   *  Turn lights on, read temperature, and possibly wave if it's too hot!
   */
  digitalWrite(led2, HIGH); // Turn on the sanity LED
	
	float temperature = getVoltage(tempPin); // Read in the current temperature in voltage form
	temperature = (temperature - .33) * 100; // Convert the temperature from voltage to degrees Celsius
                                           // Remove the 330mV offset and convert
	
	String table = "TemperatureData";  // Gets the appropriate Azure held table the store the temperature data
	char buffer[100];  // Create the buffer string
	snprintf(buffer, sizeof(buffer), "{\"Temperature\":\"%d\"}", &temperature);  // Load the current temperature data into the buffer string
	ams.create(table, buffer); // Add the data to the data to the Azure table 
	
  // Determine if it's hot enough for waveBot to tell you to cool down through a wave
  if (temperature >= 21.1) {  // 21.1 degrees Celsius it 70 degrees Fahrenheit 
    motorSpeed = 210; // Set the arm motors speed
    analogWrite(motorPin, motorSpeed);  // Turn on the motor at the decided speed
    digitalWrite(ledEye1, HIGH);   // Turn ON the LED pins
    digitalWrite(ledEye2, HIGH);   // Turn ON the LED pins
  }

  delay(2500);               // Wait for 2500mS = 2.5 second    
  

  /*
   *  Turn off the lights and motor
   */
  motorSpeed = 0; // Set the motor speed to off
  analogWrite(motorPin, motorSpeed);  // Turn the motor off
  digitalWrite(ledEye1, LOW); // Turn off the 1st eye LED
  digitalWrite(ledEye2, LOW); // Turn off the 2nd eye LED
  digitalWrite(led2, LOW);  // Turn off the sanity LED
  delay(2500);  // Wait for 2.5 second in off mode
}

// Reads in the voltage and converts it to Volts
float getVoltage(int pin) {
	return ((0.0 + analogRead(pin)) * 0.003222656);  // Read in the 0 to 1024 temperature, convert it to between 0 and 3.3V for my sensor, and return the value
}