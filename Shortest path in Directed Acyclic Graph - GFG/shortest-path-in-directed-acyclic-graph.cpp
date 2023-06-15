//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int in_degree[V] = {0};
	    vector<int>ans;
	    // traversal
	    for(int i=0; i<V; i++)
	    {
	        for(int &x : adj[i])
	            in_degree[x] += 1;
	    }
	    
	    queue<int>q;
	    for(int i=0; i<V; i++)
	        if(in_degree[i] == 0)
	            q.push(i);
	   
	   while(!q.empty())
	   {
	       int v = q.front();
	       q.pop();
	       ans.push_back(v);
	       for(int &u : adj[v])
	       {
	           in_degree[u] -= 1;
	           if(in_degree[u] == 0)
	                q.push(u);
	       }
	   }
	   return ans;
	}
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        // setup adj list
        vector<pair<int , int>> adj[N];
        vector<int>tempAdj[N];
        for(int i=0; i<M; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            tempAdj[edges[i][0]].push_back(edges[i][i]);
        }
        
        
        // vector<int>topo = topoSort(N , tempAdj);
        
        vector<int>distance(N , INT_MAX);
        distance[0] = 0;
        queue<pair<int , int>>q;
        q.push({0 , 0});
        
        while(!q.empty())
        {
            int v = q.front().first;
            int dis = q.front().second;
            q.pop();
            for(auto &it : adj[v])
            {
                if(distance[it.first] > it.second + dis)
                {
                    distance[it.first] = it.second + dis;
                    q.push({it.first , distance[it.first]});
                }
            }
        }
                
        for(int i=0; i<N; i++)
        {
            if(distance[i] == INT_MAX)
                distance[i] = -1;
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends