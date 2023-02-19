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



bool flag = false;
vector<int> row={-1,0,1,0};
vector<int> col={0,1,0,-1};
vector<char> dir = {'U','R','D','L'};


bool isVisited(vector<vector<int>> &visited,int r, int c){
    if(visited[r][c] == 1) return true;
    return false;
}

void help(vector<vector<int >> &mat, int ri , int ci, string &path, vector<string> &ans,vector<vector<int>> &visited){
     visited[ri][ci] = 1 ;
    int n = mat.size();
    int m = mat[0].size();

    if(ri == n-1 && ci == m-1 ){
        ans.push_back(path);
        return; 
    }

    for(int k = 0; k < 4 ; k++){
        
        int r = ri + row[k];
        int c = ci + col[k];
        char d = dir[k];

        if(r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == 1){
            if(!isVisited(visited,r,c)){
             
                path = path + d;
                help(mat,r,c,path,ans,visited);
                path.pop_back();
                visited[r][c] = 0 ;
            }
        }   
    }

    return;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
               vector<string> ans;
               if(m[0][0] == 0 ) return ans;
               
               
               vector<vector<int>> visited(n,(vector<int>(n,0)));
               string path ="";
               help(m,0,0,path,ans,visited);
               return ans;
}
 


int main()
{

vector<vector<int>> m=  {{1, 0, 0, 0},
                         {1, 1, 0, 1}, 
                         {1, 1, 0, 0},
                         {0, 1, 1, 1}};

vs ans = findPath(m,m.size());
print(ans);


 
return 0;
}



 