#include <vector>
#include <string>
#include <fstream>
#include <iostream>
std::vector<std::string> readFile(const std::string& filePath);

int main() {
  //   std::vector<std::string> input = readFile("./input/test");
  std::vector<std::string> input = readFile("./input/input");
  int length = input[0].length();
  int result = 0;
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < length; j++) {
      int adjacent = 0;
      if (input[i][j] == '@') {
        if (i != 0) {
          // check top 3
          if (j != 0) adjacent += input[i - 1][j - 1] == '@' ? 1 : 0;
          adjacent += input[i - 1][j] == '@' ? 1 : 0;
          if (j != length - 1) adjacent += input[i - 1][j + 1] == '@' ? 1 : 0;
        }
        // check left
        if (j != 0) adjacent += input[i][j - 1] == '@' ? 1 : 0;
        // right
        if (j != length - 1) adjacent += input[i][j + 1] == '@' ? 1 : 0;
        if (i != input.size() - 1) {
          // check bottom 3
          if (j != 0) adjacent += input[i + 1][j - 1] == '@' ? 1 : 0;
          adjacent += input[i + 1][j] == '@' ? 1 : 0;
          if (j != length - 1) adjacent += input[i + 1][j + 1] == '@' ? 1 : 0;
        }
        if (adjacent < 4) {
          result++;
        }
      }
    }
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