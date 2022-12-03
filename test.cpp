#include <bits/stdc++.h>
#include <string>
using namespace std;

void printv(vector<int> v) {
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;
  return;
}

 int getfac(int n){
        int ans = 1; 
        for(int i = 1; i <= n ; i++){
            ans = ans*i;
        }
        return ans;
    }
    


// void printSub(int i, vector<int> &vec, vector<int> &seq) {
//   if (i >= vec.size()) {

//     printv(seq);
//     // seq.clear();
//     return;
//   }

//   seq.push_back(vec[i]);
//   printSub(i + 1, vec, seq);

//   seq.pop_back();
//   printSub(i + 1, vec, seq);
// }


// int getMaximumGenerated(int n) {
//         if(n == 0) return 0;
//         if(n == 1 ) return 1;
//         vector<int> v(n+1);
//         v[0] = 0 ; 
//         v[1] = 1 ;
        
//         int mx = INT_MIN;
//         int temp = 0 ;
//         for(int i = 1 ; i <= n ; i++){
            
//             int l = 2*i;
//             int k = l+1;
            
//             //out of bound
//             if(l > n) break;
//             v[l] = v[i];
//             mx = max(v[l],mx);
            
//             //out of bound
//             if(k > n) break;
//             v[k] = v[i] + v[i+1];
//             mx = max(v[k],mx);
//         }
//         return mx;
        
//     }

// int f(int i,vector<int> &cost){
//         int n = cost.size();
//         //base case
//         if( i == n-1 || i == n-2) return 0;
        
//         int one_stp = cost[i] + f(i+1,cost);
        
//         int two_stp = INT_MAX;
//         if(i+2 < cost.size()){
//              two_stp = cost[i] + f(i+2,cost);
//         }        
            
//         return min(one_stp,two_stp);        
// }
    
// int minCostClimbingStairs(vector<int>& cost) {
//        int i = 0 ;
//         if(cost[0] < cost[1]){
//            i = 0 ;
//         }
//         else i = 1 ;
//          cout<<"i : "<<i<<endl;
//         return f(i,cost);
// }

vector<int> getRow(int n) {
      vector<int> temp(n+1),v(n+1);
      temp[0] = 1;

       
    
      
    }

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

// cout<<getMaximumGenerated(7)<<endl;
// vector<int> v = {10,15,20};
// cout<<minCostClimbingStairs(v)<<endl;

vector<int > ans  = getRow(14);
printv(ans);



  return 0;
}
