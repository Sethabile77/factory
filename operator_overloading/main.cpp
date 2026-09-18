#include <iostream>
#include <string>
using namespace std;

class Bank
{
public:
    string last_added_pin;
    Bank(string pin = "12") : last_added_pin(pin)
    {
    }
};
Bank operator+(const Bank &bank, string pin)
{
    Bank absa(bank.last_added_pin);
    absa.last_added_pin += pin;
    cout << "You have successfully added the pin : " << absa.last_added_pin << endl;
    return absa;
}
int main()
{

    Bank result;
    string pin;
    cout << "Please enter your new pin : ";
    cin >> pin;
    result + pin;
}
// prompt user to add the pin,whenever the pin is added it appends the pin to the last pin added
/*void withdrawal(double balance)
{
    double amount;
    cout << "Please enter the amount ";
    cin >> amount;
    if (amount < balance)
    {
        balance = balance - amount;

        cout << "You have successfully withdrawn: R" << amount << " and the new balance after withdrawal is R" << balance << endl;
    }
    else
    {
        cout << "withdrawal not sucessful: insufficient funds" << endl;
    }
}
void withdrawal(double balance, double amount)
{
    if (amount < balance)
    {
        balance = balance - amount;

        cout << "You have successfully  withdrawn: R" << amount << " and the new balance after withdrawal is R" << balance << endl;
    }
    else
    {
        cout << "withdrawal not successful: insufficient funds" << endl;
    }
}*/

/*int main()
{
    Bank result;
    result.withdrawal(1233.09);
    double temp;
    cout << "Please enter the amount ";
    cin >> temp;
    result.withdrawal(1230.05, temp);
    // cout << "Hello World" << endl;
}*/
