
const int inPin = 1;  // A1 is where you connect the sensor

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(inPin); // read the value from the sensor
  Serial.println(value);
  delay(1000);
}
