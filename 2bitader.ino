// Setting the pins (kept exactly the same)
const int pinA0 = 2; // A bit 0 (LSB) - Positive Side
const int pinA1 = 3; // A bit 1 (MSB) - Positive Side
const int pinB0 = 4; // B bit 0 (LSB) - Negative Side
const int pinB1 = 5; // B bit 1 (MSB / Sign Bit) - Negative Side

void setup() {
  pinMode(pinA0, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinB0, OUTPUT);
  pinMode(pinB1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Loop through positive values for A: 0, 1, 2, 3
  for (int binA = 0; binA <= 3; binA++) {
    
    // Loop ONLY through negative values for B: 2 (which is -2) and 3 (which is -1)
    for (int binB = 2; binB <= 3; binB++) {
      
      // Pins A 
      digitalWrite(pinA0, bitRead(binA, 0)); 
      digitalWrite(pinA1, bitRead(binA, 1)); 

      // Pins B 
      digitalWrite(pinB0, bitRead(binB, 0)); 
      digitalWrite(pinB1, bitRead(binB, 1)); 

      // A is purely positive (0 to 3)
      int valueA = binA; 
      
      // B is 2's complement negative (-2 or -1)
      int valueB = binB - 4; 
      
      // Calculate the true mathematical sum
      int totalSum = valueA + valueB;

      // Print the math equation
      Serial.print(valueA);
      Serial.print(" + ");
      Serial.print(valueB);
      Serial.print(" = ");
      Serial.println(totalSum);

      delay(4000);
    }
  }
  
  // Show cycle complete
  Serial.println("\nDone\n");
  delay(4000); 
}