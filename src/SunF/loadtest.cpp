#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

unordered_map<char, string> morse_list;

void printMorseTable() {
    for (const auto& pair : morse_list) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

void loadMorseTable() {
    ifstream fin("../include/morse.txt");
    if (!fin.is_open()) {
        cerr << "Error: cannot open morse.txt" << endl;
        return;
    }

    char letter;
    string code;

    while (fin >> letter >> code) {
        morse_list[letter] = code;
    }

    fin.close();
}

int main() {
    loadMorseTable();
    printMorseTable();
    return 0;
    
}