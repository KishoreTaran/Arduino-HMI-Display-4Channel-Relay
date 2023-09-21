unsigned char Buffer[9];
int relay2 = 4;
int relay3 = 5;
int relay4 = 6;
int relay1 = 3;
 
void setup()
{
  Serial.begin(115200);
 
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, LOW);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, LOW);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay3, LOW);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay4, LOW);
 }
 
void loop()
{
  if (Serial.available())
  {
    for (int i = 0; i <= 8; i++) //this loop will store whole frame in buffer array.
    {
      Buffer[i] = Serial.read();
    }
 
    if (Buffer[0] == 0X5A)
    {
      switch (Buffer[4])
      {
        case 0x51:  //for relay
          if (Buffer[8] == 1)
          { digitalWrite(relay1, HIGH);
            Serial.println("relay1 on");
          }
          else
          { digitalWrite(relay1, LOW);
            Serial.println("relay1 off");
          }
          break;
 
 
        case 0x52:  //for relay
          if (Buffer[8] == 1)
          { digitalWrite(relay2, HIGH);
            Serial.println("relay2 on");
          }
          else
          { digitalWrite(relay2, LOW);
            Serial.println("relay2 off");
          }
          break;
 
 
        case 0x53:  //for relay
          if (Buffer[8] == 1)
          { digitalWrite(relay3, HIGH);
            Serial.println("relay3 on");
          }
          else
          { digitalWrite(relay3, LOW);
            Serial.println("relay3 off");
          }
          break;
  
        case 0x54:  //for relay
          if (Buffer[8] == 1)
          { digitalWrite(relay4, HIGH);
            Serial.println("relay4 on");
          }
          else
          { digitalWrite(relay4, LOW);
            Serial.println("relay4 off");
          }
          break;
 
 
        default:
          Serial.println("Nothing");
          break;
      }
    }
  }
  delay(10);
}
