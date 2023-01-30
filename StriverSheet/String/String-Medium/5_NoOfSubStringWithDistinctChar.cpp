#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// int checkDistinctChar(string &s) {
//   int n = s.length();
//   set<char> st;
//   for (auto it : s) {
//     st.insert(it);
//   }
//   return st.size();
// }

// long long int substrCount(string s, int k) {
//   long long int count = 0;
//   int n = s.size();

//   for (int i = 0; i < n; i++) {
//     for (int j = i; j < n; j++) {
//       int start = i;
//       int end = j - i + 1;
//       string str = s.substr(start, end);
//       int d_c = checkDistinctChar(str);
//       if (d_c == k)
//         count++;
//     }
//   }
//   return count;
// }


//second most optimized apprach
// long long int substrCount(string s, int k) {

//   int n = s.size();
//   long long int c = 0;
//   int map[26];

//   for (int i = 0; i < n; i++) {
//     int nodc = 0; // no_of_distinct_char_in_cur_substring

//     // Re-Initializing all array map value with frequeuncy with 0
//     memset(map, 0, sizeof(map));

//     // iterate through multiple substring from size (1 to (n-j)) to
//     for (int j = i; j < n; j++) {
//       // mapping current chat value into a Map which is storing the frequency of
//       // that char
//       if (map[s[j] - 'a'] == 0)
//         nodc++;
//       map[s[j] - 'a']++; // increment the freq of current character
//       // if nodc value is greater then k then we dont continue the loop(j)
//       // forward
//       if (nodc == k)
//         c++;
//       if (nodc > k)
//         break;
//     }
//   }
//   return c;
// }

//most optimized approach
// the number of subarrays with at most K distinct elements
int most_k_chars(string& s, int k)
{
    if (s.size() == 0) {
        return 0;
    }
    unordered_map<char, int> map;
    int num = 0, left = 0;
 
    for (int i = 0; i < s.size(); i++) {
        map[s[i]]++;
        while (map.size() > k) {
            map[s[left]]--;
            if (map[s[left]] == 0) {
                map.erase(s[left]);
            }
            left++;
        }
        num = num + i - left + 1;
    }
    return num;
}
 
long long int substrCount(string& s, int k)
{	
    long long int ak =  most_k_chars(s, k);
    long long int ak1 =  most_k_chars(s, k-1);
    cout<<ak<<" "<<ak1<<endl;
    return  ak-ak1;
}



int main() {

  freopen("output.txt", "w", stdout);

  string s = "pqpqs";
  cout << substrCount(s, 2) << endl;

  return 0;
}
