#include "Item.cpp"
#include "sortHelpers.cpp"

#include <vector>
#include <fstream>
#include <unordered_map>
#include <sstream> 


using namespace std;

class Stock
{
    vector <Item> itemList;
public:
    Stock();
    void loadStock();
    // should be moved up to admin class
    void printStock();
    void addItem(string, string, int, int);
    void removeItemWithId(int);
    void removeItemWithName(string);
    Item* findItemWithId(int);
    Item* findItemWithName(string);
    void sortStock();
    void sortStock(string, bool);
    void saveStock();
};

