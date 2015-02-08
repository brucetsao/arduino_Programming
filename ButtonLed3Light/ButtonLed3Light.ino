int val;//定義變數val
int buttonpin=7 ;//定義button pin8
int redledpin=8 ;//定義Led pin8
int yellowledpin=9 ;//定義Led pin9
int greenledpin=10 ;//定義Led pin10
int lightNumber = 1 ;

void setup()
{
pinMode(buttonpin,INPUT);
pinMode(redledpin,OUTPUT);
pinMode(yellowledpin,OUTPUT);
pinMode(greenledpin,OUTPUT);

//設置數位接腳8為輸出介面，Arduino 上我們用到的I/O 口都要進行類似這樣的定義。
}
void loop()
{
         switch (lightNumber) 
        {
            case 1:
              digitalWrite( redledpin,HIGH) ;
              digitalWrite( yellowledpin,LOW) ;
              digitalWrite( greenledpin,LOW) ;
              break ;

            case 2:
              digitalWrite( redledpin,LOW) ;
              digitalWrite( yellowledpin,HIGH) ;
              digitalWrite( greenledpin,LOW) ;
              break ;

            case 3:
              digitalWrite( redledpin,LOW) ;
              digitalWrite( yellowledpin,LOW) ;
              digitalWrite( greenledpin,HIGH) ;
              break ;
   
          }
  if (digitalRead(buttonpin) == LOW)  //Low for button is open
      {
             lightNumber ++ ;
            if (lightNumber >3)
                lightNumber = 1 ;    
      }
      
delay(400);
 
}


