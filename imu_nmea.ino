char a;
String b;
String ref;
double count=0;
double lati;
void setup()
{
Serial.begin(9600);
Serial1.begin(9600);
}

void loop()
{
 
  if (Serial1.available())
  {
a=Serial1.read();
if (a=='\n')
{
  if(count==1 && ref=="pitch")
  {
    ref="";
    count=0;
    lati= b.toDouble();
   Serial.println(lati,5);
  }
  if (b.lastIndexOf("pitch")>0)
  {
    ref="pitch";
    count=1;
  }
b="";
}
b+=a;
}

}
/*
void isValid(String a)
{
  char arra[a.length()+1];
  a.toCharArray(arra, sizeof(arra));
for int(i)
  
}
*/


