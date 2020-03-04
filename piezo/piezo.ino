float sinVal;
int toneVal;
void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int x=0; x<180; x++) {
// converte graus para radianos, e depois obtém o valor do seno
sinVal = (sin(x*(3.1416/180)));
// gera uma frequência a partir do valor do seno
toneVal = 2000+(int(sinVal*1000));
tone(2, toneVal);
delay(2);
}
}
