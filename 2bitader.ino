// setting the pins
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

void loop() {
  // looping all values for A: 0, 1, 2, 3
  for (int pinA = 0; pinA <= 3; pinA++) {
    for (int pinB = 0; pinB <= 3; pinB++) {
      
      // sending the signals to pins a 
      digitalWrite(pinA0, bitRead(pinA, 0)); 
      digitalWrite(pinA1, bitRead(pinA, 1)); 

      // sending the signals to pins B 
      digitalWrite(pinB0, bitRead(pinB, 0)); 
      digitalWrite(pinB1, bitRead(pinB, 1)); 

      // converting A and B  2's complement decimal values
      int valueA = twosCompValue(pinA); 
      int valueB = twosCompValue(pinB); 
      
      // calculating the sum
      int totalSum = valueA + valueB;

      // printing the equation and the answer
      Serial.print(valueA);
      Serial.print(" + ");
      Serial.print(valueB);
      Serial.print(" = ");
      Serial.println(totalSum);

      delay(4000);
    }
  }
  
  // show cycle complete
  Serial.println("\nDone\n");
  delay(4000);
}

// 2-bit binary to 2's complement decimal
int twosCompValue(int binary2bit) {
  if (binary2bit >= 2) {
    return binary2bit - 4;  // 2 → -2, 3 → -1
  }
  return binary2bit;        // 0 → 0, 1 → 1
}
