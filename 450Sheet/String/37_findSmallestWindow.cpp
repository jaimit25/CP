#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
       string ans = "";
       unordered_map<char, int>m1,m2;
       for(int i =0; i<p.length(); ++i) m1[p[i]]++;
       int n = p.length(),i=0,j=0,c=0;
       while(true){
           bool flag1 = false, flag2= false;
           while(i<s.length() && c<n){
               flag1 =true;
               m2[s[i]]++;
               if(m2[s[i]]<=m1[s[i]]) c++;
               i++;
           }
           while(c==n){
               flag2 = true;
               string temp = s.substr(j,i-j);
               if(ans.length()==0 || temp.length()<ans.length()) ans = temp;
               m2[s[j]]--;
               if(m2[s[j]]<m1[s[j]]) c--;
               j++;
           }
           if(flag1 == false && flag2 == false) break;
       }
       if(ans.length()==0) return "-1";
       return ans;

    }
};

int main()
 {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
	return 0;
}