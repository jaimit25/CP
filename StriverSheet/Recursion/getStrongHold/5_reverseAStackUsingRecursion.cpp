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
 
int printStack(stack<int> &s1)
{
    if(s1.empty())
        return -1;

    cout<<s1.top()<<" ";
    int temp=s1.top();
    s1.pop();

    printStack(s1);
    s1.push(temp);

    return 0;
}

 void pushAtBottom(stack<int> &S,int x){
        if(S.empty()){
            S.push(x);
            return;
        }
        
        int num = S.top();
        S.pop();
        
        pushAtBottom(S, x);
        
        S.push(num);
    }
    
void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        
        int num = St.top();
        St.pop();
        
        Reverse(St);
        
        pushAtBottom(St, num);
   }

int main()
{

    freopen("output.txt","w",stdout);
    stack<int> s ;
 
    s.push(11);
    s.push(2);
    s.push(32);
    s.push(3);
    s.push(41);
    printStack(s);
    Reverse(s);

    cout<<endl<<"stack after reverse : "<<endl;
    Reverse(s);
    printStack(s);
}