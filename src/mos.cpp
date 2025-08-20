#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

unordered_map<char, string> charToMorse;
unordered_map<string, char> morseToChar;

void loadMorseTable() {
    ifstream fin("../include/morse.txt");
    if (!fin.is_open()) {
        cerr << "Error: cannot open morse.txt" << endl;
        return;
    }

    char letter;
    string code;
    while (fin >> letter >> code) {
        charToMorse[letter] = code;
    }
    fin.close();

}


string stringToMorse(string s) {

    string ret_string;
    for (char c : s) {
        ret_string += charToMorse[c];
    }

    return ret_string;

}

string morseToString(const string& morse) {

    stringstream ss(morse);
    string code;
    string result;
    while(ss >> code) {
        if(code == "/") {
            result += " ";
        } else if(morseToChar.find(code) != morseToChar.end()) {
            result += morseToChar[code];
        } else {
            result += '?';
        }
    }
    return result;
}
void saveResult(string input, string morse, string output){

}

int main(){

    return 0;

}
