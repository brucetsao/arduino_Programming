int val;//定義變數val
int buttonpin=7 ;//定義button pin8
int ledpin=8 ;//定義Led pin8


void setup()
{
pinMode(buttonpin,INPUT);
pinMode(ledpin,OUTPUT);
//設置數位接腳8為輸出介面，Arduino 上我們用到的I/O 口都要進行類似這樣的定義。
}
void loop()
{
  if (digitalRead(buttonpin) == LOW)  //Low for button is open
      {
        digitalWrite( ledpin,HIGH) ;
      }
      else
      {
           digitalWrite( ledpin,LOW) ;
      }
      

 
}


