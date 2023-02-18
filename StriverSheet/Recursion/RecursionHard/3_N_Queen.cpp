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

void printBoard(vector<string> &board){
    for(auto it : board){
        cout<<it<<endl;
    }
}


vector<string> getBoard(int n){
         vector<string> board;
        for(int i = 0 ; i < n ; i++){
           string temp="";
           for(int j = 0 ; j < n ; j++){
                temp += ".";
           }
           board.push_back(temp);
        }
        return board;
}

bool isAttacked(vector<string> &board, int i , int j){
    int m = board[0].size();
    int n = board.size();

        int r,c;

        //checking col, if there is any queen in that column
        for(int c = 0; c < n ; c++){
            if(board[i][c] == 'Q') return true;
        }

        //checking row, if there is any queen in that column
        for(int r = 0; r < n ; r++){
             if(board[r][j] == 'Q') return true;
        }
          

        //check top-left
        for(r = i , c = j ; r>=0 && c>=0 ;r--,c--){
            if(board[r][c]=='Q') return true;
        }

        //check top-right
        for(r = i , c = j ; r >= 0 && c < m ;r--,c++){
                 if(board[r][c]=='Q') return true;
        }
        

        //check bottom-left 
        for(r = i , c = j ; r < n && c >= 0 ;r++,c--){
             if(board[r][c]=='Q') return true;
        }

        //check bottom-right
        for(r = i , c = j ; r < n && c < m ;r++,c++){
             if(board[r][c]=='Q') return true;
        }


    return false;
}


void fun(vector<string> &board, int i, vector<vector<string>> &ans,int n){
    
    if(i == board.size()){
        ans.push_back(board);
        return ; 
    }

    for(int j = 0 ; j < n ; j++){
        if(!isAttacked(board,i,j)){
            board[i][j] = 'Q';
            fun(board,i+1,ans,n);
            board[i][j] = '.';
        }
    }

}


vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> board = getBoard(n);
        // printBoard(board);
        fun(board,0,ans,n);


        return ans;
}

 
int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

vvs ans = solveNQueens(4);
cout<<ans.size()<<endl;
print2(ans);
 
return 0;
}
 