#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

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
