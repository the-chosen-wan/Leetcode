#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define N 26
#define pb push_back
#define mp make_pair

int ans(string s)
{
    int n = s.length();
    vector<ll> dp(N, 0);
    ll pref = 0;
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        ll temp = pref;
        pref = (pref - dp[s[i] - 'a'] + pref + 1) % inf;
        dp[s[i] - 'a'] = (temp + 1) % inf;
    }

    for (int i = 0; i < N; i++)
        sum = (sum + dp[i]) % inf;

    if (sum < 0)
        sum += inf;
    return sum;
}

class Solution
{
public:
    int distinctSubseqII(string s)
    {
        return ans(s);
    }
};

int main(){
    string s;cin>>s;
    cout<<ans(s)<<endl;
    return 0;
}