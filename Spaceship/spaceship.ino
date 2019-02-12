
char ch = 0 ;
char input;
int value;
int fuel = 100;
int gravity = 5;
double velocity = 1;
double distance = 500;
double newVel;

void setup() {
  Serial.begin(9600);
  Serial.println("Spaceship Game");
  Serial.println("Adapted for Arduino by Matt Horger");
  Serial.println("Original Game by Jeffery Popyack - Drexel University");
  Serial.println("--------------------");
  Serial.println("You have successfully made it to the moon... somehow."); 
  Serial.println("Now, you must make emergency landing in the Schuykill River or else crash into 30th Street Station, risking the lives of thousands of poor SEPTA commuters."); 
  Serial.println("Your goal is to burn the appropriate amount of fuel and land with a velocity of less than 10 m/s so to not cause flooding during impact.");
  Serial.println("--------------------");
  Serial.print("Fuel Remaining: ");
  Serial.println(fuel);
  Serial.print("Velocity : ");
  Serial.print(velocity);
  Serial.println(" m/s");
  Serial.print("Distance Remaining : ");
  Serial.print(distance);
  Serial.println(" meters");
  Serial.println("--------------------");
  Serial.println("Fuel Control");
  Serial.println("--------------------");
  Serial.println("1. Burn 0 Fuel");
  Serial.println("2. Burn 10 Fuel");
  Serial.println("3. Burn 20 Fuel");
  Serial.println("4. Burn 50 Fuel");
  Serial.println("5. Burn all Fuel");
  Serial.println("--------------------");
  Serial.println("Type the number and press enter");
}

void loop() {
 if(Serial.available()){
        input = Serial.read();
        value = atoi(input);
        if(input == '1'){
          burn(0, fuel, velocity, distance);
        } else if(input == '2'){
          burn(10, fuel, velocity, distance);
        } else if(input == '3'){
          burn(20, fuel, velocity, distance);
        } else if(input == '4'){
          burn(50, fuel, velocity, distance);
        } else if(input == '5'){
          burn(fuel, fuel, velocity, distance);
        } else {
          Serial.println("Invalid Number Code");
        }
 }
}
   

void burn(int consumption, int& fuel, double& velocity, double& distance){
  Serial.println("Initializing burn");
  if(consumption > fuel) {
    consumption = fuel;
    Serial.println("Warning, do not have that much fuel");
  }
  double newVel = (velocity + gravity) - consumption;
  distance -= ((velocity + newVel) / 2);
  velocity = newVel;
  fuel = (fuel - consumption);
    // check winning conditions
    if(distance <= 0) {
        if(velocity >= 10.0){
            Serial.println("Oh no! You have crashed into 30th Street Station. Oh the humanity!!");
            Serial.println("Game Over");
            delay(9000);          
        } else {
            Serial.println("Yay! You successfully landed safely in the river. Cheesesteaks for everyone!!");
            Serial.println("Game Over");
            delay(9000);
        }
    }
  Serial.println("--------------------");
  Serial.print("Fuel Remaining: ");
  Serial.println(fuel);
  Serial.print("Velocity : ");
  Serial.print(velocity);
  Serial.println(" m/s");
  Serial.print("Distance Remaining : ");
  Serial.print(distance);
  Serial.println(" meters");
  Serial.println("--------------------");
    
}
