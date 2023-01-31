// Input:
// text = gffgfg
// pattern = gfg
// Output: 3 (index 3)
// Explanation:  
// Considering 0-based indexing, substring of text from 3rd to last index is gfg.

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

bool compare(string t, string p, int start) {
  int n = t.size();
  int m = p.size();
  int i = start;
  int j = 0;

  while (i < n && j < m) {

    if (t[i] != p[j])
      return false;
    else {
      i++;
      j++;
    }
  }
  if (j < m)
    return false;
  return true;
}

int findMatching(string text, string pat) {

  int n = text.size();
  int m = pat.size();

  if (m > n)
    return -1;

//get all the index whose value is equal to first char of pattern - for optimization
  vector<int> ind;
  char ch = pat[0];
  for (int i = 0; i < n; i++) {
    if (ch == text[i])
      ind.push_back(i);
  }


//compare the pattern on text using the starting index in "ind" vector. 
  for (auto i : ind) {
    if (compare(text, pat, i)) {
      return i;
    }
  }
  return -1;
}

// Other Approach
// int findMatching(string text, string pat) {
//         if(pat.length()>text.length()){
//             return -1;
//         }
//         for(int i=0;i<text.length()-pat.length()+1;i++){
//             if(pat==text.substr(i,pat.length())){
//                 return i;
//             }
//         }
//         return -1;
//     }


int main() {

  freopen("output.txt", "w", stdout);
  cout << findMatching("gffgfg", "gfg") << endl;
  return 0;
}
