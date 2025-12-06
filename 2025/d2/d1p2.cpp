#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
std::vector<std::string> readFile(const std::string& filePath);
bool checkInvalid(std::string num, int length);

int main() {
  // std::vector<std::string> ranges = readFile("./input/test");
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
      // std::cout << "num = " << num << std::endl;
      if (checkInvalid(num, num.length())) {
        std::cout << lhs << std::endl;
        result += lhs;
      }
    }
  }
  std::cout << result << std::endl;
  return 0;
}

bool checkInvalid(std::string num, int length) {
  for (int i = 1; i <= length / 2; i++) {
    std::string toCheck = num.substr(0, i);
    // std::cout << "to check:" << toCheck << std::endl;
    // std::cout << "with i = " << i << std::endl;
    for (int j = i; j <= length; j = j + i) {
      std::string against = num.substr(j, i);
      // std::cout << "against:" << against << std::endl;
      // std::cout << "j:" << j << std::endl;
      // std::cout << "length:" << length << std::endl;
      if (j >= (float)length) {
        // std::cout << "returned as invalid" << std::endl;
        return true;
      } else if (against == toCheck) {
        // std::cout << "continued" << std::endl;
        continue;
      } else {
        // std::cout << "break not invalid with i = " << i << std::endl;
        break;
      }
    }
    // std::cout << std::endl;
  }
  // std::cout << "returned as not invalid" << std::endl;
  return false;
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