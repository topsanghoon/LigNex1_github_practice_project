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
			}
			temp+=charToMorse[c] +" ";
		}
		temp.pop_back();
		morse_answer.push_back(temp);
	}

	for(string s: morse_answer){
		cout<<s<<endl;
	}
}

void morseToString() {
    string_answer.clear(); 

    for (const auto& code : morse_answer) {
        if (code == "/") {
            string_answer.push_back(" "); 
        }
        else if (morseToChar.find(code) != morseToChar.end()) {
            string_answer.push_back(string(1, morseToChar[code]));  
        }
        else {
            string_answer.push_back("?");  
        }
    }
    for(auto s:string_answer){
        cout<<s<<endl;
    }
}

void saveResult(string input, string morse){
    ofstream fout("output.txt", ios::out | ios::app);  
    if (!fout.is_open()) {
        cerr << "Error: cannot open output.txt for writing\n";
        return;
    }
    fout << input << '\n' << morse << '\n';
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
  StringToMorse(input_string);
  morseToString();
  int cnt=0;
  while(cnt < input_string.size())
  {
        saveResult(morse_answer[cnt],string_answer[cnt]);

        cnt++;
  }

	return 0;
}


