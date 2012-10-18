// From http://net.pku.edu.cn/~course/cs101/2011/resource/notes-cpp/stl-containers/map/map-ex-wordfreq.html
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
using namespace std;

//========================================================= main
int main() {

    set<string> ignore;    // Words to ignore.
    map<string, int> freq; // Map of words and their frequencies
    string word;           // Used to hold input word.
    
    //-- Read file of words to ignore.
    ifstream ignoreFile("ignore.txt");
    while (ignoreFile >> word) {
        ignore.insert(word);
    }

    //-- Read words/tokens to count from input stream.
    while (cin >> word) {
	if (word == "@@@") break;
        if (ignore.find(word) == ignore.end()) {
            freq[word]++; // Count this.  It's not in ignore set.
        }
    }

    //-- Write count/word.  Iterator returns key/value pair.
    map<string, int>::const_iterator iter;
    for (iter=freq.begin(); iter != freq.end(); ++iter) {
        cout << iter->second << " " << iter->first << endl;
    }

    system("PAUSE");  // keep console window open in DevC++.
    return 0;
}//end main
