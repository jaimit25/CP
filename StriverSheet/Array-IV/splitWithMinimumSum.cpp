#include <bits/stdc++.h>
#define F              first
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

int splitNum(int num) {
        
        string s=to_string(num);
        int a=0;
        int b=0;
        sort(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                a=a*10+(s[i]-'0');
            }
            else{
                b=b*10 +(s[i]-'0');
            }
        }
        return a+b;

    }


int main()
{
//type Code

return 0;
}