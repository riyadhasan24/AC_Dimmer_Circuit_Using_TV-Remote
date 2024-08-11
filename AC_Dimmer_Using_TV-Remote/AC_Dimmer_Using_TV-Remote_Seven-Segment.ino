/* The source Code from : https://github.com/riyadhasan24
 * By Md. Riyad Hasan
 */

/*
 * I used "25 in 1 small TV Remote / 50J2 Remote"
 */

#include <IRremote.h>
#include <TimerOne.h>


#define Pin_A A1
#define Pin_B A0
#define Pin_C 4
#define Pin_D A5
#define Pin_E A4
#define Pin_F A2
#define Pin_G A3


int Receive_PIN = 3;
IRrecv IR_Receive(Receive_PIN);
decode_results Results;

int Dim = 0;           
int Freq_Step = 75;                         // This Freq_Step for 50Hz AC Power
volatile int ZC = 0;
volatile boolean Zero_Cross = 0;

#define Traic_Pin 9

void setup()
{
  IR_Receive.enableIRIn();
  
  pinMode(Pin_A, OUTPUT);
  pinMode(Pin_B, OUTPUT);
  pinMode(Pin_C, OUTPUT);
  pinMode(Pin_D, OUTPUT);
  pinMode(Pin_E, OUTPUT);
  pinMode(Pin_F, OUTPUT);
  pinMode(Pin_G, OUTPUT);

  pinMode(Traic_Pin, OUTPUT);

  Timer1.initialize(Freq_Step);
  Timer1.attachInterrupt(Dim_Check, Freq_Step);
  
  attachInterrupt(0, Zero_Cross_Detect, RISING);
}

void Zero_Cross_Detect()
{
  Zero_Cross = true;
  ZC = 0;
  digitalWrite(Traic_Pin, LOW);
}

void Dim_Check()
{
  if(Zero_Cross == true)
  {
    if(ZC >= Dim)
    {
      digitalWrite(Traic_Pin, HIGH);
      ZC = 0;
      Zero_Cross = false;
    }
    else
    {
      ZC++;
    }
  }
}

void loop()
{
  if(IR_Receive.decode(&Results))
    {    
        IR_Receive.resume();

        // Remote Button 0      || Fan Off
        if(Results.value == 0x38863BC0)
          {
            Dim = 128;
            Digit_Zero();
          }
        
        // Remote Button 1
        if(Results.value == 0x38863BE0)  
          {
            Dim = 112;
            Digit_One();
          }

        // Remote Button 2
        if(Results.value == 0x38863BD0)
          {
            Dim = 98;
            Digit_Two();
          }

        // Remote Button 3
        if(Results.value == 0x38863BF0)
          {
            Dim = 84;
            Digit_Three();
          }

        // Remote Button 4
        if(Results.value == 0x38863BC8)
          {
            Dim = 70;
            Digit_Four();
          }

        // Remote Button 5
        if(Results.value == 0x38863BE8)
          {
            Dim = 56;
            Digit_Five();
          }

        // Remote Button 6
        if(Results.value == 0x38863BD8)
          {
            Dim = 46;
            Digit_Six();
          }

        // Remote Button 7
        if(Results.value == 0x38863BF8)
          {
            Dim = 32;
            Digit_Seven();
          }

        // Remote Button 8
        if(Results.value == 0x38863BC4)
          {
            Dim = 18;
            Digit_Eight();
          }

        // Remote Button 9      || Fan Full-Speed
        if(Results.value == 0x38863BE4)
          {
            Dim = 0;
            Digit_Nine();
          }
    }
}


void Digit_Zero()
{
  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, LOW);
  digitalWrite(Pin_C, LOW);
  digitalWrite(Pin_D, LOW);
  digitalWrite(Pin_E, LOW);
  digitalWrite(Pin_F, LOW);
  digitalWrite(Pin_G, HIGH);
}

void Digit_One()
{
  digitalWrite(Pin_A, HIGH);
  digitalWrite(Pin_B, LOW);
  digitalWrite(Pin_C, LOW);
  digitalWrite(Pin_D, HIGH);
  digitalWrite(Pin_E, HIGH);
  digitalWrite(Pin_F, HIGH);
  digitalWrite(Pin_G, HIGH);
}

void Digit_Two()
{
  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, LOW);
  digitalWrite(Pin_C, HIGH);
  digitalWrite(Pin_D, LOW);
  digitalWrite(Pin_E, LOW);
  digitalWrite(Pin_F, HIGH);
  digitalWrite(Pin_G, LOW);
}

void Digit_Three()
{
  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, LOW);
  digitalWrite(Pin_C, LOW);
  digitalWrite(Pin_D, LOW);
  digitalWrite(Pin_E, HIGH);
  digitalWrite(Pin_F, HIGH);
  digitalWrite(Pin_G, LOW);
}

void Digit_Four()
{
  digitalWrite(Pin_A, HIGH);
  digitalWrite(Pin_B, LOW);
  digitalWrite(Pin_C, LOW);
  digitalWrite(Pin_D, HIGH);
  digitalWrite(Pin_E, HIGH);
  digitalWrite(Pin_F, LOW);
  digitalWrite(Pin_G, LOW);
}

void Digit_Five()
{
  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, HIGH);
  digitalWrite(Pin_C, LOW);
  digitalWrite(Pin_D, LOW);
  digitalWrite(Pin_E, HIGH);
  digitalWrite(Pin_F, LOW);
  digitalWrite(Pin_G, LOW);
}

void Digit_Six()
{
  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, HIGH);
  digitalWrite(Pin_C, LOW);
  digitalWrite(Pin_D, LOW);
  digitalWrite(Pin_E, LOW);
  digitalWrite(Pin_F, LOW);
  digitalWrite(Pin_G, LOW);
}

void Digit_Seven()
{
  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, LOW);
  digitalWrite(Pin_C, LOW);
  digitalWrite(Pin_D, HIGH);
  digitalWrite(Pin_E, HIGH);
  digitalWrite(Pin_F, HIGH);
  digitalWrite(Pin_G, HIGH);
}

void Digit_Eight()
{
  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, LOW);
  digitalWrite(Pin_C, LOW);
  digitalWrite(Pin_D, LOW);
  digitalWrite(Pin_E, LOW);
  digitalWrite(Pin_F, LOW);
  digitalWrite(Pin_G, LOW);
}

void Digit_Nine()
{
  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, LOW);
  digitalWrite(Pin_C, LOW);
  digitalWrite(Pin_D, LOW);
  digitalWrite(Pin_E, HIGH);
  digitalWrite(Pin_F, LOW);
  digitalWrite(Pin_G, LOW);
}
