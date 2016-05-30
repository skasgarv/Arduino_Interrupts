long start = 0;

volatile long lastButtonPush = 0;

void setup()
{
  //start the serial
  Serial.begin(9600);
  
  //LED output
  pinMode(13,OUTPUT);
  //switch input
  pinMode(2,INPUT);
  
  //set the pull-up on the switch
  digitalWrite(2,HIGH);
  
  //seed the random number generator
  randomSeed(millis());
  
  //wait random time from 1 to 3 seconds
  delay(random(1000,3000));
  
  //turn the light on
  digitalWrite(13,HIGH);
  
  //attach the interrupt
  attachInterrupt(0,react,FALLING);  
  
  //get the start time
  start = millis();
}

void loop()
{
}

void react()
{
  long fin = millis();
  
  if(fin - lastButtonPush > 500)
  {  
    Serial.print("Your reaction time: ");
    Serial.println(fin - start);
  }
  
  lastButtonPush = fin;
}
