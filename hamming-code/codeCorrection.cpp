#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool* checkParityBits(vector<vector<int>>& vec, bool* errParityBits) {
  int value = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < 4; j += 2) {
      value += vec[i][j];
    }
  }
  if ((value % 2) != 0) {
    errParityBits[0] = 1;
  }
  value = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 2; j < 4; j++) {
      value += vec[i][j];
    }
  }
  if ((value % 2) != 0) {
    errParityBits[1] = 1;
  }
  value = 0;
  for (int i = 1; i < 4; i += 2) {
    for (int j = 0; j < 4; j++) {
      value += vec[i][j];
    }
  }
  if ((value % 2) != 0) {
    errParityBits[2] = 1;
  }
  value = 0;
  for (int i = 2; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      value += vec[i][j];
    }
  }
  if ((value % 2) != 0) {
    errParityBits[3] = 1;
  }
  value = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      value += vec[i][j];
    }
  }
  if ((value % 2) != 0) {
    errParityBits[4] = 1;
  }
  return errParityBits;
}

void detect(vector<vector<int>>& vec) {
  bool errParityBits[5] = {0, 0, 0, 0, 0};
  checkParityBits(vec, errParityBits);

  bool error = false;
  if (errParityBits[4] == 0) {
    for (int i = 0; i < 4; i++) {
      if (errParityBits[i] == 1) {
        error = true;
        break;
      }
    }
    if (error) {
      cout << "There are 2 errors" << endl;
      return;
    } else {
      cout << "There is no error" << endl;
      return;
    }
  }
  if (errParityBits[4] && !errParityBits[0] && !errParityBits[1] &&
      !errParityBits[2] && !errParityBits[3]) {
    cout << "Error is at row: 1 and col: 1" << endl;
    return;
  }

  int errCol = 0;
  int errRow = 0;
  if (errParityBits[0] && errParityBits[1]) errCol = 3;
  if (!errParityBits[0] && !errParityBits[1]) errCol = 0;
  if (!errParityBits[0] && errParityBits[1]) errCol = 2;
  if (errParityBits[0] && !errParityBits[1]) errCol = 1;
  if (errParityBits[2] && errParityBits[3]) errRow = 3;
  if (!errParityBits[2] && !errParityBits[3]) errRow = 0;
  if (!errParityBits[2] && errParityBits[3]) errRow = 2;
  if (errParityBits[2] && !errParityBits[3]) errRow = 1;
  cout << "Error is at row: " << errRow + 1 << " and col: " << errCol + 1
       << endl;
  cout << "Position: (" << errRow + 1 << ", " << errCol + 1 << ")" << endl;
}

int main() {
  string s;
  vector<vector<int>> vec(4, vector<int>(4));
  int index = 0;
  cout << "Welcome to Hamming Code correction" << endl;
  cout << "Enter the code without spaces: ";
  cin >> s;

  if (s.length() != 16) {
    cout << "!!! Enter 16-bit code !!!" << endl;
    return 1;
  }
  for (char i : s) {
    if (i != '1' && i != '0') {
      cout << "Enter only binary digits" << endl;
      return 1;
    }
  }
  cout << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      vec[i][j] = s[index++] - '0';
    }
  }

  cout << "The provided bits are: " << endl;
  for (auto i : vec) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  cout << endl;

  detect(vec);

  return 0;
}
