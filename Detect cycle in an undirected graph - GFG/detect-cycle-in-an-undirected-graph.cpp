//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int src , vector<bool>&visited , vector<int> adj[])
    {
        queue<pair<int , int>>q;
        q.push({src , -1});
        visited[src] = true;

        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            visited[temp.first] = true;
            for(int &x : adj[temp.first])
            {
                if(x == temp.second and visited[x])
                    continue;
                else if(visited[x] and x!= temp.second)
                    return true;
                else if(!visited[x])
                    q.push({x , temp.first});
            }
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
                if(bfs(i , visited , adj))
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