#include <iostream>
#include <string>
using namespace std;

void removeCodes(int *arr) {
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    sum += (i + 1) * arr[i];
  }
  sum %= 11;
  arr[9] = sum, arr[10] = -1;
}

bool checkISBN(int *arr) {
  int sum = 0, sum2 = 0, index = 0;
  for (int i = 0; i < 11; i++) {
    sum += arr[i];
    sum2 += ((i + 1) * arr[i]) % 11;
  }
  sum %= 11, sum2 %= 11;
  if (sum == 0 && sum2 == 0) {
    cout << "ISBN is already correct" << endl;
    removeCodes(arr);
    cout << "The correct ISBN-10 is: ";
    for (int i = 0; i < 10; i++) {
      cout << arr[i];
    }
    cout << endl;
    return false;
  }
  for (int i = 1; i <= 11; i++) {
    if ((sum2 - (sum * i)) % 11 == 0) {
      index = i - 1;
      break;
    }
  }
  arr[index] = arr[index] - sum;
  arr[index] %= 11;
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
    removeCodes(arr);
    cout << "The correct ISBN-10 is: ";
    for (int i : arr) {
      if (i == -1) break;
      cout << i;
    }
    cout << endl;
  }

  return 0;
}
