//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(string s,vector<string>& words){
    int n = s.length();
    int w = words.size();
    vector<bool> dp(n,false);

    string res = "";
    unordered_set<string> mappa;

    for(int i=0;i<w;i++)
        mappa.insert(words[i]);

    for(int i=0;i<n;i++){
        res+=s[i];

        if(mappa.find(res)!=mappa.end())
            dp[i] = true;
    }

    if(dp[n-1])
        return true;
    
    for(int i=0;i<n;i++){
        string res = "";

        if(dp[i])
            continue;
        for(int j=i;j>=0;j--){
            res = (s[j]+res);

            if(mappa.find(res)!=mappa.end()&&(j==0?true:dp[j-1])){
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n-1];
}

class Solution {
public:
    int wordBreak(string A, vector<string> &B) {
        return ans(A,B);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends