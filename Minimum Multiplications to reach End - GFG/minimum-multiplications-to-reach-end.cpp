//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        queue<pair<int , int>>q;
        q.push({0 , start});
        
        vector<int>distance(100000 , 1e9);
        distance[start] = 0;
        
        int mod = 100000;
        
        while(!q.empty())
        {
            int v = q.front().second;
            int dis = q.front().first;
            q.pop();
            for(int &it : arr)
            {
                int node = (v*it)%mod;
                if(dis+1 < distance[node])
                {
                    distance[node] = dis+1;
                    if(node == end)
                        return dis+1;
                    q.push({dis+1 , node});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends