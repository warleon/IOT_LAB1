// C++ code
//

int red = 11;
int blue = 10;
int green = 9;
int yellow = 8;
int button = 7;

int count = 3;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);

  pinMode(button, INPUT);

//  digitalWrite(red, HIGH);
//  digitalWrite(blue, HIGH);
//  digitalWrite(green, HIGH);
//  digitalWrite(yellow, HIGH);

}

void loop()
{
  int pressed = digitalRead(button);
  digitalWrite(LED_BUILTIN, pressed);
  if(!pressed)
    count = (count + 1)%4;
  else
    count = (count + 3)%4;

  
  int state = 1 << count;
    
  digitalWrite(red, state & 0x1);
  digitalWrite(blue, state & 0x2);
  digitalWrite(green, state & 0x4);
  digitalWrite(yellow, state & 0x8);
  
  delay(500);

}