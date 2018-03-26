using namespace std;

class ShoppingItem{
    Item *item;
    int amount;
public:
    ShoppingItem(Item*, int);
    void printOut();
    string getItemName();
    int getItemPrice();
    int getBoughtAmount();
    void setItemAmount(int);
    void addToItemAmount(int);
    void removeFromItemAmount(int);

};
