//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int i , vector<bool>&visited , vector<int> adj[] , int parent)
    {
        visited[i] = true;
        
        for(int &x : adj[i])
        {
            if(x != parent and visited[x])
                return true;
            else if(!visited[x] and x != parent and dfs(x , visited , adj , i))
                return true;
        }
        return false;
    }
         
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool>visited(V , false);
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i , visited , adj , -1))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends