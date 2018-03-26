#include "Stock.h"

/*/////////////////////////////////////////////////// HOW TO USE ///////////////////////////////////////////////////////////

        Stock s1;

        s1.printStock();
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////
                NAME                     CATEGORY                 ID                       AMOUNT                   PRICE

                Sausage                  Meat                     1237458600               24                       48
                Cheese burger            Takeaway                 1480338690               200                      8
                Mexican pizza            Takeaway                 -1041626879              30                       26
                Potato                   Vegetables               1681524070               120                      12
                                                                    .
                                                                    .
                                                                    .
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////


        s1.sortStock();     // will sort by category and in each category sort by name


                     sortBy  order
        s1.sortStock("Price", true);         //custom sort sortBy{"Name", "Category", "Amount", "Price" }
                                                      and order {ascending = false, descending = true}
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////
                NAME                     CATEGORY                 ID                       AMOUNT                   PRICE

                Oz powder                Washing                  2010220083               11                       60
                Sausage                  Meat                     1237458600               24                       48
                Mexican pizza            Takeaway                 -1041626879              30                       26
                Potato                   Vegetables               1681524070               120                      12
                                                                    .
                                                                    .
                                                                    .
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////


        s1.saveStock();     // will save updated stock to file


                     Name      Category   Amount Price
        s1.addItem("lolipop", "Takeaway",   50,   1);

        //not recommended, use removeItemWithName() for clarity
        s1.removeItemWithId(1681524070);

        s1.removeItemWithName("potato");

        ////////////////////////////////////////////Manipulating items///////////////////////////////////////////////////

         Item *t1;

        //not recommended, use findItemWithName() for clarity
        t1 = s1.findItemWithId(1681524070);
         Or
        t1 = s1.findItemWithName("potato");

        cout << t1->getName();      //"Potato"
        cout << t1->getId();        //1681524070

        t1->setPrice(999);
        cout << t1->getPrice();     //999
        .
        .
        .

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

string fileName = "stock.txt";

Stock::Stock(){
    loadStock();
}

void Stock::loadStock(){
    ifstream  stock(fileName);
    if (stock.is_open()){
        string itemLine, name, category;
        int id, amount, price;
        //skip first two lines
        getline (stock,itemLine);
        getline (stock,itemLine);
        while(getline (stock,itemLine) && !stock.eof()){
            // used to split the string to variables
            istringstream ss (itemLine);
            ss >> name;
            ss >> category;
            ss >> id;
            ss >> amount;
            ss >> price;
            amount = (amount < 0) ? 0 : amount;
            price = (price < 0) ? 0 : price;
            addItem(handleName(name), category, amount, price);
        }
        stock.close();
    }
}

void Stock::printStock(){
        cout << setw(25) << left << "NAME" << setw(25) << left << "CATEGORY" << setw(25) << left << "ID"
        << setw(25) << left << "AMOUNT" << setw(25) << left << "PRICE" << endl << endl;
        HANDLE  theConsole;
        theConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        for(int i = 0; i < itemList.size(); i++){
            cout << itemList.at(i);
        }
}

void Stock::addItem(string name, string category, int amount, int price){
        if(findItemWithName(name) == NULL){
            Item item(name, Null, amount, price);
            // we used setCategoryWithString() due to the constructor not accepting category as a string
            item.setCategoryWithString(category);
            itemList.push_back(item);
        }
}

void Stock::removeItemWithId(int id){
        for(int i = 0; i < itemList.size(); i++){
            if(itemList.at(i).getId() == id){
                itemList.erase(itemList.begin()+i);
                break;
            }
        }
}

void Stock::removeItemWithName(string n){
    removeItemWithId(hashItem(unhandleName(n)));
}

Item* Stock::findItemWithId(int id){
        for(int i = 0; i < itemList.size(); i++){
            if(itemList.at(i).getId() == id){
                return &itemList[i];
            }
        }
        return NULL;
}

Item* Stock::findItemWithName(string n){
    return findItemWithId(hashItem(unhandleName(n)));
}

void Stock::sortStock(){
    sort(itemList.begin(), itemList.end());
}

void Stock::sortStock(string sortType, bool order){
    if(sortType == "Name")  sort(itemList.begin(), itemList.end(), sortByName(order));
    else if(sortType == "Category")  sort(itemList.begin(), itemList.end(), sortByCategory(order));
    else if(sortType == "Amount")  sort(itemList.begin(), itemList.end(), sortByAmount(order));
    else if(sortType == "Price")  sort(itemList.begin(), itemList.end(), sortByPrice(order));
}

void Stock::saveStock(){
    ofstream  stock(fileName);
    if (stock.is_open()){
        stock << setw(25) << left << "NAME" << setw(25) << left << "CATEGORY" << setw(25) << left << "ID"
        << setw(25) << left << "AMOUNT" << setw(25) << left << "PRICE" << endl << endl;
        for(int i = 0; i < itemList.size(); i++){
            itemList.at(i).setName(unhandleName(itemList.at(i).getName()));
            stock << itemList.at(i);
            itemList.at(i).setName(handleName(itemList.at(i).getName()));
        }
        stock.close();
    }

}

