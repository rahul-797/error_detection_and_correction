#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool generateCode(int *arr) {
  int sum = 0, sum2 = 0;
  for (int i = 0; i < 9; i++) {
    sum += arr[i];
    sum2 += (i + 1) * arr[i];
  }
  sum %= 9, sum2 %= 9;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (((sum + i + j) % 9 == 0) && ((sum2 + (10 * i) + (11 * j)) % 9 == 0)) {
        arr[9] = i, arr[10] = j;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  string isbn;
  cout << "Enter ISBN-10 code: ";
  cin >> isbn;

  if (isbn.length() != 10) {
    cout << endl << "<-- Enter 10 digit code -->" << endl << endl;
    return 1;
  }
  isbn.pop_back();

  int arr[11];
  for (int i = 0; i < 9; i++) {
    if (isdigit(isbn[i])) {
      arr[i] = isbn[i] - '0';
    }
  }

  generateCode(arr);

  cout << "ISBN with error correction enabled is: ";
  for (int i : arr) {
    cout << i;
  }
  cout << endl;

  return 0;
}
