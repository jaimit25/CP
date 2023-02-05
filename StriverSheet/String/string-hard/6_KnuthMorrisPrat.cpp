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
 

void print(vi &a){
	for(auto it : a)
		cout<<it<<" ";

	cout<<endl;
}


void preprocessLps(string &pat, vector<int> &lps){
			int m = pat.size();
	        lps[0] = 0 ; 
            int i = 1 , j = 0 ;
            while(i<= m-1){
            	if(pat[i] == pat[j]){
            		 lps[i] = j+1;
            		 i++;j++;
            	}
            	else{	
            			//if out prefix is at first char or we have just started the checking of prefix == suffix
            			if(j == 0 ) lps[i++]=0 ; // lps of i is 0 and increment i afterwards 
            			else{
            				j = lps[j-1];
            			}
            	}

            }
}

vector <int> search(string &pat, string &txt)
{
           int m = pat.size();
            int n = txt.size();
            vector<int> ans;
            int i,j;

            //preprocess the pattern in LPS(longest common prefix Array)
            vector<int> lps(m,0);
            preprocessLps(pat,lps);

            //Now Finding the Pattern in the string using lps Array
            i = j = 0 ;
             while(i < n){
                if(pat[j] == txt[i]) { i++; j++; }
                if(j == m) { 
                	// we have found the pattern in text since the j pointer which we used to traverse on pattern has reached the end of pattern
                	ans.push_back(i-j+1);   // "+1" because we want one base indexing
                	j = lps[j-1]; // align j pointer to find the next index of the pattern
                }
                else if(i < n  and pat[j] != txt[i]){
                    if(j == 0) { i++; }
                    else{ j = lps[j-1]; }

                }

            }

	return ans;
}

 
int main()
{
 
string t =  "abxabcabcaby";
string p =  "abcaby";

vi ans = search(p,t);
print(ans);




 
return 0;
}
 