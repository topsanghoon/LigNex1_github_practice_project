
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
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
        morseToChar[code] = letter;
    }

    fin.close();
}

int main(){

	vector<string> input_string;
	while(1){
		string temp;
		cin >> temp;

		if(temp == "END") break;
		input_string.push_back(temp);

	}
  
  loadMorseTable();

	return 0;
}
