/*
PROJETO:______SENSOR COM INTERRUPÇÃO PARA INDICAR QUAL BOTÃO FOI PRESSIONADO PRIMEIRO
MCU:__________ARDUINO UNO
VERSÃO IDE:___1.8.5 
AUTOR:________ISAAC GONDIM GERALDO

REFERENCIA: https://www.arduino.cc/reference/pt/language/functions/external-interrupts/attachinterrupt/
*/

volatile byte state = LOW;
// DECLARAÇÃO DE FUNÇÕES ==============================================================================================================================================

void blink();

void setup() 
{
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blinkdireita, LOW);
  attachInterrupt(digitalPinToInterrupt(3), blinkesquerda, LOW);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() 
{
  
}
// FUNÇÕES AUXILIARES =================================================================================================================================================

void blinkdireita()
{
  digitalWrite(4, HIGH);
  int cont;
  for(cont=0;cont<500;cont++)
  {
    delayMicroseconds(10000);
  }
  digitalWrite(4, LOW);
}


void blinkesquerda() 
{
  digitalWrite(5, HIGH);
  int cont;
  for(cont=0;cont<500;cont++)
  {
    delayMicroseconds(10000);
  }
  digitalWrite(5, LOW);
}
