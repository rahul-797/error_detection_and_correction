#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool checkISBN(int *arr) {
  int sum = 0, sum2 = 0, pos = 0;
  for (int i = 0; i < 11; i++) {
    sum += arr[i];
    sum2 += ((i + 1) * arr[i]) % 9;
  }
  sum %= 9, sum2 %= 9;
  if (sum == 0 && sum2 == 0) {
    cout << "ISBN is already correct" << endl;
    return false;
  }
  for (int i = 1; i <= 11; i++) {
    if ((sum2 - (sum * i)) % 9 == 0) {
      pos = i;
      cout << "Error is of: " << sum << endl;
      break;
    }
  }
  arr[pos] -= sum;
  while (arr[pos] < 0) {
    arr[pos] += 9;
  }
  return true;
}

int main() {
  cout << "Enter ISBN code with any single digit altered: ";
  string isbn;
  int arr[11];
  cin >> isbn;

  if (isbn.length() != 11) {
    cout << endl << "ISBN should be 11 digits" << endl << endl;
    return 1;
  }

  for (int i = 0; i < 11; i++) {
    if (isdigit(isbn[i])) {
      arr[i] = isbn[i] - '0';
    } else {
      cout << endl << "Enter valid code" << endl << endl;
      return 1;
    }
  }

  bool changed = checkISBN(arr);
  if (changed) {
    cout << "The correct ISBN-10 is: ";
    for (int i : arr) {
      cout << i;
    }
    cout << endl;
  }

  return 0;
}
