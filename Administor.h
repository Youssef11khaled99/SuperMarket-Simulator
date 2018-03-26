#include "Stock.cpp"
#include "Customer.cpp"
#include <string>
#include <vector>
using namespace std;

class Administor : public Person
{
    private:
        Stock marketStock;
        double totalRevenue;
    public:
        Administor(string, string);
        vector <Customer> c;
        void reportAvailableItems();
        void updateExistingItem();
        void reportTotalRevenue();
        int totalCustomers();
        void maxReceipt();
        void run();
};
