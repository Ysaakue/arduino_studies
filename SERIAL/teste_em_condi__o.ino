
#include <SoftwareSerial.h>

//Porta do Arduino onde o pino RX do Módulo GSM esta conectado
#define TX_PIN 10
 
//Porta do Arduino onde o pino TX do Módulo GSM esta conectado
#define RX_PIN 11
 
//Cria comunicacao serial via software nas portas digitais definidas acima
SoftwareSerial serialGSM(RX_PIN, TX_PIN);


void setup() 
{
  //Begin serial comunication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  while(!Serial);
   
  //Inicia comunicacao serial com o GSM
  serialGSM.listen();
  serialGSM.begin(9600);
  delay(1000);
  
  Serial.println("Setup Completo!");
}

//========================================================================================================================================================================================================

void loop() 
{    
  if(Serial.available())//Le as mensagens vindas do GSM para escrevê-las no monitor serial
  {
    char texto[20];
    String message;
    String confir="oi";
    
    message =Serial.readStringUntil("\r");//Define a menssagem com os dados vindos do GPRS
    Serial.println(message);
    sprintf(texto,"%s",message);
    serialGSM.write(texto);



    if(message.equals(confir))
    {
      Serial.println("certo");
    }
  }

  
  if(serialGSM.available())//Le as mensagens vindas do GSM para escrevê-las no monitor serial
  {
    char message;
    message =serialGSM.read();//Define a menssagem com os dados vindos do GPRS
    Serial.write(message);//O monitor lê essa menssagem e imprime na tela
    if(message == "OK")
    {
      Serial.println("certo");
    }
  }
}
