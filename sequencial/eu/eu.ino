byte leds[] = {2,3,4,5,6,7};
int sentido =1;
int delai = 1000;
void setup() {
  // put your setup code here, to run once:
pinMode(leds,OUTPUT);
}

void loop()
{int x;
  for{x=0;x<7;x+sentido}
  {
      digitalWrite(leds[x],HIGH);
      delay(delai);
      digitalWrite(leds[x],LOW);
      delay(delai);
      if (x==0);
        {
        sentido=1;
        }
      if (x==5);
        {
          sentido = -1;
        }
  }
}
