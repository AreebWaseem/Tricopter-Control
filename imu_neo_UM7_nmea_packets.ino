 char a;
 String b;
 int count;
 char arr=' ';
 double data_0;
 double data_1;
 double data_2;
 double data_3;
 double roll, pitch, yaw;
 double sensor_x, sensor_y, sensor_z;
 int data_count;
 int accelero_count;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial1.begin(115200);
count=0;
roll=0;
pitch=0;
yaw=0;
data_count=0;
data_0=0;
data_1=0;
data_2=0;
data_3=0;
accelero_count=0;
sensor_x=0;
sensor_y=0;
sensor_z=0;
}

void loop() {
  // put your main code here, to run repeatedly:
get_accelero_values();
if (millis()%50==0)
{
Serial.println(roll);
}
}

void get_accelero_values()
{
if (Serial1.available())
{
  a=Serial1.read();
  if (count==0)
  {
   if (a=='$')
   {
    count=1;
   } 
  }
  if (count == 1)
  {
    
  if (a==',')
  {
    data_count++;
    if (data_count==3)
    {
      data_0= b.toDouble();
    }
    if (data_count==4)
    {
    data_1= b.toDouble();
  //Serial.println(data);
    }
    if (data_count==5)
    {
      data_2= b.toDouble();
    }
    if (data_count==6)
    {
      data_3= b.toDouble();
    }
   b="";
   // Serial.println(data_count);
  }
  if (a!=',' && data_count > 1 )
  {
    b+=a;
  }
   if (a=='*')    // Check Sum 
   {
    if (data_count==5)
    {
      roll= data_0;
      pitch= data_1;
      yaw= data_2;
    }
    if (data_count==6)
    {
      if (accelero_count<1)
      {
 //  Serial.println(data_1);
   sensor_x= data_1;
   sensor_y= data_2;
   sensor_z= data_3;
      }
   accelero_count++;
   if (accelero_count>2)
   {
    accelero_count=0;
   }
    }
    count=0;
    b="";
    data_count=0;
    data_1=0;
    data_2=0;
    data_3=0;
   }
}
//Serial.println(roll);
//Serial.println(test);
}
//Serial.println(b);
//Serial.println(roll);
}

