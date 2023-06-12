//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int i , vector<bool>&visited , vector<int> adj[] , vector<bool>&fun_visited)
    {
        visited[i] = true;
        fun_visited[i] = true;
        
        for(int &x : adj[i])
        {
            if(!visited[x] and dfs(x , visited , adj , fun_visited))
                return true;
            else if(fun_visited[x])
                return true;
        }
        fun_visited[i] = false;
        return false;
    }
         
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<bool>visited(V , false);
        vector<bool>fun_visited(V , false);
        for(int i=0; i<V; i++)
        {
            if(!visited[i] and dfs(i , visited , adj , fun_visited))
            {
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends