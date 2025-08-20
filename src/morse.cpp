#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, string> charToMorse;
unordered_map<string, char> morseToChar;

vector<string> morse_answer;
vector<string> string_answer;

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

void StringToMorse(const vector<string>& input_string){

	for(int i=0;i<input_string.size();i++){
		string temp;
		for(char c:input_string[i]){
			c = toupper(c);
			if(c==' '){
				temp+="/ ";
				continue;
			}
			temp+=charToMorse[c] +" ";
		}
		temp.pop_back();
		morse_answer.push_back(temp);
	}
}


void morseToString() {
    string_answer.clear();

    stringstream ss(morse);
    string code;
    string result;
    while(const auto& code : morse_answer) {
        if(code == "/") {
            string_answer.push_back(" ");
        } else if(morseToChar.find(code) != morseToChar.end()) {
            string_answer.push_back(string(1, morseToChar[code]));
        } else {
            string_answer.push_back("?");
        }
	
    }
    
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

