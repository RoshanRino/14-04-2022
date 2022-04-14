#include<iostream>

using namespace std;
int main()
{
    int a;
    cout<<"Enter a number: ";
    cin>>a;
    int quotient;
    try
    {
        quotient = a/5;
        cout<<"The quotient when divided by 5 is: "<<quotient<<endl;
        if(quotient<10)
            throw quotient;

    }
    catch (int e)
    {
        cout<<"Catch Block is Executed"<<endl;
        cout<<"Quotient value to low";
    }
    return 0;
}
