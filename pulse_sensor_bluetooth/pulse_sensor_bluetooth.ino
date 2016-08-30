// Import required libraries
#include <aREST.h>

// Sensor and pins variables
int pulsePin = 0;
int blinkPin = 6;

// Create aREST instance
aREST rest = aREST();

// Pulse rate variable
volatile int BPM;

// Exposed pulse rate variable
int measured_bpm;

// Raw signal
volatile int Signal;

// Interval between beats
volatile int IBI = 600;

// Becomes true when the pulse is high
volatile boolean Pulse = false;

// Becomes true when Arduino finds a pulse
volatile boolean QS = false;

void setup(){

  // Start Serial
  Serial.begin(115200);
  
  // Sets up to read Pulse Sensor signal every 2mS
  interruptSetup();
  
  // Give name and ID to device
  rest.set_id("1");
  rest.set_name("pulse_rate_sensor");
  
  // Expose BPM to API
  rest.variable("bpm",&measured_bpm);
  
}

void loop(){
  
  // If heart beat is found
  if (QS == true) {
    
    // Save measurement
    measured_bpm = BPM;
        
    // Reset the Quantified Self flag for next time      
    QS = false;                       
  }


  // Handle REST calls
  rest.handle(Serial);  
  
}
