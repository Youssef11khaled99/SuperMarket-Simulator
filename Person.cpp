#include "Person.h"

Person::Person()
{
    name = "";
    address = "0000";
}

Person::Person(string n, string a)
{
    name = n;
    address = a;
}

void Person::setName(string n) {name = n;}

void Person::setAddress(string a) {address = a;}

string Person::getName() const {return name;}

string Person::getAddress() const {return address;}


