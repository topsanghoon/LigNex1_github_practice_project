#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

/**
 * @brief Morse code 변환기
 *
 * - 문자열 → 모스부호
 * - 모스부호 → 문자열
 */

// Morse code 매핑
const std::unordered_map<char, std::string> kMorseMap = {
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

std::unordered_map<std::string, char> kReverseMap;

/**
 * @brief 문자열을 모스부호로 변환
 * @param text 입력 문자열
 * @return 변환된 모스부호
 */
std::string ToMorse(const std::string& text) {
  std::stringstream ss;
  for (size_t i = 0; i < text.size(); i++) {
    char c = std::toupper(static_cast<unsigned char>(text[i]));
    if (kMorseMap.count(c)) {
      ss << kMorseMap.at(c);
      if (i < text.size() - 1) {
        ss << " ";  // 문자 구분
      }
    } else if (c == ' ') {
      ss << "/ ";  // 단어 구분
    }
  }
  return ss.str();
}

/**
 * @brief 모스부호를 문자열로 변환
 * @param code 모스부호 문자열
 * @return 변환된 일반 문자열
 */
std::string FromMorse(const std::string& code) {
  std::stringstream ss(code);
  std::string token;
  std::string result;
  while (ss >> token) {
    if (token == "/") {
      result.push_back(' ');
    } else if (kReverseMap.count(token)) {
      result.push_back(kReverseMap[token]);
    }
  }
  return result;
}

int main() {
  // reverse_map 초기화
  for (const auto& kv : kMorseMap) {
    kReverseMap[kv.second] = kv.first;
  }

  std::ofstream output("output.txt");  // 항상 덮어쓰기
  if (!output.is_open()) {
    std::cerr << "File open error!\n";
    return 1;
  }

  std::string line;
  while (std::getline(std::cin, line)) {
    if (line == "END") {
      break;
    }

    std::string morse = ToMorse(line);
    std::string text = FromMorse(morse);

    // 표준 출력
    std::cout << morse << "\n" << text << "\n";
    // 파일에도 기록
    output << morse << "\n" << text << "\n";
  }

  output.close();
  return 0;
}

