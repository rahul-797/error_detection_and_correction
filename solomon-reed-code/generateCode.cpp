#include <iostream>
#include <vector>
using namespace std;

void print(vector<double>& y) {
  for (auto j : y) {
    cout << j << " ";
  }
  cout << endl;
}

void generateParityBits(vector<double>& y, int totalCorrections) {
  double val = 0;
  for (int i = 0; i < y.size(); i++) {
    double temp = y[i];
    for (int j = 0; j < len2 - 1; j++) {
      if (i == j) continue;
      temp *= (4 - x[j]);
    }
    for (int j = 0; j < len2; j++) {
      if (j == i) continue;
      temp /= (x[i] - x[j]);
    }
    val += temp;
  }
  cout << val << endl;
}

int main() {
  vector<double> y;
  int total = 0;
  int totalCorrections = 0;
  double input = 0.0;

  cout << "Enter the number of digits: ";
  cin >> total;
  cout << "Enter the digits: ";
  for (int i = 0; i < total; i++) {
    cin >> input;
    y.push_back(input);
  }
  cout << "Enter number to digits to correct: ";
  cin >> totalCorrections;

  generateParityBits(y, totalCorrections);
  print(y);

  return 0;
}
