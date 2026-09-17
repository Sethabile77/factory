#include <iostream>
using namespace std;

class Bank
{
public:
    void withdrawal(double balance)
    {
        double amount;
        cin >> amount;
        if (amount < balance)
        {
            balance = balance - amount;
        }
        cout << "You have successfully withdrawn: R" << amount << " and the new balance after withdrawal is R" << balance << endl;
    }
    void withdrawal(double balance, double amount)
    {
        if (amount < balance)
        {
            balance = balance - amount;
        }

        cout << "You have successfully  withdrawn: R" << amount << " and the new balance after withdrawal is R" << balance << endl;
    }
};

int main()
{
    Bank result;
    result.withdrawal(1233.09);
    result.withdrawal(1230.05, 400.50);
    // cout << "Hello World" << endl;
}