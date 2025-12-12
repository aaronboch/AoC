#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <utility>
#include <sstream>
#include <algorithm>
std::vector<std::string> readFile(const std::string& filePath) {
  std::vector<std::string> result{};
  std::ifstream input(filePath);
  if (!input) {
    std::cerr << "Error opening file\n";
    return {};
  }
  std::string temp{};
  while (getline(input, temp)) {
    if (temp == "") {
      break;
    }
    result.push_back(temp);
  }
  return result;
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
  // auto input = readFile("./input/test");
  auto input = readFile("./input/input");
  std::vector<std::pair<unsigned long, unsigned long>> ranges{};
  for (const auto& line : input) {
    // std::cout << input[i] << std::endl;
    ranges.emplace_back(splitRange(line));
  }
  std::sort(ranges.begin(), ranges.end());

  unsigned long result{};
  auto [rangeStart, rangeEnd] = ranges[0];
  for (auto [lhs, rhs] : ranges) {
    // std::cout << lhs << "-" << rhs << std::endl;
    if (lhs > rangeEnd) {
      result += rangeEnd - rangeStart + 1;
      rangeStart = lhs;
      rangeEnd = rhs;
    } else {
      rangeEnd = std::max(rangeEnd, rhs);
    }
  }
  result += rangeEnd - rangeStart + 1;

  std::cout << result << std::endl;

  return 0;
}
