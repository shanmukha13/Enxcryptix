#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()

{
     cout<<"\n\t\t\t ||Welcome to the Guessing Game!||"<<endl;
     cout<<"\n\t\tYou have to guess a secret number between 1 to 100!!\n"<<endl;

      srand(time(0));
     int randomNumber = 1+(rand()%100);
     int  number;
     int times=0;

     cout<<"Guess the number: ";



     while(true)
     {

         cin>>number;
         times++;
        if(number<randomNumber)
        {

          cout<<"\nNope,\tEnter the number higher than "<<number<<endl;


        }
        else if (number>randomNumber)
        {

           cout<<"\nNope,\tEnter the number lower than "<<number<<endl;

        }

        else {
            cout<<"\n\t\tYour guess is correct, The secret number is  "<<number<<endl;

            cout<<"\t\tYou took  "<<times<<" attempts to guess the secret number"<<endl;
            break;
        }
     }


  return 0;

}
