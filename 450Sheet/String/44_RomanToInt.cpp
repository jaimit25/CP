#include <bits/stdc++.h>
#include <string>

using namespace std;

int getCharValue(char c) {

  switch (c) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  }
  return -1;
}

int romanToInt(string &s) {
  int n = s.length();
  cout << n << endl;
  if (n == 0)
    return -1;

  int val = 0;
  for (int i = 0; i < n; i++) {

    if (i == n - 1)
      return (val + getCharValue(s[i]));
    int c = getCharValue(s[i]);
    int n_c = getCharValue(s[i + 1]); // next character value

    if (c < n_c)
      val = val - c;
    else if (c > n_c)
      val = val + c;
    else
      val = val + c;

    // cout << val << endl;
  }

  return val;
}

int main(int argc, char *argv[]) {
  string r = "CMXCVIII";
  cout << romanToInt(r) << endl;
}
