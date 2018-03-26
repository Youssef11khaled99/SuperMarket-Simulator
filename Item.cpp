#include "Item.h"

/*/////////////////////////////////////////////////// HOW TO USE ///////////////////////////////////////////////////////////

                     name      category   amount price
        Item item_1("potato", Vegetables,   99,   12);

        cout << item_1;                           // potato  Vegetables  42  99  12

        item_1.setName("Tomato");
        cout << item_1.getName() << endl;         // Tomato

        item_1.setCategory(Takeaway);
        cout << item_1.getCategory() << endl;     // Takeaway

        cout << item_1.getId() << endl;           // 1681524070

        item_1.setAmount(525);
        cout << item_1.getAmount() << endl;       // 525

        item_1.setPrice(99);
        cout << item_1.getPrice() << endl;        // 99

        cout << item_1 << endl;                   // Tomato  Takeaway  242  525  99

        #NOTE:
            1 - Don't input category as a string "Vegetables", rather put it without the double qoutes due it being a enum type,
                if you need to input with string you can use the setCategoryWithString() function

            2 - Edit the output of the << operator overload to your liking and delete it if not needed
            (don't forget the #include <iostream> in Item.h when deleting)

            3 - The Id of the item is automatically produced using a hash function


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

Item::Item(string n, type c, int am, int p)
{
    name = n;
    category = c;
    id = hashItem(unhandleName(n));;
    amount = am;
    price = p;
}

ostream& operator<<(ostream& out, const Item& item){
    if(item.amount < 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 252);
    out << setw(25) << left <<item.name << setw(25) << left << typeStr[item.category] << setw(25) << left <<
    item.id << setw(25) << left << item.amount << setw(25) << left << item.price << "\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 240);

 }

//will be used for sorting the Stock(sort first by Category then by Name)
bool Item::operator<(const Item& item) const{
     if (this->getCategory() != item.getCategory()){
         return (this->getCategory() < item.getCategory());
     } else {
         return (this->getName() < item.getName());
     }
 }

/*/////////////////////////////////////////////////////// SETTERS & GETTERS ///////////////////////////////////////////////*/

string Item::getName() const{
    return name;
}
void Item::setName(string n){
    name = n;
}

string Item::getCategory() const{
    return typeStr[category];
}
void Item::setCategory(type c){
    category = c;
}
void Item::setCategoryWithString(string str){
    if(str == "Washing") category = Washing;
    else if(str == "Drinking") category = Drinking;
    else if(str == "Takeaway") category = Takeaway;
    else if(str == "Vegetables") category = Vegetables;
    else if(str == "Meat") category = Meat;
}

int Item::getId() const{
    return id;
}

int Item::getAmount() const{
    return amount;
}
void Item::setAmount(int am){
    amount = (am < 0) ? 0 : am;
}

int Item::getPrice() const{
    return price;
}
void Item::setPrice(int p){
    price = (p < 0) ? 0 : p;
}
