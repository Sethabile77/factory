#include <iostream>
using namespace std;

class Bank
{
public:
    void withdrawal(double balance)
    {
        double amount;
        cin >> amount;
        cout << "You have successfully withdrawn: " << amount << endl;
    }
    void withdrawal(double balane, double amount)
    {

        cout << "You have successfully  withdrawn: " << amount << endl;
    }
};

int main()
{
    Bank result;
    result.withdrawal(1233.09);
    result.withdrawal(1230.05, 400.50);
    // cout << "Hello World" << endl;
}