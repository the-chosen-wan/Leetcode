#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define M 25

int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<vector<int>> dp(n,vector<int>(M));

    for(int i=0;i<n;i++)
        dp[i][0] = a[i];
    
    for(int j=1;j<M;j++){
        for(int i=0;i+(1<<j)<=n;i++)
            dp[i][j] = __gcd(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
    }

    int lg[n+1];
    lg[1]=0;
    for(int i=2;i<=n;i++)
        lg[i]=lg[i/2]+1;
    
    auto query = [&](int l,int r)->int{
        int len = lg[r-l+1];
        return __gcd(dp[l][len],dp[r-(1<<len)+1][len]);
    };

    int l,r;cin>>l>>r;
    cout<<query(l,r)<<endl;
    return 0;
}