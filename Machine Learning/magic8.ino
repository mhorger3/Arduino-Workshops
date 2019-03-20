
  String phrases = {"Ask again later",
     "It is certain", 
     "Without a doubt",
     "Yes - definitely",
     "As I see it, yes",
     "Most likely",
     "Outlook good",
     "Yes",
     "My reply is no",
     "Very doubtful",
     "No", "Not a chance",
     "No way",
     "Absolutely not",
     "I doubt it",
     "Ask again",
     "I'm uncertain"
    };
    String output;
    int numberofPhrases = 17;
    const int buttonPin = 2;
    int buttonState = 0;
    
    void setup() {
       randomSeed(analogRead(5));
    }
        
    void loop() {
        buttonState = digitalRead(buttonPin);
        if(buttonState == HIGH) {
            output = phrases[random(numberofphrases)];
            Serial.println(output);
            delay(400);
        }
    }
