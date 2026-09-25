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
    BankAccount()
    {
        accNo = "";
        balance = 0;
        pin = "";
    }
    BankAccount(string accountNo, float balance, string pin)
    {
        accNo = accountNo;
        this->balance = balance;
        this->pin = pin;
    }
    friend BankAccount operator+(const BankAccount &ba, float amount);
    friend BankAccount operator+(float amount, const BankAccount &ba);
    friend ostream &operator<<(ostream &os, const BankAccount &ba);
    friend istream &operator>>(istream &is, BankAccount &ba);

    void display()
    {
        cout << "Bank Details: Account Number " << accNo << " ,Balance : " << balance << " ,Pin:  " << pin << endl;
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
ostream &operator<<(ostream &os, const BankAccount &ba)
{
    os << "Your bank details: Your account number is " << ba.accNo << "with a current balance of  " << ba.balance << " and your pin is " << ba.pin << endl;

    return os;
}
// i removed the const because it was giving me a problem and i don't know why
istream &operator>>(istream &input, BankAccount &ba)
{
    cout << "Please enter account Number: ";
    input >> ba.accNo;
    cout << "Please enter balane: ";
    input >> ba.balance;
    cout << "Please enter your pin : ";
    input >> ba.pin;
    return input;
}

int main()
{
    BankAccount absa("456790", 6709.09, "5432");

    absa.display();
    absa = absa + 173.06;
    absa.display();

    absa = 349.90 + absa;
    absa.display();

    cout << absa;
    BankAccount FNB;
    cin >> FNB;

    FNB.display();
}