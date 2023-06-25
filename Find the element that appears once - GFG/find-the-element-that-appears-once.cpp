//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int nums[], int N)
	{
	    
	    if(N == 1)    return nums[0]; //
        sort(nums , nums+N);
        if(nums[0] != nums[1])  return nums[0];
        int i = 1;
        for(i; i<N - 1; i++)
        {
            if(nums[i] == nums[i-1] or nums[i] == nums[i+1])    continue;
            break;
        }  
        // if(i+1 == N)  return nums[i+1];
        return nums[i];    
	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends