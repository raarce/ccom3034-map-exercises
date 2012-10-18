#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {

    map<string, string> M; 
    string st1, st2;
    
    // Read a file with string pairs.
    ifstream F("pairs.txt");
    while (F>>st1) {
        F >> st2;
        // insert into the map!
        M[st1] = st2; 
    }

    // traverse the map (in order)
    cout << "Printing the contents of the map:\n";
    map<string,string>::iterator it = M.begin();
    for (;it!=M.end();it++) cout << it->first << ":" << it->second << endl;
  
    cout << endl;
    it = M.find("gallina");
    if (it != M.end())
        cout << "Key gallina maps to value: "  << M["gallina"] << endl;
    else cout << "Not found: gallina\n";


    it = M.find("gallo");
    if (it != M.end())
        cout << M["gallo"] << endl;
    else cout << "Not found: gallo\n";

    return 0;
}//end main
