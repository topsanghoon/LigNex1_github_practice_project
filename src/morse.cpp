#include<string>
#include<vector>
#include<unordered_map>
#include <cctype>
#include <iostream>

using namespace std;


unordered_map<char, string> charToMorse;  // key: 문자, value: key값에 매핑되는 모스부호
vector<string> morse_answer;  // 변환된 모스부호가 저장되는 전역변수

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