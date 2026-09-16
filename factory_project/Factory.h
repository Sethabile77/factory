#ifndef FACTORY_H
#define FACTORY_H

#include "Worker.h"
class Worker;
class Factory
{

public:
    Factory();
    Factory &operator=(const Factory &other);
    ~Factory();

    Factory &operator|(string filename);
    int operator[](const Worker &worker) const;
    Worker *operator[](int index) const;
    void operator*=(const Factory &other);
    Factory *operator*(const Factory &other) const;
    Factory &operator+=(Worker *worker);

    Factory &operator+=(Worker &worker);
    Factory &operator-=(Worker *worker);
    bool operator==(const Factory &other) const;
    bool operator!=(const Factory &other) const;
    const Factory &operator>(const Factory &other) const;
    const Factory &operator<(const Factory &other) const;
    const Factory &operator>=(const Factory &other) const;
    const Factory &operator<=(const Factory &other) const;
    friend ostream &operator<<(ostream &os, const Factory &factory);
    friend istream &operator>>(istream &is, Factory &factory);

private:
    Worker **workers;
    int numWorkers;
    friend class Worker;
};

#endif