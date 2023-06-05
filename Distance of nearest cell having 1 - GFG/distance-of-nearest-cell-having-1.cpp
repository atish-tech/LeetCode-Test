//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    // int fun(vector<vector<int>>grid , queue<pair<pair<int , int> , int>>&q)
    // {
    //     while(!q.empty())
    //     {
    //         auto temp = q.front();
    //         int i = temp.first.first;
    //         int j = temp.first.second;
    //         int count = temp.second;
    //         q.pop();
            
    //         if(i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size())
    //             continue;
    //         if(grid[i][j] == 1)
    //             return count;
    //         q.push({{i+1 , j} , count+1});
    //         q.push({{i-1 , j} , count+1});
    //         q.push({{i , j+1} , count+1});
    //         q.push({{i , j-1} , count+1});
            
    //     }
    // }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<pair<int , int> , int>>q;
	    vector<vector<bool>>visited(grid.size() , vector<bool>(grid[0].size() , false));
	    vector<vector<int>>ans(grid.size() , vector<int>(grid[0].size()));
	    
	    for(int i=0; i<grid.size(); i++)
	        for(int j=0; j<grid[0].size(); j++)
	            if(grid[i][j] == 1)
	                q.push({{i , j} , 0});
	                
        while(!q.empty())
        {
            auto temp = q.front();
            int i = temp.first.first;
            int j = temp.first.second;
            int count = temp.second;
            q.pop();
            if(i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size())
                continue;
            if(!visited[i][j])
            {
                ans[i][j] = count;
                // cout<<count<<"  ";
                visited[i][j] = true;
                q.push({{i+1 , j} , count+1});
                q.push({{i-1 , j} , count+1});
                q.push({{i , j+1} , count+1});
                q.push({{i , j-1} , count+1});
            }
            
        }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends