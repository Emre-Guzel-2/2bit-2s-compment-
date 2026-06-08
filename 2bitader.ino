// S=setting the pins
const int pinA0 = 2;  
const int pinA1 = 3;  
const int pinB0 = 4;  
const int pinB1 = 5;  

void setup() {
  pinMode(pinA0, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinB0, OUTPUT);
  pinMode(pinB1, OUTPUT);

  Serial.begin(9600);
}

//  2-bit binary to 2's complement decimal
int twosCompValue(int binary2bit) {
  if (binary2bit >= 2) {
    return binary2bit - 4;  // 2 → -2, 3 → -1
  }
  return binary2bit;        // 0 → 0, 1 → 1
}

void loop() {
  // Lop  ALL values for A: 0, 1, 2, 3 (Decimal: 0, +1, -2, -1)
  for (int binA = 0; binA <= 3; binA++) {
    
    // Loop through ALL values for B: 0, 1, 2, 3 (Decimal: 0, +1, -2, -1)
    for (int binB = 0; binB <= 3; binB++) {
      
      // Send signals to Pins A 
      digitalWrite(pinA0, bitRead(binA, 0)); 
      digitalWrite(pinA1, bitRead(binA, 1)); 

      // Send signals to Pins B 
      digitalWrite(pinB0, bitRead(binB, 0)); 
      digitalWrite(pinB1, bitRead(binB, 1)); 

      // Convert A and B to their 2's complement decimal values
      int valueA = twosCompValue(binA); 
      int valueB = twosCompValue(binB); 
      
      // Calculate the straight mathematical sum
      int totalSum = valueA + valueB;

      // Print just the equation and the answer
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
