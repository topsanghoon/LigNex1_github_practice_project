#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<pair<char, string>> morse_list

void loadMorseTable(){
	ifstream fin("../include/morse.txt");
	if(!fin.is_open()){
		cerr << "Error: cannot open morse.txt" << endl;
		return;
	}

	char letter;
	string code;

	while(fin >> letter >> code){
		morse_list.push_back({letter, code});
	}

	fin.close();
}

int main(){
	loadMorseTable();
}
