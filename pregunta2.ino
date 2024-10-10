// C++ code
//
int car_red =10;
int car_yellow =9;
int car_green =8;

int human_red =7;
int human_green =6;

int count=0;


void setup()
{
  //pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(car_red, OUTPUT);
  pinMode(car_yellow, OUTPUT);
  pinMode(car_green, OUTPUT);

  pinMode(human_red, OUTPUT);
  pinMode(human_green, OUTPUT);

}

void loop()
{
  count = (count+1) % 17;
  
  digitalWrite(car_red, count<17 && count >=7);
  digitalWrite(car_yellow, count<7 && count >=2);
  digitalWrite(car_green, count<2);

  digitalWrite(human_green, count<17 && count >=7);
  digitalWrite(human_red, count<7);

  
  delay(1000); // Wait for 1000 millisecond(s)
}