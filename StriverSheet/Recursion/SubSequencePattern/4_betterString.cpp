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
#define vvi vector<vector<int>>

using namespace std;


// int helper(string &s, string &temp ,int i, set<string> &st ){
        
//         if(i == s.size()){
//         	// cout<<temp<<endl;
//             st.insert(temp);
//             return 0;
//         }
//         temp = temp+s[i];
//         helper(s,temp,i+1,st);

//         temp.pop_back();
//         helper(s,temp,i+1,st);
    
//         return st.size();
// }
    
// string betterString(string str1, string str2) {
//     set<string> st;
//     string temp;
//     int l = helper(str1,temp,0,st);
//     st.clear();
//     temp ="";
//     int r = helper(str2,temp,0,st);


//     if( l > r ) return str1;
//         return str2;
// }


//Approach 2
string betterString(string str1, string str2) {
    //dp solution so omitted
}


using namespace std;
 
 
int main()
{

cout<<betterString("gfg","ggg")<<endl;
 
 
return 0;
}
 