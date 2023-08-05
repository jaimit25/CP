
//check if Array 1 is subset of Another Array

#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void solve()
{
	vi arr1 = {6,7,3,2};
    vi arr2 = {2,3};
    set<int> s;
    for(auto it : arr1)
    	s.insert(it);

   	for(auto it : arr2){
   		if(s.find(it) == s.end()){
   			cout<<"Array 2 is not Subset of Array 1";
   			return ;
   		}
   	}

   	cout<<"Array 1 is Subset of Array 2";

}
 
int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

solve();
 
return 0;
}



