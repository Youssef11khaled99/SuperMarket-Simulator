#include "Administor.h"
#include <sstream>

Administor::Administor(string name, string address) : Person(name, address){}

void Administor::reportAvailableItems()
{
    marketStock.printStock();
}

int read(int &b)
{
    cin>>b;
    if(cin.fail())
    {
        cout<<"You should enter correct value : ";
        cin.clear();
        cin.ignore(10000, '\n');
        return read(b);
    }
}

void Administor:: updateExistingItem()
{
    int choice;
    Item *t1;
    string choosenItem;
    reportAvailableItems();
    do{
        cout<<"Please enter item Name: ";
        cin.ignore(10000 , '\n');
        getline(cin, choosenItem , '\n');
        t1 = marketStock.findItemWithName(choosenItem);
    } while (t1 == NULL);

    cout<<"To update the available units of "<<t1->getName()<<" enter 1, to update price enter 2: ";
    read(choice);
    while(choice != 1 && choice != 2)
    {
        cout<<"Please enter valid number (1 or 2 )";
        read(choice);
    }
    if( choice == 1)
    {
        int newAmount;
        cout<<"Please enter the new number of units of "<<t1->getName()<<" : ";
        read(newAmount);
        t1->setAmount(newAmount);
    }
    else if( choice == 2)
    {
        int newPrice;
        cout<<"Please enter the new price of "<<t1->getName()<<" : ";
        cin>>newPrice;
        t1->setPrice(newPrice);
    }
}

void Administor:: reportTotalRevenue()
{
    marketStock.sortStock();
    int total=0;
    for ( int i = 0 ; i < c.size() ; i++)
    {
            total += c[i].getTotal();
    }
    cout<<"Total Revenue = "<<total<<" $"<<endl;
    cout<<"Order of the customers are: "<<endl;
    sort(c.begin(), c.end());
    for(int i = c.size()- 1 ; i >= 0 ; i--)
    {
        cout<<c[i].getName()<<", checkout at "<<c[i].getCheckOutTime()<<endl;
    }
    c.clear();
}

int Administor:: totalCustomers()
{
    return c.size();
}

void Administor:: maxReceipt()
{
    double Max = c[0].getTotal();
    int index = 0;
    for(int i = 0 ; i < c.size() ; i++)
    {
        if( c[i].getTotal() > Max)
        {
            Max = c[i].getTotal();
            index = i;
        }
    }
    cout << "Customer" << index << " Receipt: " << Max << endl;
}
void Administor:: run()
{
    while(true){
        int choice;
        cout<<"Press 1 to Enter as admin, 2 to Enter as customer, and 0 to end the program: ";
        read(choice);
        system("CLS");
        while(choice != 0 && choice != 1 && choice != 2)
        {
            cout<<"Please enter valid number (1 or 2): ";
            read(choice);
            system("CLS");
        }
        if (choice == 0){
            cout << "\t\t\tThank you for using SuperMarketSimulator" << endl;
            marketStock.saveStock();
            break;
        }

        else if(choice == 1)
        {
            char a;
            while( a != 'N' && a != 'n')
            {
                int numOfOperation;

                cout<<"What you want to do:"<<endl;
                cout<<"\t1- ReportAvailableItems"<<endl;
                cout<<"\t2- AddNewItem "<<endl;
                cout<<"\t3- UpdateExistingItem "<<endl;
                cout<<"\t4- ReportTotalRevenue "<<endl;
                cout<<"\t5- DisplayTotalCustomers "<<endl;
                cout<<"\t6- DisplayMaxReceipt "<<endl;

                read(numOfOperation);
                system("CLS");
                if(numOfOperation == 1)
                {
                    reportAvailableItems();
                }
                else if(numOfOperation == 2)
                {
                    string name, category;
                    int amount, price;
                    cout<<"*****************************AddNewItem*****************************"<<endl;
                    cout << "Enter item name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter item category(Washing,Drinking,Takeaway,Vegetables,Meat): ";
                    cin >> category;
                    cout << "Enter item amount: ";
                    read(amount);
                    cout << "Enter item price: ";
                    read(price);
                    marketStock.addItem(name, category, amount, price);
                }
                else if(numOfOperation == 3)
                {
                    updateExistingItem();
                }
                else if(numOfOperation == 4)
                {
                    reportTotalRevenue();
                }
                else if(numOfOperation == 5)
                {
                    cout << "Total Customers: " << totalCustomers() << endl;
                }
                else if(numOfOperation == 6)
                {
                    if( c.size() < 1 )
                    {
                        cout<<"There are no customers yet!"<<endl;
                    }
                    else{maxReceipt();}
                }
                cout<<"Do you want to do another operation? "<<endl;
                cin>>a;
                system("CLS");
            }
            a = 'y';
        }

        else if(choice == 2)
        {
//            cout<<"Please enter number of customers: ";
//

//            read(customerNum);
//           customerSize+=customerNum;

//            for(int i = customerSize - customerNum ; i < c.size() ; i++)
            //{

               // string customerName = "Cust" + bridge.str();
                Customer w("Ahmed", "25 street");
                int customerNum = c.size()-1;
                cout<<endl<<"Please select from the following menu the items that Customer"<<c.size()<<" bought: "<<endl;
                reportAvailableItems();
                char AnotherItemChoice;
                int itemAmount;
                string itemName;
                while( AnotherItemChoice != 'N' && AnotherItemChoice != 'n')
                {
                    Item *t;
                    cin.ignore();
                    do {
                        cout<<"Please enter the item Name :";
                        getline(cin, itemName);
                        t = marketStock.findItemWithName(itemName);
                    } while(t == NULL);
                    do{
                    cout<<"Please enter the item amount :";
                    read(itemAmount);
                    } while (t->getAmount() < itemAmount);
                    t->setAmount(t->getAmount() - itemAmount);
                    w.buyItem(t, itemAmount);
                    cout<< "The price will be: " << w.getTotal() << "$" << endl;
                    cout<<"Do you want to buy anything else? "<<endl;
                    cin>>AnotherItemChoice;
                }
                 system("CLS");
                w.print();
                c.push_back(w);
                AnotherItemChoice = 'y';
           // }
        }
    }
}
