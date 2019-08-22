#include <SPI.h>
#include <SD.h>
#include <Adafruit_BMP085.h>
File myFile;
const int chipSelect = 4;
char a;
String b;
String ref;
int count=0;
float roll=0;
float pitch=0;
float yaw=0;
float roll_bt=0;
float pitch_bt=0;
float yaw_bt=0;
float Thrust_motor=0;
float thrust_bt=0;
float Sensor_x=0;
float Sensor_y=0;
float Sensor_z=0;
float sensor_x_bt=0;
float sensor_y_bt=0;
float sensor_z_bt=0;
float height=0;
File dataFile;
void setup() {
  Serial.begin(9600);
Serial1.begin(57600);
Serial2.begin(9600);
  // put your setup code here, to run once:
///////////////////////// SD initialization /////////////////////////
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while(1);
  }
  Serial.println("card initialized.");
  
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
recieve_values();
//Serial.println(Serial1.read());
if (millis()%200==0)
{
  
 dataFile = SD.open("myFusion.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
          dataFile.print("Sensor_x,");
          dataFile.print(Sensor_x);
          dataFile.print("Sensor_y,");
            dataFile.print(Sensor_y);
            dataFile.print("Sensor_z,");
              dataFile.print(Sensor_z);
          dataFile.print("roll,");
            dataFile.print(roll);
            dataFile.print("pitch,");
              dataFile.print(pitch);
              dataFile.print("yaw,");
              dataFile.print(yaw);
               dataFile.print("height,");
              dataFile.println(height);      
    dataFile.close();
    // print to the serial port too:
   // Serial.println("done");
    Serial.println(roll);
  }
}
}

void recieve_values()
{
    while(Serial1.available())
  {
a=Serial1.read();
if (a=='$' && count==0)
{
count++;
}

if (count>=1)
{
  if (a==',')
  {
    if (count==2)
    {
        Sensor_x= b.toFloat();
    }
    if (count==3)
    {
      Sensor_y= b.toFloat();
    }
    if (count==4)
    {
       Sensor_z= b.toFloat();
    }
    if (count==5)
    {
       roll= b.toFloat();
    }
    if (count==6)
    {
       pitch= b.toFloat();
    }
    if (count==7)
    {
       yaw= b.toFloat();
    }
    if (count==8)
    {
      height= b.toFloat();
    }
    b="";
    count++;
  }
  if (a!=','&& count>1)
  {
  b+=a;
  }
}
if (a=='\n')
{
  b="";
  count=0;
}
  }
}



