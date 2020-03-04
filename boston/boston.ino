//INCLUSÃO DE BIBLIOTECAS
#include <LiquidCrystal.h>                                                              
#include <SoftwareSerial.h>                                                                 
#include <Keypad.h>
#include <math.h>

//DECLARAÇÃO DE CONSTANTES
#define TX_PIN 10                                                                           //Porta do Arduino onde o pino RX do Módulo GSM esta conectado
#define RX_PIN 11                                                                           //Porta do Arduino onde o pino TX do Módulo GSM esta conectado
 

LiquidCrystal lcd (A0,A1,A2,A3,A4,A5);                                                     //Define os pinos que serão utilizados para ligação ao display

//declaração ed variaveis globais
unsigned long int bin,dec;
String oper;

//KEYPAD DEFINITIONS
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
char keyMap[numRows][numCols]=
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3
Keypad keyPad= Keypad(makeKeymap(keyMap), rowPins, colPins, numRows, numCols);

//=============================================================================================================================================================================================

void setup()
{
  lcd.begin(16, 2);                                                                         //Define o número de colunas e linhas do LCD
  Serial.begin(9600);                                                                       //Inicia a comunicação serial com baudrate de 9600
  while(!Serial);                                                                           //Espera a comunicação serial ser estabelecida
  delay(1000);                                                                              //Delay de 1s
  
  Serial.println("Setup Completo!");                                                        //Escreve na porta serial
}

//=============================================================================================================================================================================================

String readVal()
{
  String myString = "";
  char keyPressed = keyPad.getKey();
  while (keyPressed != '#')
  {
    keyPressed = keyPad.getKey();
    if ((keyPressed != NO_KEY) && (keyPressed != '#')) 
    {
      myString.concat(keyPressed);
      lcd.print(keyPressed);
    }   
  }  
  return(myString);  
}
//=============================================================================================================================================================================================

int bitode(int bin)
{
  int q=bin,
  r=0,
  elev=0;
  char txt[20];

  while(q!=0)
  {
    r=q%10;
    q=q/10;
    dec=dec+r*(int)(round(pow(2,elev)));
    elev++;
  }
  return dec;
}

//=============================================================================================================================================================================================

int detobi(int dec)
{
  int i=0,
  r=0,
  q=dec;
  bin=0;
  char txt[20];
  
  while(q>0)
  {
    r=q%2;
    q=(int)(q/2);
    bin=bin+r*(int)(round(pow(10,i)));
    i++;

  }

  return bin;
}
//=============================================================================================================================================================================================

void loop()
{
  bin=0;
  dec=0;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("escolha operacao");
  //         1234567890123456
  lcd.setCursor(0,1);
  lcd.print("A=b->d B=d->b ");
  //         01234567890123456
  oper = readVal();
  
  if(oper == "A")
  {
    lcd.clear();
    lcd.print("Digite um valor:");
    lcd.setCursor(0,1);
    bin = readVal().toInt();
    dec= bitode(bin);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("bin:");
    lcd.print(bin);
    lcd.setCursor(0,1); 
    lcd.print("dec:");
    lcd.print(dec);
    delay(5000);
  }
  else 
  {
    if(oper == "B")
    {
      lcd.clear();
      lcd.print("Digite um valor:");
      lcd.setCursor(0,1);
      dec = readVal().toInt();
      bin= detobi(dec);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("dec:");
      lcd.print(dec);
      lcd.setCursor(0,1); 
      lcd.print("bin:");
      lcd.print(bin);
      delay(5000);
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("opcao invalida!!!");
      lcd.setCursor(0,1);
      lcd.print("tente novamente. ");
      //         01234567890123456
      delay(5000);
    }
  }
}

//http://josecintra.com/blog/arduino-lcd-teclado-buzzer/
