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


//graph[][] -  is the Edges Matrix and not the adjacency matrix 
bool isPossible(int node, int col,bool graph[101][101], vector<int> &colored, int n){
    for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && colored[k] == col) {
         return false;
        }
      }
  return true;
   
}

bool help(int node, int m , int n , vector<int> &colored,bool graph[101][101],vector<int> &path){
    
    //base case
    if(node == n){
        return true;
    }

    for(int i = 1 ;i <= m ; i++){
        //is it possible to color current node
        if(isPossible(node,i,graph,colored,n)){
            colored[node] = i ;
            if(help(node+1,m,n,colored,graph,path)){
                return true;
            }
            colored[node] = 0 ;
        }
        

    }
    return false;
}
 
bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colored(n,0);
        vector<int> path;
        return help(0,m,n,colored,graph,path);
}

int main()
{


 int N = 4;
  int m = 3;

  bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);

 
 
return 0;
}
 