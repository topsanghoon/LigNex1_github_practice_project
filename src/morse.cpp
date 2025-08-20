
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include<vector>

using namespace std;

unordered_map<char, string> charToMorse;
unordered_map<string, char> morseToChar;
vector<string> morse_answer;  // 변환된 모스부호가 저장되는 전역변수
vector<string> string_answer; // 변환된 문자열이 저장되는 전역변수

void loadMorseTable();
void StringToMorse(const vector<string>& input_string);

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


int main(){

	vector<string> input_string;
	while(1){
		string temp;
		cin >> temp;

		if(temp == "END") break;
		input_string.push_back(temp);

	}
  


	return 0;
}
