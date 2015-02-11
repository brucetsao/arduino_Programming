#include "pitches.h"
#include <LiquidCrystal.h>
#define flameDPin  12  
#define flameAPin A0
int melodyPin=11;//設置控制蜂鳴器的數位IO腳
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,  
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0
};

//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


 int mariolen = sizeof(melody) / sizeof(int) ;
 LiquidCrystal lcd(8, 9, 10, 45, 43, 41,39,37,35,33,31);
 
 
void setup() 
{ 
pinMode(melodyPin,OUTPUT);//設置數位IO腳模式，OUTPUT為轀出 
 pinMode(flameDPin,INPUT);//定義蜂鳴器為輸入介面
 pinMode(flameAPin,INPUT);//定義蜂鳴器為輸入介面
 

  Serial.begin(9600);//設定串列傳輸速率為9600 } 
 
 // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Now Detect Flame");
}
void loop() {
  int val ;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print("                    ") ;
//   val=digitalRead(flameDPin);//讀取火焰感測器的模擬值 
   val=digitalRead(flameDPin);//讀取火焰感測器的模擬值 
    Serial.println(val);//輸出模擬值，並將其列印出來
 
    if (val ==  0)
    {
           lcd.setCursor(0, 1);
          lcd.print("Fire Alarming");
           playMario() ; 
    }
    else
    {
           lcd.setCursor(0, 1);
          lcd.print("Ready");
           playMario() ; 
    }
    
 /*
 
 if(val== 1)//當模擬值大於600 時蜂鳴器鳴響
 { 
     playMario() ;  
 } 

  */
  delay(200);  
} 


void playMario()
{
   int noteDuration ;
  for(int mariopos=0; mariopos <mariolen; mariopos++)
    {
         noteDuration = 1000/tempo[mariopos]; 
        tone(melodyPin, melody[mariopos],noteDuration); 
        delay(noteDuration*1.3);
    }


  
}
