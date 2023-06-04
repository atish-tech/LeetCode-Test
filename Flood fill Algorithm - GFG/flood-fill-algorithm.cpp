//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void f(int sr , int sc , vector<vector<int>>& image , int color , int value , queue<pair<int , int>>&q)
    {
        if(sr < 0 or sr >= image.size() or sc < 0 or sc >= image[0].size() or 
        image[sr][sc] != value or image[sr][sc] == color)
            return;

        image[sr][sc] = color;
        q.push({sr , sc});
        // cout<<sr<<"  "<<sc<<endl;
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, 
    int color) 
    {
        queue<pair<int , int>>q;  
        q.push({sr , sc});
        int value = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int sr = temp.first;
            int sc = temp.second;
            f(sr+1 , sc , image , color , value , q);
            f(sr , sc+1 , image , color , value , q);
            f(sr-1 , sc , image , color , value , q);
            f(sr , sc-1 , image , color , value , q);
        } 
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends