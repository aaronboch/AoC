#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<std::string> readFile(const std::string& filePath);

int main() {
  //   std::vector<std::string> input = readFile("./input/test");
  std::vector<std::string> input = readFile("./input/input");
  int result = 0;
  for (int i = 0; i < input.size(); i++) {
    int firstDigit = 0;
    int firstPos = 0;
    int secondDigit = 0;
    for (int j = 0; j < input[i].length() - 1; j++) {
      if (input[i][j] - '0' > firstDigit) {
        std::cout << input[i][j] << std::endl;
        firstDigit = input[i][j] - '0';
        firstPos = j;
      }
    }
    for (int j = firstPos + 1; j < input[i].length(); j++) {
      if (input[i][j] - '0' > secondDigit) {
        secondDigit = input[i][j] - '0';
      }
    }
    std::cout << firstDigit << secondDigit << std::endl;
    result += firstDigit * 10 + secondDigit;
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