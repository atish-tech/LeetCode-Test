//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<pair<int , int>> adj[n];
        for(int i=0; i<flights.size(); i++)
            adj[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        
        queue<pair<int , pair<int , int>>>q;
        q.push({0 , {src , 0}});

        vector<int>distance(n , INT_MAX);

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int v = it.second.first;
            int w = it.second.second;
            for(auto &u : adj[v])
            {
                if(stop > k)
                    continue;
                if(u.second+w < distance[u.first])
                {
                    distance[u.first] = u.second + w;
                    q.push({stop+1 , {u.first , u.second+w}});
                }
            }
        }    

        if(distance[dst] == INT_MAX)
            return -1;
        return distance[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends