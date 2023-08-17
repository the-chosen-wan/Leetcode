//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

ll ans(int h){
    vector<ll> dp(h+1,0);
    dp[0]=1;
    dp[1] = 1;
    for(int i=2;i<=h;i++)
        dp[i] = (2*(dp[i-2]*dp[i-1]) + (dp[i-1]*dp[i-1]))%inf;

    return dp[h];
}

class Solution {
  public:
    long long int countBT(int h) { 
        return ans(h);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends