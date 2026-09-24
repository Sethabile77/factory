#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accNo;
    float balance;
    string pin;

public:
    BankAccount(string accountNo, float balance, string pin)
    {
        accNo = accountNo;
        this->balance = balance;
        this->pin = pin;
    }
    friend BankAccount operator+(const BankAccount &ba, float amount);
    friend BankAccount operator+(float amount, const BankAccount &ba);
    void display()
    {
        cout << accNo << " " << balance << " " << pin << endl;
    }
};

BankAccount operator+(const BankAccount &ba, float amount)
{
    BankAccount temp = ba;

    temp.balance += amount;
    return temp;
}

BankAccount operator+(float amount, const BankAccount &ba)
{
    BankAccount temp = ba;

    temp.balance += amount;
    return temp;
}

int main()
{
    BankAccount absa("456790", 6709.009, "5432");

    absa.display();
    absa + 173.06;
    absa.display();

    349.90 + absa;
    absa.display();
}