//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        unordered_map<int , int>m;
        int mLen = 0;
        int sum = 0;
        
        for(int i=0; i<N; i++)
        {
            sum += A[i];
            if(sum == k)    mLen = max(i+1 , mLen);
            
            // int p = sum - k;
            if(m.find(sum - k) != m.end())    mLen = max(mLen , i - m[sum - k]);
            
            if(m.find(sum)  == m.end())     m[sum] = i;
        }
        return mLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends