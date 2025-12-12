#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <tuple>
std::vector<std::string> readFile(const std::string& filePath);

int main() {
  // std::vector<std::string> input = readFile("./input/test");
  std::vector<std::string> input = readFile("./input/input");
  int result = 0;
  std::vector<std::tuple<int, int>> directions = {
      {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
  int rows = input.size();
  int cols = input[0].length();
  int tempResult = 0;
  do {
    tempResult = 0;
    for (int row = 0; row < rows; row++) {
      for (int col = 0; col < cols; col++) {
        int adjacent = 0;
        if (input[row][col] != '@') continue;

        for (auto [rowDir, colDir] : directions) {
          int neighborRow = row + rowDir;
          int neighborCol = col + colDir;
          if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 &&
              neighborCol < cols && input[neighborRow][neighborCol] == '@') {
            adjacent++;
          }
        }

        if (adjacent < 4) {
          tempResult++;
          result++;
          input[row][col] = 'x';
        }
      }
    }
  } while (tempResult > 0);
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