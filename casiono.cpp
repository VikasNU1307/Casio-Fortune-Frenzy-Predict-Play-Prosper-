#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rules();
int main()
{
    string playerName;
    int Money; // stores player's Money
    int bettingBalance;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    
     char Check;
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    
   

    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting Money to play game : $";
    cin >> Money;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current Money is $ " << Money << "\n";
// Get player's betting Money
        do
        {
            cout << "Hey, " << playerName<<", enter amount to bet : $";
            cin >> bettingBalance;
            if(bettingBalance > Money)
                cout << "Betting Money can't be more than current Money!\n"
                       <<"\nRe-enter Money\n ";
        }while(bettingBalance > Money);
         dice = rand()%10 + 1;
         //cout<<dice<<endl;
// Get player's numbers
        cout<< "the guessing number is: " << dice <<endl;
        do
        {   
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
       
        
        if(dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingBalance * 10;
            Money = Money + bettingBalance * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< bettingBalance <<"\n";
            Money = Money - bettingBalance;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have Money of $ " << Money << "\n";
        if(Money == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your Money is $ " << Money << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}
