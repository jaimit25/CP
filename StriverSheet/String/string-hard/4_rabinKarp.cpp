#include <bits/stdc++.h>
#define ll long long int
#define push_back pb
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define vvi vector<vector<int>>

using namespace std;

void print(vi a) {
  for (auto it : a) {
    cout << it << " ";
  }

  cout << endl;
}

int findHash(string &s, int st, int en) {

  int e = en - st + 1; // length of the string s
  e = e - 1;           // initial value of e

  int val = 0; // store the resut of hash Value

  for (int i = st; i <= en; i++) {
    val = val + s[i] * pow(10, e);
    e--;
  }

  return val;
}

int rollingHash(string &s, int current_index, int prevHash, int sz_of_pattern) {
  return ((prevHash - (s[current_index - 1] * pow(10, sz_of_pattern - 1))) *
              10 +
          s[current_index + sz_of_pattern - 1]);

  // End index of the window (current_index + sz_of_pattern - 1 )
}


vector<int> search(string &pat, string &txt) {

  vector<int> ind;

  int sz_of_pattern = pat.size();
  int n = txt.size();

  // hash of the pattern
  int pattern_hash = findHash(pat, 0, sz_of_pattern - 1);

  // hash of first window of the txt
  int prev_hash = findHash(txt, 0, 0 + sz_of_pattern - 1);
  if (prev_hash == pattern_hash)
    ind.push_back(1); // 1 base indexing not 0 base indexing 

  // loop only till the size of window dont overflow the indexes
  for (int i = 1; (i + (sz_of_pattern)-1) < n; i++) {

    // hash of current index pattern
    int curr_hash = rollingHash(txt, i, prev_hash, sz_of_pattern);
    if (curr_hash == pattern_hash)
      ind.push_back(i + 1); // 1 base indexing not 0 base indexing 
    prev_hash = curr_hash;
  }
  if (ind.size() == 0)
    ind.push_back(-1);

  return ind;
}

int main() {

  freopen("output.txt", "w", stdout);

  //   string t = "aabaaca";
  //   string p = "baa";

  //   string t = "abesdu";
  //   string p = "edu";
  //   cout << findHash(p, 0, 2) << endl;

//   string t = "batmanandrobinarebat";
//   string p = "bat";


  string t = "igznzxtzqsjwatycbmjawwmninepfduplucltxmkpvgrrgtuseurageltkcapwpbqromqawixezqkvlfbhwcocpjmrmbpbegvsuluqtuuvkesvjtdhvtjmexfqbvufdpaxcwnwqjtbplyzedicwsodpwtqrpyuearhwgfnpaqelofrsotqiktxipqzeqvlqmuoubbjbrpmixfclbstnosvdkujcpwsdqhxrkiueziowoqjpiecwxxbjtnmkjgncpmvauqgtausokbfugjtfiuqbjclvlazamucimicnewdoxjlfuemdadgkhufsuevjaxrnivcorhfrqqwnujquoyevslqprlyskrhunljgsoxleuyyfqutozqhmgyetyyepfaesjlkzivdevdllygazxjndjrxhrdyyddqnqdoayshwxshxzjywumbffamxdnxj";
  string p = "qo";
  cout<<t[155]<<t[156]<<endl;

//   vi ans = search(p, t);
//   print(ans);

  return 0;
}
