#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	//     int indg[V]= {0};
	    int *indg =  new int[V];
	    
	    
	    // setting in-degree of all the element
	    for(int i = 0 ; i < V;i++){
	        for(auto it : adj[i]){
	            indg[it]++;
	        }
	    }
	    
	    vector<int> topo_sort;
         queue<int> q;
         
         
        //pushing all the element with indegree 0 into the queue
         for(int i = 0 ; i < V ; i++){
	        if(indg[i] == 0 ){
	               q.push(i);
	        }
         }
         
         while(!q.empty()){
            int node = q.front();
            q.pop();
            topo_sort.push_back(node);
            
            for(auto it : adj[node]){
                indg[it]--;
                if(indg[it] == 0  )  q.push(it);
                
            }
            
         }
         
        return topo_sort; 
	    
	    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends