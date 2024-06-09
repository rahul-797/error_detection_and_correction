#include <iostream>
#include <string>
using namespace std;

bool generateCode(string& isbn) {
  int sum = 0, sum2 = 0;
  for (int i = 0; i < 9; i++) {
    sum += (isbn[i] - '0');
    sum2 += (i + 1) * (isbn[i] - '0');
  }
  sum %= 11, sum2 %= 11;

  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < 11; j++) {
      if (((sum + i + j) % 11 == 0) &&
          ((sum2 + (10 * i) + (11 * j)) % 11 == 0)) {
        (i == 10) ? isbn.append("X") : isbn.append(to_string(i));
        (j == 10) ? isbn.append("X") : isbn.append(to_string(j));
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

  for (int i = 0; i < 9; i++) {
    if (!isdigit(isbn[i])) {
      cout << endl << "Enter valid ISBN-10" << endl;
      return 1;
    }
  }

  generateCode(isbn);

  cout << "ISBN with error correction enabled is: " << isbn << endl;

  return 0;
}
