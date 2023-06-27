//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        vector<int>zero;
        vector<int>one;
        vector<int>two;
        
        for(int i=0; i<n; i++)
            if(a[i] == 0)   zero.push_back(0);
            else if(a[i] == 1)    one.push_back(1);
            else    two.push_back(2);
        
        int i = 0;
        for(int &x : zero)  a[i++] = 0;
        for(int &x : one)   a[i++] = 1;
        for(int &x : two)   a[i++] = 2;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends