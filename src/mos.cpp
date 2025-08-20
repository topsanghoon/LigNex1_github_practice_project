#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

unordered_map<char, string> charToMorse;
unordered_map<string, char> morseToChar;


void loadMorseTable(){
cout<<"hi check out"<<'\n;
cout<<"hi check out"<<'\n;
cout<<"hi check out"<<'\n;
cout<<"hi check out"<<'\n;
cout<<"hi check out"<<'\n;
cout<<"hi check out"<<'\n;
cout<<"hi check out"<<'\n;
cout<<"hi check out"<<'\n;

}
string stringToMorse(string s){

	string ret_string;
	for(char c: s){
		ret_string += charToMorse[c];
	}

	return ret_string;

}
string morseToString(const string& morse) {

    unordered_map<string, char> morseToChar = {
        {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
        {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
        {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
        {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
        {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'}
    };

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


}
