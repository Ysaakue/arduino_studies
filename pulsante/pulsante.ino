// Projeto 7 – Lâmpada pulsante
int ledPin = 6;
float sinVal;
int ledVal;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int x=0; x<180; x++) {
// converte graus para radianos e, então, obtém o valor do seno
sinVal = (sin(x*(3.1416/180)));
ledVal = int(sinVal*255);
analogWrite(ledPin, ledVal);
delay(25);
}
}
