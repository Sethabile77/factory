#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
    int numofBankAccounts;

public:
    Bank(int newBank)
    {
        numofBankAccounts = newBank;
    }

    Bank operator-(int accountNumber)
    {
        Bank temp = *this;

        temp.numofBankAccounts -= accountNumber;
        cout << "The Number of account/s  remaining is: " << temp.numofBankAccounts << endl;
        return temp;
    }
};
int main()
{
    // Task 1 :
    cout << "===== Task 1 ==== " << endl;
    cout << endl;
    int numAccount;
    Bank absa(45);
    cout << "Please Enter the number of accounts you want to remove : ";
    cin >> numAccount;
    absa - numAccount;
    cout << endl;

    cout << "===== Task 2 ===== " << endl;
    cout << endl;

    Bank FNB(30);
    int acc1;
    int acc2;
    int acc3;
    int acc4;
    cout << "Please Enter the first  number of accounts you want to remove : ";
    cin >> acc1;
    cout << "Please Enter the second number of accounts you want to remove : ";
    cin >> acc2;
    cout << "Please Enter the third number of accounts you want to remove : ";
    cin >> acc3;
    cout << "Please Enter the  forth number of accounts you want to remove : ";
    cin >> acc4;
    ((((FNB - acc1) - acc2) - acc3) - acc4);
}
// find a way to print out num accounts left , ask the user the amount of accounts you want to remove
// work on the chaining of operators at the end (ask multiple time how many accounts to remove)

// class Bank
// {
// public:
//     string last_added_pin;
//     Bank(string pin = " ") : last_added_pin(pin)
//     {
//     }
// };
// Bank operator+(const Bank &bank, string pin)
// {
//     Bank absa(bank.last_added_pin);
//     absa.last_added_pin += "\n";
//     absa.last_added_pin += pin;
//     cout << "You have successfully added the pin : " << absa.last_added_pin << endl;
//     return absa;
// }
// int main()
// {

//     Bank result;
//     string pin;
//     string pin2;
//     string pin3;
//     cout << "Please enter your new pin1 : ";
//     cin >> pin;

//     cout << "Please enter your new pin2 : ";
//     cin >> pin2;

//     cout << "Please enter your new pin3 : ";
//     cin >> pin3;

//     (((result + pin) + pin2) + pin3);
// }
// // prompt user to add the pin,whenever the pin is added it appends the pin to the last pin added
// /*void withdrawal(double balance)
// {
//     double amount;
//     cout << "Please enter the amount ";
//     cin >> amount;
//     if (amount < balance)
//     {
//         balance = balance - amount;

//         cout << "You have successfully withdrawn: R" << amount << " and the new balance after withdrawal is R" << balance << endl;
//     }
//     else
//     {
//         cout << "withdrawal not sucessful: insufficient funds" << endl;
//     }
// }
// void withdrawal(double balance, double amount)
// {
//     if (amount < balance)
//     {
//         balance = balance - amount;

//         cout << "You have successfully  withdrawn: R" << amount << " and the new balance after withdrawal is R" << balance << endl;
//     }
//     else
//     {
//         cout << "withdrawal not successful: insufficient funds" << endl;
//     }
// }*/

// /*int main()
// {
//     Bank result;
//     result.withdrawal(1233.09);
//     double temp;
//     cout << "Please enter the amount ";
//     cin >> temp;
//     result.withdrawal(1230.05, temp);
//     // cout << "Hello World" << endl;
// }*/
