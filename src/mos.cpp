#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

unordered_map<char, string> charToMorse;
unordered_map<string, char> morseToChar;

void loadMorseTable(){

}
string stringToMorse(string s){
   
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
