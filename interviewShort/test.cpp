#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvs vector<vector<string>>
#define vvc vector<vector<char>>
#define vvll vector<vector<long long>>
#define svi set<vector<int>>
#define si set<int>

using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int dt) {
    data = dt;
    next = NULL;
  }
};

template <class T> void print(T &a) {
  for (auto it : a) {
    cout << it << " ";
  }
  cout << endl;
}

template <class T> void print2(T &a) {
  for (auto it : a) {
    for (auto i : it) {
      cout << i << " ";
    }
    cout << endl;
  }
}

void printLL(Node *head) {
  if (!head) {
    cout << "NULL" << endl;
    return;
  }
  // cout<<endl<<"Printing ll..."<<endl;
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}
// append node to linked list
void appendData(Node *root, int dt) {
  Node *head = root;
  if (root) {
    while (head->next) {
      head = head->next;
    }
    head->next = new Node(dt);
  } else {
    root = new Node(dt);
  }
}

// https://leetcode.com/problems/simplify-path/

// void solve(){
//     string path = "/aba//..."  ;
//     stringstream ss(path) ;
//     string temp,res; 
//     vector<string> st;

//     while(getline(ss,temp,'/')){
//         if(temp == "" || temp == ".") continue;
//         if(temp == ".." and !st.empty()) st.pop_back(temp);
//         else if (temp != "..") st.push_back(temp);
//     }
//     for(auto it : st){
//         res =  res+ "/" + it;
//     }
// }

// https://www.geeksforgeeks.org/rearrange-a-linked-list-such-that-all-even-and-odd-positioned-nodes-are-together/
Node *append(Node *root, Node *dt) {
  Node *head = root;
  if (root != NULL) {
    while (head->next) {
      head = head->next;
    }
    head->next = dt;
    dt->next = NULL;
  } else if (root == NULL) {
    root = dt;
  }
  return root;
}
// void solve() {
//   // Created a linked list 1->2->3->4
//   Node *head = append(head, new Node(1));
//   appendData(head, 2);
//   appendData(head, 3);
//   appendData(head, 4);
//   appendData(head, 5);
//   append(head, new Node(6));
//   append(head, new Node(7));
//   append(head, new Node(8));

//   printLL(head);

//   Node *root = head;
//   Node *e = NULL, *o = NULL;

//   while (root) {

//     Node *nd = root;
//     if (root->next)
//       root = root->next;
//     nd->next = NULL;

//     // cout<<"Current node is : "<<nd->data<<endl;

//     if (nd->data % 2 == 0) {
//       // even
//       e = append(e, nd);
//     } else {
//       // odd
//       o = append(o, nd);
//     }
//     if (root->next == NULL)
//       break;
//   }


//   //Extra Work for Last Element
//    Node *nd = root;
//    if (nd->data % 2 == 0) {
//       // even
//       e = append(e, nd);
//     } else {
//       // odd
//       o = append(o, nd);
//     }
   
//   printLL(e);
//   printLL(o);
// }


//To fill array with 0
// void solve(){
//     int arr[10][10]={{0}};
//     fill(arr[0],arr[0]+100,2);
//     for(int i = 0 ; i < 10 ; i++){
//         for(int j = 0 ; j < 10 ; j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


//Graphs
void dfs(vector<int> adj[10], int node,vector<int> &vis){
    cout<<node<<" ";
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(adj,it,vis);
        }
    }
}

// void solve(){

//     //Create Graph - with Edges

//Tst Case 1
// 1 2
// 1 6
// 2 3
// 2 4
// 6 7
// 6 9
// 4 5
// 7 8
// 5 8

//Tst Case 2
// 1 2
// 1 3
// 2 5
// 3 6
// 5 7
// 6 7
// 3 4

//     vector<int> adj[10];
//     for(int i = 0 ; i < 9;i++){
//         int u,v;
//         cin>>u>>v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }


//     //BFS 
//     queue<int> q;
//     vector<int> vis(10,0);
//     q.push(1);
//     vis[1] = 1;

//     while(!q.empty()){
//         int node = q.front();
//         cout<<node<<" ";
//         q.pop();
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 q.push(it);
//                 vis[it] = 1;
//             }
//         }
//     }


//     // DFS
//     vector<int> visit(10,0);
//     cout<<endl;
//     dfs(adj,1,visit);
//     cout<<endl;



//     //Detect Cycle
//     queue<pair<int,int>> qu;
//     qu.push({1,-1});
//     fill(visit.begin(),visit.end(),0);
//     visit[1] = 1 ;

//     while(!qu.empty()){
        
//         int nd = qu.front().first;
//         int p_nd = qu.front().second;
//         qu.pop();

//         for(auto it:adj[nd]){
//             if(!visit[it]){
//                 qu.push({it,nd});
//                 visit[it] = 1;
//             }
//             else if(p_nd != it){
//                 //cycle found
//                 cout<<"Cycle found"<<endl;
//                 return;
//             }
//         }
//     }

// }


//Dijsktras Algorithm
// 0 1 4
// 0 2 4
// 1 2 2
// 2 3 3
// 3 5 2
// 2 5 6
// 2 4 1
// 4 5 3
// void solve(){
//     vector<pair<int,int>> adj[10];

//     for(int i = 0 ; i < 8 ;i++){
//         int u,v,w;
//         cin>>u>>v>>w;
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }

//     //Print Graph
//    // for(int i = 0;  i < 10 ; i++){
//    //  for(auto it : adj[i]){
//    //      cout<<"{"<<it.first<<","<<it.second<<"} "<<" ";
//    //  }
//    //  cout<<endl;
//    // }

//     vector<int> dist(8,1e9);
//     dist[0] = 0;

//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
//     q.push({0,0});

//     while(!q.empty()){

//         int w = q.top().first;
//         int nd = q.top().second;
//         q.pop();

//         for(auto it : adj[nd]){
//             int a_nd = it.first;
//             int w_nd = it.second;
//             if(w+w_nd < dist[a_nd]){
//                 dist[a_nd] = w+w_nd ;
//                 q.push({dist[a_nd],a_nd});
//             }

//         }
//     }

//     print(dist);

// }


void lps(string &s,vector<int> &lps)
{
    int i = 1 ; 
    int j = 0;
    int n = s.size();

    while(i <= n-1){
        if(s[i] == s[j]){
            lps[i] = j+1;
            i++;j++;
        }
        else{
            if(j == 0){
                lps[i] = 0 ;
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }

}

void solve(){

// 0 1 2 3 4 5 6 7
// a b c d a b c a
// 0 0 0 0 1 2 3 1 


    //TO Generate LPS ARRAY
    // string str = "abcdabca";
    // int n = str.size();
    // vector<int> lps_v(n,0);
    // lps(str,lps_v);
    // print(lps_v);
    // string pat = "abc";


    //TO Fing Pattern in text using Lps Array Itself from KMP algorithm
        string text = "jaimit";
        string pat = "jai";
        string temp = pat+'$'+text;
        cout<<temp<<endl;

        vector<int> lps_v(temp.size(),0);
        lps(temp,lps_v);
        print(lps_v);

        for(auto it : lps_v){
            if(it == pat.size()){
                cout<<"found"<<endl;
            }
        }

}


int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  solve();

  return 0;
}

