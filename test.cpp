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

 // "ABCB"
 // ["A","B","C","E"]
 // ["S","F","C","S"]
 // ["A","D","E","E"]


//ABCCED
// ["A","B","C","E"]
// ["S","F","C","S"]
// ["A","D","E","E"]


// ABCEFSADEESE - mark visted notes as 0 while back-tracking
// ["A","B","C","E"]
// ["S","F","E","S"]
// ["A","D","E","E"]


bool flag = false;
vector<int> row={-1,0,1,0};
vector<int> col={0,1,0,-1};

bool isPrevLocation(int r, int c , int prevr, int prevc){
    if(r == prevr && c == prevc) return true;
    return false;
}

bool isVisited(int r, int c,vector<vector<int>> &visited){
    if(visited[r][c] == 1) return true;
    return false;
}

void help(int ri, int ci, vector<vector<char>> &board, string &word,int wp,int prevR, int prevC,vector<vector<int>> &visited){

     visited[ri][ci] = 1;
    int m = board[0].size();
    int n = board.size();
    
    if(wp == word.size()){
        flag = true;
        return;
    }

    for(int i = 0 ; i < 4 ;i++){
        int r = ri + row[i];
        int c = ci + col[i];

        
            if(r >= 0 && r < n && c >= 0 && c < m && word[wp] == board[r][c]){
                    if(!isPrevLocation(r,c,prevR,prevC)){
                        if(!isVisited(r,c,visited)){
                            help(r,c,board,word,wp+1,ri,ci,visited);
                            visited[r][c]=0;
                        }
                        
                    }
                    
            }  
        
        
    }

}

bool exist(vector<vector<char>>& board, string word) {

    int m = board[0].size();
    int n = board.size();


    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(word[0] == board[i][j]){
                vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
                help(i,j,board,word,1,-1,-1,visited);
                if(flag) return true;
            }
        }
    }
    return false;
}


 
int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

vvc board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
string word = "ABCCED";

if(exist(board,word)){
    cout<<"Exist";
}
else cout<<"Does not Exist";
 
 
return 0;
}
 