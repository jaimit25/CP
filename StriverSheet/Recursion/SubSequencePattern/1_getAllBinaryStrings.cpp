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
 



void f(int n , string s, int indx){

	if(n == indx){
		cout<<s<<" ";
		return ;
	}

	f(n,s+'0', indx+1);

	if(indx == 0 || s[indx-1] != '1' ){
		f(n,s+'1',indx+1);
	}
	

}

void generateBinaryStrings(int num){
	string s = "";
        f(num, s, 0);
}


int main()
{

 generateBinaryStrings(3);
 
return 0;
}
 