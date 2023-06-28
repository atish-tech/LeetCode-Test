//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> nums){
        int val = -1;
        for(int i=nums.size()-2; i >= 0; i--)
            if(nums[i] < nums[i+1])
            {
                val = i;
                break;
            }    
        if(val == -1)
        {
            reverse(nums.begin() , nums.end());
            return nums;
        }
        
        for(int i = nums.size()-1; i > val; i--)
            if(nums[i] > nums[val])
            {
                swap(nums[val] , nums[i]);
                break;
            }
        reverse(nums.begin() + val+1 , nums.end());
        return nums;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends