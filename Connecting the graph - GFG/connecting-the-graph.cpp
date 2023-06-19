//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
  
    int Solve(int n, vector<vector<int>>&connections) 
    {
        if(connections.size() < n-1)
            return -1;
        parent.resize(n);
        rank.resize(n , 0);
        for(int i=0; i<n; i++)
            parent[i] = i;
        for(auto &x : connections)
        {
            if(find(x[0]) != find(x[1]))
            {
                Union(x[0] , x[1]);
                n--;
            }
        }
        return n-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends