//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
 

        // vector<vector<int>>dis(grid.size() , vector<int>(grid[0].size() , INT_MAX));
        // dis[source.first][source.second] = 1;
        if(source.first == destination.first and source.second == destination.second)
            return 0;
        queue<pair<pair<int , int> , int>>q;
        q.push({{source.first , source.second} , 0});

        vector<pair<int , int>>direction = {{0 , -1} , {-1 , 0} , {1 , 0} , {0 , 1}};

        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(auto &it : direction)
            {
                int r = i+it.first;
                int c = j+it.second;
                if(r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1)
                {
                    grid[r][c] = 0;
                    q.push({{r , c} , d+1});
                    if(r == destination.first and c == destination.second)
                        return d+1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends