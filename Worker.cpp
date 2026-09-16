#include "Worker.h"

int Worker::idCounter = 1;

Worker::Worker(std::string name, double salary)
{
    this->name = name;
    this->salary = salary;
    ID = idCounter++;
}

Worker::~Worker()
{
}
Worker &Worker::operator=(std::string name)
{
    if (name != "")
    {
        this->name = name;
    }

    return *this;
}
Worker &Worker::operator=(double salary)
{

    if (salary >= 0)
    {
        this->salary = salary;
    }

    return *this;
}
Worker &Worker::operator+=(int increase)
{
    if ((salary + increase) >= 0)
    {
        salary += increase;
    }

    return *this;
}
Worker &Worker::operator-=(int decrease)
{
    if ((salary - decrease) >= 0)
    {
        salary -= decrease;
    }

    return *this;
}

bool Worker::operator==(const Worker &other) const
{
    return (this->name == other.name && this->salary == other.salary);
}

bool Worker::operator!=(const Worker &other) const
{
    return (this->name != other.name && this->salary != other.salary);
}

bool Worker::operator>(const Worker &other) const
{
    return (this->salary > other.salary);
}

bool Worker::operator<(const Worker &other) const
{
    return (this->salary < other.salary);
}
bool Worker::operator>=(const Worker &other) const
{
    return (this->salary >= other.salary);
}
bool Worker::operator<=(const Worker &other) const
{
    return (this->salary <= other.salary);
}
Worker &Worker::operator=(const Worker &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->salary = other.salary;
    }

    return *this;
}
double Worker::operator()() const
{
    return salary;
}
ostream &operator<<(ostream &os, const Worker &worker)
{
    os << "Worker: " << worker.ID << "," << worker.name << ",R" << std::fixed << std::setprecision(2) << worker.salary;
    return os;
}
