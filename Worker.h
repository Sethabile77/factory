#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Worker
{
public:
    friend class Factory;
    Worker(std::string name, double salary);
    ~Worker();
    Worker &operator=(std::string name);
    Worker &operator=(double salary);
    Worker &operator+=(int increase);
    Worker &operator-=(int decrease);
    bool operator==(const Worker &other) const;
    bool operator!=(const Worker &other) const;
    bool operator>(const Worker &other) const;
    bool operator<(const Worker &other) const;
    bool operator>=(const Worker &other) const;
    bool operator<=(const Worker &other) const;
    Worker &operator=(const Worker &other);
    double operator()() const;
    friend ostream &operator<<(ostream &os, const Worker &worker);

private:
    static int idCounter;
    int ID;
    std::string name;
    double salary;
};

#endif