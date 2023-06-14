//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
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
    string findOrder(string dict[], int N, int K) 
    {
        vector<int> adj[K];
        for(int i=1; i<N; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i-1];
            int t = min(s1.length() , s2.length());
            for(int i=0; i<t; i++)
            {
                if(s1[i] != s2[i])
                {
                    adj[s2[i] - 'a'].push_back(s1[i] - 'a');
                    break;
                }
            }
        }
        
        string str = "";
        vector<int>data = topoSort(K , adj);
        for(int &i : data)
        {
            str += char(i + 'a');
        }
        return str;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends