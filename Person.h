#include <string>

using namespace std;
class Person
{
    private:
        string name;
        string address;

    public:
        Person();
        Person (string, string);
        void setName (string);
        string getName () const;
        void setAddress (string);
        string getAddress () const;
};

