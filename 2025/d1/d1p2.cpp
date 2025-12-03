#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readFile(const std::string& filePath);
int mod(int i, int m);

int main() {
  int dialPosition = 50;
  unsigned int result = 0;
  // std::vector<std::string> input = readFile("./input/test");
  std::vector<std::string> input = readFile("./input/input");
  for (auto& line : input) {
    int num = std::stoi(line.substr(1, line.length()));
    result += num / 100;
    switch (line[0]) {
      case 'L':
        if (dialPosition != 0) {
          result += dialPosition - num % 100 <= 0 ? 1 : 0;
        }
        dialPosition = mod(dialPosition - num, 100);
        break;
      case 'R':
        result += dialPosition + num % 100 > 99 ? 1 : 0;
        dialPosition = mod(dialPosition + num, 100);
        break;
      default:
        break;
    }
  }
  std::cout << result << std::endl;
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

int mod(int i, int m) { return ((i % m) + m) % m; }