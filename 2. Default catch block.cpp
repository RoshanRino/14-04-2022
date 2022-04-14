#include<iostream>
using namespace std;
int throInt()
{
    int temp;
    return temp;
}
float throFloat()
{
    float temp;
    return temp;
}
double throDouble()
{
    double temp;
    return temp;
}
char throChar()
{
    char temp;
    return temp;
}
int main()
{
   int a;
   cout<<"Enter a number :";
   cin>>a;
   try
   {
       if(a==1)
            throw throInt();
       else if (a==2)
            throw throFloat();
       else if (a==3)
            throw throDouble();
       else
            throw throChar();
   }
   catch(...)
   {
       cout<<"Default catch block excecuted"<<endl;
   }
   return 0;
}
