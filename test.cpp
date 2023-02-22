#include<bits/stdc++.h>
#define ll long long int
#define F first 
#define S              second
#define pb             push_back
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define vs             vector<string>
#define vvi            vector<vector<int>>
#define vvs            vector<vector<string>>
#define vvc            vector<vector<char>>
#define vvll            vector<vector<long long>>
#define svi            set<vector<int>> 
#define si             set <int>





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

bool check(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0; i < 9; i++) 
            if(board[i][col] == c) 
                return false;

        for(int i = 0; i < 9; i++) 
            if(board[row][i] == c) 
                return false;

        int x0 = (row/3) * 3, y0 = (col/3) * 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[x0 + i][y0 + j] == c) return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int r, int c)
    {
        if(r==9)
        return true;
        if(c==9)
        return solve(board, r+1, 0);
        if(board[r][c]!='.')
        return solve(board, r, c+1);
        for(char i='1';i<='9';i++)
        {
            if(check(board, r, c, i))
            {
                board[r][c]=i;
                if(solve(board, r, c+1))
                return true;
                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
 

int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

 
 
return 0;
}
 