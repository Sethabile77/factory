#include <iostream>

#include "Factory.h"
#include "Worker.h"
int main()
{
    Factory *factory = new Factory();
    *factory | "file.txt";
    Worker *worker1 = new Worker("Jane Doe", 540.34);
    Worker *worker2 = new Worker("Tarzan", 4521.235);

    *factory += *worker1;
    *factory += *worker2;

    cout
        << *factory;
    delete factory;

    Factory factory1;
    Worker *work1 = new Worker("Jane Doe", 540.34);
    Worker *work2 = new Worker("Tarzan", 4521.235);
    Worker *work3 = new Worker("Alice", 234234.24);
    factory1 += work1;
    factory1 += work2;
    factory1 += work3;

    cout << endl;
    cout << "Factory1 before deletion: " << endl;
    cout << factory1;
    cout << endl;
    cout << "Factory1 after Tarzan is removed: " << endl;
    factory1 -= work2;
    cout << factory1;
    cout << endl;
    cout << "Testing copy operator: " << endl;
    Factory factory2;

    factory2 = factory1;
    cout << factory2;
    cout << endl;
    cout << "Boolean testing: " << endl;

    cout << "f1 == f2 ? is  " << (factory1 == factory2 ? "true" : "false") << endl;
    cout << "f1 != f2 ? is " << (factory1 != factory2 ? "true" : "false") << endl;
    cout << "f1 > f2 ? is " << (&factory1 == &factory2 ? "true" : "false") << endl;
    delete work1;
    delete work2;
    delete work3;
    return 0;
}