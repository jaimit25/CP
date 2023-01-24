

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define length 10

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &num, int target) {
    vector<vector<int>> res;

    if (num.empty())
      return res;
    int n = num.size();
    sort(num.begin(), num.end());

    for (int i = 0; i < n; i++) {

      int target_3 = target - num[i];

      for (int j = i + 1; j < n; j++) {

        int target_2 = target_3 - num[j];

        int front = j + 1;
        int back = n - 1;

        while (front < back) {

          int two_sum = num[front] + num[back];

          if (two_sum < target_2)
            front++;

          else if (two_sum > target_2)
            back--;

          else {

            vector<int> quadruplet(4, 0);
            quadruplet[0] = num[i];
            quadruplet[1] = num[j];
            quadruplet[2] = num[front];
            quadruplet[3] = num[back];
            res.push_back(quadruplet);

            // Processing the duplicates of number 3
            while (front < back && num[front] == quadruplet[2])
              ++front;

            // Processing the duplicates of number 4
            while (front < back && num[back] == quadruplet[3])
              --back;
          }
        }

        // Processing the duplicates of number 2
        while (j + 1 < n && num[j + 1] == num[j])
          ++j;
      }

      // Processing the duplicates of number 1
      while (i + 1 < n && num[i + 1] == num[i])
        ++i;
    }

    return res;
  }
};

int main() {
  Solution obj;
  vector<int> v{1, 0, -1, 0, -2, 2};

  vector<vector<int>> sum = obj.fourSum(v, 0);
  cout << "The unique quadruplets are" << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }

  return 0;
}