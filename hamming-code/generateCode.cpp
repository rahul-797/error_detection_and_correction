#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void generateCode(vector<vector<int>>& vec) {
  int value = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (j & 1) {
        value += vec[i][j];
      }
    }
  }
  vec[0][1] = (value - vec[0][1]) % 2;

  value = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 2; j < 4; j++) {
      value += vec[i][j];
    }
  }
  vec[0][2] = (value - vec[0][2]) % 2;

  value = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i & 1) {
        value += vec[i][j];
      }
    }
  }
  vec[1][0] = (value - vec[1][0]) % 2;

  value = 0;
  for (int i = 2; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      value += vec[i][j];
    }
  }
  vec[2][0] = (value - vec[2][0]) % 2;

  value = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      value += vec[i][j];
    }
  }
  vec[0][0] = (value - vec[0][0]) % 2;
}

int main() {
  srand(time(0));
  vector<vector<int>> vec(4, vector<int>(4));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      vec[i][j] = rand() % 2;
    }
  }

  generateCode(vec);
  for (auto i : vec) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  cout << "Generated code: ";
  for (auto i : vec) {
    for (auto j : i) {
      cout << j;
    }
  }
  cout << endl;
  return 0;
}
