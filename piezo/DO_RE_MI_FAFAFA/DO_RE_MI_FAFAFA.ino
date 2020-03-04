#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C 261
#define NOTE_D 294
#define NOTE_E 329
#define NOTE_F 349
#define NOTE_G 392
#define NOTE_A 440
#define NOTE_B 523
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.125
#define SIXTEENTH 0.0625
int tune[] = { NOTE_C, NOTE_D, NOTE_E, NOTE_F, NOTE_F, NOTE_F, NOTE_C, NOTE_D,
NOTE_C, NOTE_D, NOTE_D, NOTE_D, NOTE_C, NOTE_G, NOTE_F, NOTE_E, NOTE_E, NOTE_E, NOTE_C, NOTE_D,
NOTE_E, NOTE_F, NOTE_F, NOTE_F};
float duration[] = {QUARTER, QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,QUARTER,};

void setup() {
  // put your setup code here, to run once:
pinMode(8, OUTPUT);
length =21);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int x=0; x<length; x++) {
tone(8, tune[x]);
delay(1500 * duration[x]);
noTone(8);
}
delay(5000);
}
