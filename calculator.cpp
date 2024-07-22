#include <iostream>

using namespace std;

int main()
{
    int x,y;
    char c;

    cout << "| | Welcome! Precision and simplicity at your fingertips.| |"<<endl ;
    cout<< "Enter two numbers"<<endl;
    cin>>x;
    cin>>y;
    cout<<"Enter the operator:";
    cin>>c;



    switch(c)
    {
    case '+':

        cout<<" "<<x<<" +"<<" "<<y<<" = "<<" "<<x+y<<endl;
        break;

    case '-':
        cout<<" "<<x<<" -"<<" "<<y<<" = "<<" "<<x-y<<endl;
        break;

    case '*':
        cout<<" "<<x<<" *"<<" "<<y<<" = "<<" "<<x*y<<endl;
        break;

    case '/':

        if(y==0)
        {
          cout<<"Division is invalid as divisor cannot be zero"<<endl;
        }

        else  cout<<" "<<x<<" /"<<" "<<y<<" = "<<" "<<(x/y)<<endl;

        break;

    default:

        cout<<"Error! Operator not found"<<endl;

    }


    return 0;
    }











