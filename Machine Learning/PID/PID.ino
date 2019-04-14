double learning[100]; // learning is an array of 100 integers
const int inPin = 1;  // A0 is where you connect the sensor
float previous;
void setup()
{
  Serial.begin(9600);
  previous = 0;
}

void loop()
{
  int value = analogRead(inPin); // read the value from the sensor
  float millivolts = (value / 1024.0) * 5000; 
  float celsius = millivolts / 10;
  float reading = ((celsius * 9)/5 + 32); //turning the celsius into fahrehait
  Serial.println(reading);
  if(reading - previous > 0){
    Serial.println("Shift in Data");
    Serial.print(reading);
    Serial.print(" - ");
    Serial.print(previous);
    Serial.println("Pushing to array");
    int arrayIndex = sizeof(learning);
    Serial.println("Array Size: ");
    Serial.print(arrayIndex);
    if(arrayIndex == 100){ // our array is filled, exit out
     for(int i = 0; i < 100; i++){
      Serial.println(learning[i]);
     }
      exit(0);
    }
    learning[arrayIndex] = reading - previous;    
  }
  delay(1000);
  previous = reading;
}
