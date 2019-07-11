/**
 * Traffic lights

 * File: traffic_lights.ino
 * Author: Richard Kneale
 * Date created: 26th December 2015
 * Date modified: 13th April 2018
 * Description: An Arduino traffic light system

 * Parts:
 * 2 x green LEDs
 * 2 x red LEDs
 * amber LED
 * blue LED
 * pushbutton
 * 10 kilohm resistor
 * 6 x 220 ohm resistors

 * States:
 * green light and red walking man on
 * green light, red walking man and blue button indicator on
 * amber light, red walking man and blue button indicator on
 * red light, red walking man and blue button indicator on
 * red light and green walking man on
 * red light, amber light and red walking man on
 */

/**
 * Create a global variable to hold the state of the switch
 * This variable is persistent throughout the program
 * Whenever you refer to switchState you are talking about the number it holds
 */

int switchstate = 0;

void setup() {
    // Declare the LED pins as outputs
    pinMode(3, OUTPUT); // red man
    pinMode(4, OUTPUT); // green man
    pinMode(5, OUTPUT); // green traffic light
    pinMode(6, OUTPUT); // amber traffic light
    pinMode(7, OUTPUT); // red traffic light
    pinMode(8, OUTPUT); // blue button indicator

    // Declare the switch pin as an input
    pinMode(2, INPUT); // switch
}

void loop() {
    // Read the value of the switch
    // digitalRead() checks to see if there is voltage on the pin or not
    switchstate = digitalRead(2);

    // If the switch is LOW (the button is not pressed)
    if(switchstate == LOW) {
        // Turn the green light and red walking man on
        digitalWrite(8, LOW); // turn the blue button indicator off
        digitalWrite(7, LOW); // turn the red traffic light off
        digitalWrite(6, LOW); // turn the amber traffic light off
        digitalWrite(5, HIGH); // turn the green traffic light on
        digitalWrite(4, LOW); // turn the green walking man off
        digitalWrite(3, HIGH); // turn the red walking man on
    }

    // If the switch is not LOW (the button is pressed)
    else {
        buttonPressed();
    }
}

// Called when the switch is pressed
void buttonPressed() {
    // Turn the green light, blue indicator light and red walking man on
    digitalWrite(8, HIGH); // turn the blue button indicator off
    digitalWrite(7, LOW); // turn the red traffic light off
    digitalWrite(6, LOW); // turn the amber traffic light off
    digitalWrite(5, HIGH); // turn the green traffic light on
    digitalWrite(4, LOW); // turn the green walking man off
    digitalWrite(3, HIGH); // turn the red walking man on

    // Wait five seconds before changing the lights
    delay(5000);

    // Carry out the light changing sequence
    lightSequence();
}

// Replicates the sequence used by traffic lights
void lightSequence() {
    // Turn the amber light, red walking man and blue button indicator on
    digitalWrite(8, HIGH); // turn the blue button indicator on
    digitalWrite(7, LOW); // turn the red traffic light off
    digitalWrite(6, HIGH); // turn the amber traffic light on
    digitalWrite(5, LOW); // turn the green traffic light off
    digitalWrite(4, LOW); // turn the green walking man off
    digitalWrite(3, HIGH); // turn the red walking man on

    // Wait three seconds before changing the lights
    delay(3000);

    // Turn the red light, red walking man and blue button indicator on
    digitalWrite(8, HIGH); // turn the blue button indicator on
    digitalWrite(7, HIGH); // turn the red LED on
    digitalWrite(6, LOW); // turn the amber LED off
    digitalWrite(5, LOW); // turn the green LED off
    digitalWrite(4, LOW); // turn the green walking man off
    digitalWrite(3, HIGH); // turn the red walking man on

    // Wait five seconds before changing the lights
    delay(5000);

    // Turn the red light and green walking man on
    digitalWrite(8, LOW); // turn the blue button indicator off
    digitalWrite(7, HIGH); // turn the red LED on
    digitalWrite(6, LOW); // turn the amber LED off
    digitalWrite(5, LOW); // turn the green LED off
    digitalWrite(4, HIGH); // turn the green walking man on
    digitalWrite(3, LOW); // turn the red walking man off

    // Wait five seconds before changing the lights
    delay(5000);

    // Turn the red light, amber light and red walking man on
    digitalWrite(8, LOW); // turn the blue button indicator off
    digitalWrite(7, HIGH); // turn the red traffic light on
    digitalWrite(6, HIGH); // turn the amber traffic light on
    digitalWrite(5, LOW); // turn the green traffic light off
    digitalWrite(4, LOW); // turn the green walking man off
    digitalWrite(3, HIGH); // turn the red walking man on

    // Wait two seconds before turning the green light and red walking man on
    delay(2000);
}
