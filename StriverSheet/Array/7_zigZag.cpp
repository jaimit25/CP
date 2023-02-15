// https://leetcode.com/problems/zigzag-conversion/description/


#include<bits/stdc++.h>
#define ll long long int
#define F first 
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define vs             vector<string>
#define vvi vector<vector<int>>

using namespace std;
 
template<class T>
void print(T &a){
    for(auto it : a){
        cout<<it<<" ";
    }
    cout<<endl;
}

template<class T>
void print2(T &a){
    for(auto it : a){
        for(auto i : it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
}

int getMedian(vi &temps)
{
    int n = temps.size();
    if(n%2 == 0){
        return temps[n/2]+temps[n/2+1];
    }
    return temps[(n/2)];
}

 string convert(string s, int numRows) {

    string ans="";
    int n = s.size();
    vector<string> ss(numRows,"");


    int ind = 0 ;
    int i = 0, j = 0;
    while(ind < n){
        for(int i = 0 ; i < numRows ; i++){
            if(ind >= n) break;
            ss[i] = ss[i] + s[ind];
            ind++;
         }
         cout<<ind<<endl;
         if(ind >= n) break;
        for(int j = numRows-2 ; j > 0 ;j--){
            if(ind >= n) break;
            ss[j] = ss[j] + s[ind];
            ind++;
         }
    }

    for(auto it : ss){
        ans = ans + it;
    }

    return ans;
 }



 
int main()
{



string s = "PAYPALISHIRING";
string ans = convert(s,3);
cout<<ans<<endl;

 
 
return 0;
}
 