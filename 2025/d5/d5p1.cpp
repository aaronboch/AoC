#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <utility>
#include <sstream>
std::pair<std::vector<std::string>, int> readFile(const std::string& filePath) {
  std::vector<std::string> result{};
  std::ifstream input(filePath);
  std::string temp{};
  int seperationPos;
  while (getline(input, temp)) {
    result.push_back(temp);
    if (temp == "") {
      seperationPos = result.size();
    }
  }
  return {result, seperationPos};
}

std::pair<unsigned long, unsigned long> splitRange(const std::string& range) {
  std::stringstream ss{range};
  unsigned long lhs{}, rhs{};
  ss >> lhs;
  ss.ignore();
  ss >> rhs;
  return {lhs, rhs};
}

int main() {
  //   auto [input, start] = readFile("./input/test");
  auto [input, start] = readFile("./input/input");
  unsigned int result{};
  for (int i = start; i < input.size(); i++) {
    // std::cout << input[i] << std::endl;
    unsigned long test = std::stol(input[i]);
    for (int j = 0; j < start - 1; j++) {
      auto [lhs, rhs] = splitRange(input[j]);
      // std::cout << lhs << "-" << rhs << std::endl;

      if (test >= lhs && test <= rhs) {
        result++;
        break;
      }
    }
  }
  std::cout << result << std::endl;

  return 0;
}
