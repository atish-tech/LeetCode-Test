//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string , int>>q;
        unordered_set<string>s(wordList.begin() , wordList.end());
        q.push({beginWord , 1});

        while(!q.empty())
        {
            string str = q.front().first;
            int count = q.front().second;
            q.pop();
            if(str == endWord)
                return count;
            for(int i=0; i<str.length(); i++)
            {
                char original = str[i];
                for(char x = 'a'; x <= 'z'; x++)
                {
                    str[i] = x;
                    if(s.find(str) != s.end())
                    {
                        q.push({str , count+1});
                        s.erase(str);
                    }
                }
                str[i] = original;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends