byte ledPin[] = {2,3,4,5,6,7}; // Cria um array para os pinos dos LEDs
int ledDelay; // intervalo entre as alterações
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 1; // seleciona o pino de entrada para o potenciômetro

void setup() 
{
  for (int x=0; x<10; x++) 
  { 
    pinMode(ledPin[x], OUTPUT);// define todos os pinos como saída
  }
  changeTime = millis();
}

void loop() 
{
  ledDelay = analogRead(potPin); // lê o valor do potenciômetro
  Serial.print(ledDelay);
  if ((millis() - changeTime) > ledDelay)
  { 
    changeLED();// verifica se transcorreram ledDelay ms desde a última alteração
    changeTime = millis();
  }
}
void changeLED()
{
  for (int x=0; x<10; x++) 
  { 
    // apaga todos os LEDs
    delay(50);
    digitalWrite(ledPin[x], LOW);
  }
  digitalWrite(ledPin[currentLED], HIGH); // acende o LED atual
  currentLED += direction; // incrementa de acordo com o valor de direction
  // altera a direção se tivermos atingido o fim
  if (currentLED == 9) 
  {
    direction = -1;
  }
  if (currentLED == 0) 
  {
    direction = 1;
  }
}
