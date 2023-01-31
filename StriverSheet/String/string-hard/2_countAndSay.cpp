#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

string countAndSay(int n) {
  if (n == 1)
    return "1";
  string ans = "1";

  for (int i = 2; i <= n; i++) {
    string temp = ans;
    ans = "";

    int c = 0;// count variable
    char num = temp[0]; // current number which we will count
    for (auto it : temp) {
      if (it != num) {
        ans = ans + to_string(c) + num;
        num = it;
        c = 1; // num has changed so again start counting, for current index we
               // will count the value so
        // c = 1; and not 0
      } else
        c++;
    }
    ans = ans + to_string(c) + num;
  }
  return ans;
}

int main() {



  cout << countAndSay(4) << endl;

  return 0;
}
