#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
std::vector<std::string> readFile(const std::string& filePath);

int main() {
  //   std::vector<std::string> ranges = readFile("./input/test");
  std::vector<std::string> ranges = readFile("./input/input");
  long result = 0;
  for (auto& range : ranges) {
    int pos = range.find("-");
    long lhs = std::stol(range.substr(0, pos));
    long rhs = std::stol(range.substr(pos + 1));
    // std::cout << lhs << "-" << rhs << std::endl;
    std::string num;
    for (; lhs <= rhs; lhs++) {
      num = std::to_string(lhs);
      if (num.length() % 2 != 0) {
        continue;
      }
      //   std::cout << num << std::endl;
      long left = stol(num.substr(0, num.length() / 2));
      long right = stol(num.substr(num.length() / 2));
      if (left == right) {
        result += lhs;
      }
      //   std::cout << left << " " << right << std::endl;
      //   std::cout << result << std::endl;
    }
  }
  std::cout << result << std::endl;
  return 0;
}

std::vector<std::string> readFile(const std::string& filePath) {
  std::vector<std::string> result;
  std::ifstream input(filePath);
  std::string temp;
  while (getline(input, temp, ',')) {
    result.push_back(temp);
  }
  return result;
}