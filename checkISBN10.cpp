#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

bool checkISBN(int *arr) {
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += ((10 - i) * arr[i]) % 11;
  }
  if (sum % 11 == 0) return true;
  return false;
}

int main() {
  string isbn;
  cout << "Enter ISBN-10 digits: ";
  cin >> isbn;

  int arr[10];
  for (int i = 0; i < 10; i++) {
    if (isbn[i] == 'X') {
      if (i == 9) {
        arr[i] = 10;
      } else {
        cout << "'X' is only allowed as the last character" << endl;
        return 1;
      }
    } else if (isdigit(isbn[i])) {
      arr[i] = isbn[i] - '0';
    } else {
      cout << "Enter valid characters" << endl;
    }
  }

  bool match = checkISBN(arr);
  if (match)
    cout << "ISBN-10 is correct" << endl;
  else
    cout << "ISBN-10 is not correct" << endl;

  return 0;
}
