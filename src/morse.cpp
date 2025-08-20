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
    ifstream fin("include/morse.txt");
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

void StringToMorse(const vector<string>& input_string) {
    morse_answer.clear();

    for (const string& word : input_string) {
        string temp;
        for (size_t i = 0; i < word.size(); i++) {
            char c = toupper(static_cast<unsigned char>(word[i]));
            if (c == ' ') {
                temp += "/ ";
            } else if (charToMorse.count(c)) {
                temp += charToMorse[c] + " ";
            }
        }
        if (!temp.empty() && temp.back() == ' ') {
            temp.pop_back();
        }
        morse_answer.push_back(temp);
    }
}

void morseToString() {
    string_answer.clear();

    for (const string& line : morse_answer) {
        stringstream ss(line);
        string token;
        string restored;

        while (ss >> token) {
            if (token == "/") {
                restored.push_back(' ');
            } else if (morseToChar.count(token)) {
                restored.push_back(morseToChar[token]);
            } else {
                restored.push_back('?');
            }
        }
        string_answer.push_back(restored);
    }
}

void saveResult(const vector<string>& morse, const vector<string>& text) {
    ofstream fout("src/output.txt", ios::out);  // 덮어쓰기 모드
    if (!fout.is_open()) {
        cerr << "Error: cannot open output.txt for writing\n";
        return;
    }

    for (size_t i = 0; i < morse.size(); i++) {
        fout << morse[i] << '\n';
        fout << text[i] << '\n';
    }
    fout.close();
}

int main() {
    vector<string> input_string;
    string line;

    while (true) {
        getline(cin, line);
        if (line == "END") break;
        input_string.push_back(line);
    }

    loadMorseTable();
    StringToMorse(input_string);
    morseToString();

    // 표준 출력
    for (size_t i = 0; i < morse_answer.size(); i++) {
        cout << morse_answer[i] << '\n';
        cout << string_answer[i] << '\n';
    }

    // 파일 저장 (덮어쓰기)
    saveResult(morse_answer, string_answer);

    return 0;
}

