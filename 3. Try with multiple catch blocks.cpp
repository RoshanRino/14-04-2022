#include <iostream>
using namespace std;
class feet
{
    public:
    int foot;
    int inch;
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
};
int main()
{
    feet g,h,sum,diff1,diff2;
    cout<<"Total length Should not exceed 10 feet"<<endl;;
    cin>>g>>h;
    sum=g+h;
    try
    {
        cout<<"Start of try Block"<<endl;
        if(sum.foot>=10 && sum.foot<20)
            throw 10;
        else if(sum.foot>=20 && sum.foot<30)
            throw 40.2;
        else if(sum.foot>=30 )
             throw g ;
        cout<<"End of try Block"<<endl;
    }
    catch(int a)
    {
        cout<<"catch INTEGER executed"<<endl<<"Limit Exceeded"<<endl;
    }
    catch(double a)
    {
        cout<<"catch DOUBLE executed"<<endl<<"Limit Exceeded"<<endl;
    }
    catch(...)
    {
        cout<<"catch DEFAULT executed"<<endl<<"Limit Exceeded"<<endl;
    }
    cout<<"End of program";
    return 0;
}
