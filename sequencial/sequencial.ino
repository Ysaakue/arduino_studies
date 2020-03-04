// Projeto 5 – Efeito de iluminação sequencial com LEDs
byte ledPin[] = {2,3,4,5,6,7}; // cria um array para os pinos dos LEDs
int ledDelay(65); // intervalo entre as alterações
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
void setup() {
  // put your setup code here, to run once:
for (int x=0; x<10; x++) { // define todos os pinos como saída
pinMode(ledPin[x], OUTPUT); }
changeTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
if ((millis() - changeTime) > ledDelay) { // verifica se já transcorreram ledDelay ms desde

// a última alteração

changeLED();
changeTime = millis();
}
}
void changeLED() {
for (int x=0; x<10; x++) { // apaga todos os LEDs
digitalWrite(ledPin[x], LOW);
}
digitalWrite(ledPin[currentLED], HIGH); // acende o LED atual
currentLED += direction; // incrementa de acordo com o valor de direction
// altera a direção se tivermos atingido o fim
if (currentLED == 9) {direction = -1;}
if (currentLED == 0) {direction = 1;}
}
