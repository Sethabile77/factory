#include "Factory.h"
#include "Worker.h"
using namespace std;

namespace
{
    double total(const Factory &factory)
    {
        double total = 0;
        int index = 0;
        while (factory[index] != NULL)
        {
            const double value = (*factory[index])();
            total = total + value;
            index += 1;
        }
        return total;
    }
}
Factory::Factory()
{
    numWorkers = 0;
    workers = new Worker *[0];
}

Factory::~Factory()
{
    int index = 0;
    while (index < this->numWorkers)
    {
        delete this->workers[index];
        index += 1;
    }
    delete[] this->workers;
}
Factory &Factory::operator=(const Factory &other)
{
    if (this == &other)
    {
        return *this;
    }
    Worker **op = new Worker *[other.numWorkers];
    int end = 0;
    try
    {
        while (end < other.numWorkers)
        {
            op[end] = new Worker(*other.workers[end]);
            ++end;
        }
    }
    catch (...)
    {
        while (end > 0)
        {
            --end;
            delete op[end];
        }
        delete[] op;
        throw;
    }
    int index = 0;
    while (index < this->numWorkers)
    {
        delete this->workers[index];
        index += 1;
    }
    delete[] this->workers;
    this->workers = op;
    this->numWorkers = other.numWorkers;
    return *this;
}
Factory &Factory::operator|(std::string filename)
{
    std::ifstream inputfile(filename.c_str());
    if (!inputfile.is_open())
    {
        return *this;
    }
    inputfile >> *this;
    return *this;
}
int Factory::operator[](const Worker &worker) const
{
    int index = 0;
    while (index < this->numWorkers && *this->workers[index] != worker)
    {
        ++index;
    }
    return index < this->numWorkers ? index : -1;
}

Worker *Factory::operator[](int index) const
{
    Worker *result = NULL;
    if (index >= 0 && index < this->numWorkers)
    {
        result = this->workers[index];
    }
    return result;
}
void Factory::operator*=(const Factory &other)
{
    if (this == &other)
    {
        return;
    }
    int index = 0;
    while (index < other.numWorkers)
    {
        Worker *op = other.workers[index];
        *this += op;
        index += 1;
    }
    return;
}
Factory *Factory::operator*(const Factory &other) const
{
    Factory *result = new Factory();
    try
    {
        *result *= *this;
        int index = 0;
        while (index < other.numWorkers)
        {
            *result += other.workers[index];
            index += 1;
        }
    }
    catch (...)
    {
        delete result;
        throw;
    }
    return result;
}
Factory &Factory::operator+=(Worker *worker)
{
    if (worker == NULL)
    {
        return *this;
    }
    const int k = (*this)[*worker];
    if (k != -1)
    {
        return *this;
    }
    Worker **op = new Worker *[this->numWorkers + 1];
    int index = 0;
    while (index < this->numWorkers)
    {
        op[index] = this->workers[index];
        index += 1;
    }
    Worker *copy = NULL;
    try
    {
        copy = new Worker("", 0);
        *copy = *worker;
    }
    catch (...)
    {
        delete copy;
        delete[] op;
        throw;
    }
    op[this->numWorkers] = copy;
    delete[] this->workers;
    this->workers = op;
    ++this->numWorkers;
    return *this;
}
Factory &Factory::operator+=(Worker &worker)
{
    if ((*this)[worker] != -1)
    {
        return *this;
    }
    Worker **op = new Worker *[this->numWorkers + 1];
    int index = 0;
    while (index < this->numWorkers)
    {
        op[index] = this->workers[index];
        index += 1;
    }
    op[this->numWorkers] = &worker;
    delete[] this->workers;
    this->workers = op;
    ++this->numWorkers;
    return *this;
}
Factory &Factory::operator-=(Worker *worker)
{
    if (worker == NULL)
    {
        return *this;
    }
    const int count_to_remove = (*this)[*worker];
    if (count_to_remove == -1)
    {
        return *this;
    }
    Worker **op = new Worker *[this->numWorkers - 1];
    int next = 0;
    int index = 0;
    while (index < this->numWorkers)
    {
        if (index != count_to_remove)
        {
            op[next] = this->workers[index];
            ++next;
        }
        index += 1;
    }
    delete this->workers[count_to_remove];
    delete[] this->workers;
    this->workers = op;
    --this->numWorkers;
    return *this;
}
bool Factory::operator==(const Factory &other) const
{
    const double this_side = total(*this);
    const double other_side = total(other);
    return this_side == other_side;
}
bool Factory::operator!=(const Factory &other) const
{
    return !(*this == other);
}
const Factory &Factory::operator>(const Factory &other) const
{
    const double this_side = total(*this);
    const double other_side = total(other);
    if (this_side != other_side)
    {
        if (this_side > other_side)
        {
            return *this;
        }
        return other;
    }
    return *(new Factory());
}
const Factory &Factory::operator<(const Factory &other) const
{
    const double this_side = total(*this);
    const double other_side = total(other);
    if (this_side != other_side)
    {
        if (this_side < other_side)
        {
            return *this;
        }
        return other;
    }
    return *(new Factory());
}
const Factory &Factory::operator>=(const Factory &other) const
{
    return *this > other;
}

const Factory &Factory::operator<=(const Factory &other) const
{
    return *this < other;
}

std::ostream &operator<<(std::ostream &os, const Factory &factory)
{
    if (factory.numWorkers == 0)
    {
        return os << "Empty factory";
    }
    int index = 0;
    while (index < factory.numWorkers)
    {
        os << *factory.workers[index] << '\n';
        index += 1;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Factory &factory)
{
    std::string input;
    while (std::getline(is, input))
    {
        if (!input.empty() && input[input.size() - 1] == '\r')
        {
            input.erase(input.size() - 1);
        }
        if (input.empty() || input == "Empty factory")
        {
            continue;
        }
        const std::string::size_type i = input.find(',');
        const std::string::size_type j = input.rfind(",R");
        if (input.compare(0, 8, "Worker: ") != 0 || i == std::string::npos ||
            j == std::string::npos || j <= i)
        {
            is.setstate(std::ios::failbit);
            return is;
        }
        const std::string Name = input.substr(i + 1, j - i - 1);
        std::istringstream salaryInput(input.substr(j + 2));
        double salary;
        if (!(salaryInput >> salary))
        {
            is.setstate(std::ios::failbit);
            return is;
        }
        salaryInput >> std::ws;
        if (!salaryInput.eof())
        {
            is.setstate(std::ios::failbit);
            return is;
        }
        Worker *worker = new Worker(Name, salary);
        const int before = factory.numWorkers;
        try
        {
            factory += *worker;
        }
        catch (...)
        {
            delete worker;
            throw;
        }
        if (factory.numWorkers == before)
        {
            delete worker;
        }
    }
    return is;
}
