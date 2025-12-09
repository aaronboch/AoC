#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stack>
std::vector<std::string> readFile(const std::string& filePath);

int main() {
  // std::vector<std::string> input = readFile("./input/test");
  std::vector<std::string> input = readFile("./input/input");
  unsigned long result = 0;

  for (int i = 0; i < input.size(); i++) {
    std::vector<int> joltage;
    int toRemove = input[i].size() - 12;
    for (int j = 0; j < input[i].length(); j++) {
      int digit = input[i][j] - '0';
      while (!joltage.empty() && toRemove > 0 && joltage.back() < digit) {
        joltage.pop_back();
        toRemove--;
      }
      joltage.push_back(digit);
    }
    if (toRemove > 0) {
      while (toRemove > 0) {
        joltage.pop_back();
        toRemove--;
      }
    }
    long temp = 0;
    for (auto digit : joltage) {
      temp = temp * 10 + digit;
    }
    std::cout << temp << std::endl;
    result += temp;
  }
  std::cout << result << std::endl;
  return 0;
}

std::vector<std::string> readFile(const std::string& filePath) {
  std::vector<std::string> result;
  std::ifstream input(filePath);
  std::string temp;
  while (getline(input, temp)) {
    result.push_back(temp);
  }
  return result;
}