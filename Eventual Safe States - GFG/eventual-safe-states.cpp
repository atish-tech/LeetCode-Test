//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) 
    {
        // setup
        vector<int>adj[V];
        for(int i=0; i<V; i++)
            for(int &v : graph[i])
                adj[v].push_back(i);

        vector<int>indegree(V , 0);
        for(int i=0; i<V; i++)
            for(int &v : adj[i])
                indegree[v] += 1;
        queue<int>q;
        for(int i=0; i<V; i++)
            if(indegree[i] == 0)
                q.push(i);
        // logic
        vector<int>ans;
        while(!q.empty())
        {
            int i = q.front();
            ans.push_back(i);
            q.pop();
            for(int &v : adj[i])
            {
                indegree[v] -= 1;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends