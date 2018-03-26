#include "handlers.cpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>


using namespace std;

//Each type has an index of its string representation in the array typeStr
enum type {Null = -1, Washing = 0, Drinking = 1, Takeaway = 2, Vegetables = 3, Meat = 4};
string typeStr[] = {"Washing","Drinking","Takeaway","Vegetables","Meat"};

class Item
{
    string name;
    type category;
    int id,amount,price;
public:
    Item(){};
    Item(string, type, int, int);
    friend ostream& operator<<(ostream&, const Item&);
    bool operator<(const Item&) const;
    string getName() const;
    void setName(string);
    string getCategory() const;
    void setCategory(type);
    void setCategoryWithString(string);
    int getId() const;
    int getAmount() const;
    void setAmount(int);
    int getPrice() const;
    void setPrice(int);
};
