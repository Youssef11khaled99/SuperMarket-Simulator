#include "Customer.h"

using namespace std;

int Customer::Count = 0;

Customer::Customer(){}

Customer::Customer(string n, string a): Person(n,a)
{
    Count++;
    cID = 2018000+Count;

    //GET SYSTEM TIME
    time_t now;
    struct tm *now_tm;
    now = time(NULL);
    now_tm = localtime(&now);
    ArrivalTime = new Time(now_tm->tm_hour, now_tm->tm_min);

    //RANDOM SHOPPING DURATION
    int randH = rand() % (4 - 1) ;
    int randM = rand() % (59 - 1);
    shoppingDuration = new Time(randH, randM);
    checkOutTime = new Time();
    *checkOutTime = *ArrivalTime + *shoppingDuration;
}

// int Duration()
// {
//     shoppingDuration = rand() % ((Max - Min +1) + Min)
// }

void Customer::buyItem(Item *i ,int num)
{
    ShoppingItem shopItem(i, num);
    shoppingList.push_back(shopItem);

}

int Customer::getTotal()
{
    int total = 0;
    for(int j = 0; j < shoppingList.size(); j++){
        total+=shoppingList[j].getBoughtAmount() * shoppingList[j].getItemPrice();
    }
    return total;
}

void Customer::print()
{
    for(int i = 0; i < shoppingList.size(); i++)
    {
        cout << shoppingList[i].getItemName() << " Amount: " << shoppingList[i].getBoughtAmount() << " Price: " << shoppingList[i].getItemPrice() << endl;
    }
}

bool Customer::operator<(const Customer& obj) const{
    if(getCheckOutTime().getHours() == obj.getCheckOutTime().getHours()) return getCheckOutTime().getMinutes() < obj.getCheckOutTime().getMinutes();
    return getCheckOutTime().getHours() < obj.getCheckOutTime().getHours();
 }

Time Customer::getCheckOutTime() const
{
    return *checkOutTime;
 }
