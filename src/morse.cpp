#include <iostream>
#include <vector>
#include <string>

using namespace std;




int main(){

	vector<string> input_string;
	while(1){
		string temp;
		cin >> temp;

		if(temp == "END") break;
		input_string.push_back(temp);

	}

	//for(int i = 0; i < input_string.size(); i++) cout << input_string[i];

	return 0;
}


