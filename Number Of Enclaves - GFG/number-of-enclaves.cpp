//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    //dfs to convert all 1's in 0's in 4 directions
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid) {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0) return;
        grid[i][j]=0;
        dfs(i+1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j-1,n,m,grid);
    }
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //using dfs in row and column to convert all 1's that connected to boundry 1's;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) dfs(i,0,n,m,grid);
            if(grid[i][m-1]==1) dfs(i,m-1,n,m,grid);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1) dfs(0,i,n,m,grid);
            if(grid[n-1][i]==1) dfs(n-1,i,n,m,grid);
        }
        //now couniting 1's in middle if available
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends