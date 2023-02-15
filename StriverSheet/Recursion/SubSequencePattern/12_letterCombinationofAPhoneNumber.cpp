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

 void fun(string digits,vector<string> str,vector<string> &ans,int n,int i,string temp)
{
    if(i>n)
        return ;
    if(i==n)
    {
        ans.push_back(temp);
        return ;
    }
    int ind = (digits[i]-'0');
    for(char s : str[ind])
        fun(digits,str,ans,n,i+1,temp+s);
}
vector<string> letterCombinations(string digits) 
{
    if(digits == "")
        return {};
    vector<string> str,ans;
    str={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n=digits.size();
    fun(digits,str,ans,n,0,"");
    return ans;
}


   
  int main()
  {
  
   
  return 0;
  }
     