#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

unordered_map<char,string> morse_list;

loadMorseTable(){

}
string stringToMorse(string s){
	string ret_string;
	for(char c: s){
		ret_string += morse_list[c];
	}

	return ret_string;
}
string morseToString(string) {

}
saveResult(string input, string morse, string output){

}
int main(){

	return 0;
}
