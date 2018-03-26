#include "Person.cpp"
#include "ShoppingItem.cpp"
#include "Time.cpp"

#include <cstdlib>
#include <string>

#include <ctime>


class Customer : public Person
{
    private:
        int cID;
        vector<ShoppingItem> shoppingList;
        Time* ArrivalTime;
        Time* shoppingDuration;
        Time* checkOutTime;

    public:
        static int Count;
        Customer();
        Customer(string, string);
        void buyItem(Item* ,int);
        int getTotal();
        void print();
        bool operator<(const Customer&) const;
        Time getCheckOutTime() const;
};
