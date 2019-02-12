// DUCSTeach Arduino Traffic Light
// Code Written by: Matthew Horger
// Drexel University - 2018



void setup() {
  // put your setup code here, to run once:
  
  pinMode(2, OUTPUT); // 2 is red
  pinMode(3, OUTPUT); // 3 is yellow
  pinMode(4, OUTPUT); // 4 is green

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(2, HIGH); // turn on red by default - don't want traffic moving freely
  delay(4000); // show red for 4 seconds to allow traffic from the other side to pass through
  digitalWrite(2, LOW); // turn off red
  digitalWrite(4, HIGH); // turn on green
  delay(4000); // leave green on for the same time as red for equal flow of traffic
  digitalWrite(4, LOW); //turn off green
  digitalWrite(3, HIGH); //turn on yellow
  delay(2000); // we only want yellow on for 2 seconds to let traffic finishing flowing
  digitalWrite(3, LOW); // turn off yellow and loop back to begining of program (void loop)
  
}
