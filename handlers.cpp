#include <algorithm>
#include <string>

using namespace std;

/*/////////////////////////////////////////////////// HOW TO USE ///////////////////////////////////////////////////////////
                     
        string itemName = "potato";
        cout << hashItem(itemName);                         //1681524070
        
        string AnotherItemName = "tomato+soup";
        cout << handleName(AnotherItemName);                //Tomato soup
        
        cout << unhandleName(AnotherItemName);              //tomato+soup

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//converts item name to a hash to be used as item's ID
int hashItem(string n){
    hash<string> hashItem;
    return hashItem(n);
}

//converts item name to a more readable form
string handleName(string n){
    replace(n.begin(), n.end(), '+', ' ');
    n[0] = toupper(n[0]);
    return n;
}

//converts item name to a suitable form for storing in the file
string unhandleName(string n){
    replace(n.begin(), n.end(), ' ', '+');
    n[0] = tolower(n[0]);
    return n;
}
