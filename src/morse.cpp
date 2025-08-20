#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;
vector<string> morse_answer;
vector<string> string_answer;
vector<string> input_string;
int vector_size;

void loadMorseTable() {


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

    int cnt=0;
    while(cnt < input_string.size())
    {
        saveResult(morse_answer[cnt],string_answer[cnt]);

        cnt++;
    }

    return 0;

}
