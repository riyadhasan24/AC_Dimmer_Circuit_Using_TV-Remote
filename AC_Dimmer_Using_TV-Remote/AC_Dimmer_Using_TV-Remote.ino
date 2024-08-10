/* The source Code from : https://github.com/riyadhasan24
 * By Md. Riyad Hasan
 */

/*
 * I used "25 in 1 small TV Remote / 50J2 Remote"
 */


#include <IRremote.h>
#include <TimerOne.h>

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
          }
        
        // Remote Button 1
        if(Results.value == 0x38863BE0)  
          {
            Dim = 112;            
          }

        // Remote Button 2
        if(Results.value == 0x38863BD0)
          {
            Dim = 98;           
          }

        // Remote Button 3
        if(Results.value == 0x38863BF0)
          {
            Dim = 84;           
          }

        // Remote Button 4
        if(Results.value == 0x38863BC8)
          {
            Dim = 70;           
          }

        // Remote Button 5
        if(Results.value == 0x38863BE8)
          {
            Dim = 56;           
          }

        // Remote Button 6
        if(Results.value == 0x38863BD8)
          {
            Dim = 46;           
          }

        // Remote Button 7
        if(Results.value == 0x38863BF8)
          {
            Dim = 32;           
          }

        // Remote Button 8
        if(Results.value == 0x38863BC4)
          {
            Dim = 18;           
          }

        // Remote Button 9      || Fan Full-Speed
        if(Results.value == 0x38863BE4)
          {
            Dim = 0;           
          }
    }
}