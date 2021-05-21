int led = 5; //LED pin number here
int button = 4;
int pot = A0;
int vibSensor = 2;
int buzzer = 9;
int touch;

void setup() 
{
pinMode(led, OUTPUT); //make sure led is set up as output!
pinMode(button, INPUT);
pinMode(pot, INPUT);
pinMode(vibSensor, INPUT);
pinMode(buzzer, OUTPUT);

Serial.begin(9600); //9600 rate at which data is being transferred, this value is pretty standard
}

void loop()
{
int reading = digitalRead(button);
int pot_reading = analogRead(pot);
int brightness = map(pot_reading, 0, 1023, 0, 255); //taking potentiallity and mapping it to our light range, led will change dimness with twist of handle

if(reading == HIGH)
{
analogWrite(led, brightness); //controls led dimming, 0-255
}
else
{
analogWrite(led, 0); //grounding and turning off
}

//TOUCH STUFF
touch = digitalRead(2);
Serial.println(touch);

if(touch == 1)
{
//play buzzer
tone(buzzer, 900);
}
else
{
//don't play buzzer
noTone(buzzer);
}
}
 
