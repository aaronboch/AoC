#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readFile(const std::string& filePath);
int mod(int i, int m);

int main() {
  int dialPosition = 50;
  uint result = 0;
  // std::vector<std::string> input = readFile("./input/test");
  std::vector<std::string> input = readFile("./input/input");
  for (auto& line : input) {
    switch (line[0]) {
      case 'L':
        dialPosition =
            mod(dialPosition - std::stoi(line.substr(1, line.length())), 100);
        break;
      case 'R':
        dialPosition =
            mod(dialPosition + std::stoi(line.substr(1, line.length())), 100);
        break;
      default:
        break;
    }
    if (dialPosition == 0) {
      result++;
    }
    // std::cout << line << " Dialpos: " << dialPosition << " Result: " <<
    // result << std::endl;
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