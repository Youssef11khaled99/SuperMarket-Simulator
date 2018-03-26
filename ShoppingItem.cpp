#include "ShoppingItem.h"


/*/////////////////////////////////////////////////// HOW TO USE ///////////////////////////////////////////////////////////
                     
        Item *item1;
                          name      category   amount price
        item1 = new Item("potato", Vegetables,   99,   12); 
                            
                              item  amount
        ShoppingItem shopItem(item1,  5);
        
        cout << shopItem.getItemName() << endl;         // "potato"
        cout << shopItem.getItemPrice() << endl;          // 12
        cout << shopItem.getBoughtAmount() << endl;       // 5
        
        shopItem.setItemAmount(99);
        cout << shopItem.getItemAmount() << endl;       // 99
        
        shopItem.addToItemAmount(1);
        cout << shopItem.getItemAmount() << endl;       // 100
    
        shopItem.removeFromItemAmount(101);
        cout << shopItem.getItemAmount() << endl;       // 0
        

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

ShoppingItem::ShoppingItem(Item *t, int a){
    item = t;
    amount = a;
}

void ShoppingItem::printOut(){
    cout << "Item: " << *item << "Amount: " << amount << endl;
}


string ShoppingItem::getItemName(){
        return item->getName();
}

int ShoppingItem::getItemPrice(){
        return item->getPrice();
}

int ShoppingItem::getBoughtAmount(){
        return amount;
}



void ShoppingItem::setItemAmount(int a){
        amount = a;
}

void ShoppingItem::addToItemAmount(int a){
        amount += a;
}

void ShoppingItem::removeFromItemAmount(int a){
        amount -= a;
        if (amount < 0) amount = 0;
}
