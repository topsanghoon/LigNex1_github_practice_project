#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <cctype>
using namespace std;

// Morse code 매핑
unordered_map<char, string> morse_map = {
    {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."},    {'F', "..-."}, {'G', "--."},  {'H', "...."},
    {'I', ".."},   {'J', ".---"}, {'K', "-.-"},  {'L', ".-.."},
    {'M', "--"},   {'N', "-."},   {'O', "---"},  {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
    {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}
};
unordered_map<string, char> reverse_map;

// 문자열 → 모스부호
string toMorse(const string& text) {
    stringstream ss;
    for (size_t i = 0; i < text.size(); i++) {
        char c = toupper(text[i]);
        if (morse_map.count(c)) {
            ss << morse_map[c];
            if (i < text.size() - 1) ss << " "; // 문자 구분
        } else if (c == ' ') {
            ss << "/ "; // 단어 구분
        }
    }
    return ss.str();
}

// 모스부호 → 문자열
string fromMorse(const string& code) {
    stringstream ss(code);
    string token, result;
    while (ss >> token) {
        if (token == "/") result.push_back(' ');
        else if (reverse_map.count(token)) result.push_back(reverse_map[token]);
    }
    return result;
}

int main() {
    // reverse_map 초기화
    for (auto& kv : morse_map) reverse_map[kv.second] = kv.first;

    ofstream output("output.txt"); // 항상 덮어쓰기
    if (!output.is_open()) {
        cerr << "File open error!" << endl;
        return 1;
    }

    string line;
    while (getline(cin, line)) {
        if (line == "END") break;

        string morse = toMorse(line);
        string text = fromMorse(morse);

        // 표준 출력
        cout << morse << "\n" << text << "\n";
        // 파일에도 기록
        output << morse << "\n" << text << "\n";
    }

    output.close();
    return 0;
}

