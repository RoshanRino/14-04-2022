#include <iostream>
using namespace std;
class invalidEntryException : public exception
{
public:
    const char *printException()
    {
        return "The Entered Numbers are not valid";
    }
};
class feet
{
    int foot;
    int inch;
    public:
    void operator++ (int )
    {
        inch++;
        if(inch==12)
        {
            inch=0;
            foot++;
        }
    }
    void operator-- (int )
    {
        inch--;
        if(inch<0)
        {
            inch=11;
            foot--;
        }
    }
    feet operator+ (feet d)
    {
        feet temp;
        temp.foot=d.foot+foot;
        temp.inch=d.inch+inch;
        if(temp.inch>11)
        {
            temp.foot++;
            temp.inch=temp.inch-12;
        }
        return temp;
    }
    feet operator- (feet d)
    {
        feet temp;
        if(d.foot>foot)
        {
            temp.foot=d.foot-foot;
            temp.inch=d.inch-inch;
            if(temp.inch<0)
            {
                temp.foot--;
                temp.inch+=12;
            }
        }
        else if(d.foot<foot)
        {
            temp.foot=foot-d.foot;
            temp.inch=inch-d.inch;
            if(temp.inch<0)
            {
                temp.foot--;
                temp.inch+=12;
            }
        }
        else if (temp.inch!=inch)
        {
            temp.foot=0;
            temp.inch= abs(d.inch-inch);
        }
        else
        {
            temp.foot=0;
            temp.inch=0;
        }
        return temp;
    }
    friend istream &operator>> (istream &input,feet &d)
    {
        cout<<"Enter Feet: ";
        input>>d.foot;
        cout<<"Enter Inches: ";
        input>>d.inch;
        return input;
    }
    friend ostream &operator<< (ostream &output,feet &d)
    {
        output<<d.foot<<" "<<d.inch<<"\"";
        return output;
    }
    void operator= (feet d)
    {
        foot=d.foot;
        inch=d.inch;
    }
    int Inch()
    {
        return inch;
    }
};
int main()
{
    try
    {
        feet g,h,sum,diff1,diff2;
        cin>>g>>h;
        if(g.Inch()>11 || h.Inch()>11)
        {
            invalidEntryException e;
            throw e;
        }
        sum=g+h;
        diff1=g-h;
        diff2=h-g;
        cout<<"Sum of distance :"<<sum<<endl;
        cout<<"Difference in distance :"<<diff1<<" & "<<diff2<<endl;
        g++;
        h--;
        cout<<"Increment of first : "<<g<<endl;
        cout<<"Decrement of second : "<<h<<endl;
        g=h;
        cout<<g<<" Is Equal To "<<h<<endl;
    }
    catch(invalidEntryException &Exception)
    {
        cout<<Exception.printException();

    }
    return 0;
}
