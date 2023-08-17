#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using namespace std;
const int inf = (1e9)+7;
#define pb push_back
#define mp make_pair

int ans(string low, string high)
{
    int n1 = low.length();
    int n2 = high.length();
    int N = max(n1, n2);

    vector<int> digits1(N);
    vector<int> digits2(N);

    vector<vector<vector<vector<int>>>> dp(N, vector<vector<vector<int>>>(10, vector<vector<int>>(2, vector<int>(2, -1))));

    for(int i=0;i<N-n1;i++){
        digits1[i]=0;
    }

    for(int i=0;i<N-n2;i++){
        digits2[i]=0;
    }

    for(int i=N-n1;i<N;i++){
        digits1[i] = low[i-N+n1]-'0';
    }
    
    
    for(int i=N-n2;i<N;i++){
        digits2[i] = high[i-N+n2]-'0';
    }

    auto dfs = [&](int pos,int dig,int relax,int zero,vector<int>& digits,auto&& dfs)->int{
        if(pos>=N){
            return 1;
        }
        
        if(dp[pos][dig][relax][zero]!=-1)
            return dp[pos][dig][relax][zero];
        
        ll ret = 0;
        int limit = relax ? 9 : digits[pos];

        if(zero){
            for(int i=0;i<=limit;i++){
                int newrelax = relax ? 1 : i<limit;
                ret = (ret + dfs(pos+1,i,newrelax,i==0,digits,dfs))%inf;
            }
        }
        else{
            if(dig-1>=0&&dig-1<=limit){
                int newrelax = relax ? 1 : dig-1<limit;
                ret = (ret + dfs(pos+1,dig-1,newrelax,0,digits,dfs))%inf;
            }

            if(dig+1>=0&&dig+1<=limit){
                int newrelax = relax ? 1 : dig+1<limit;
                ret = (ret + dfs(pos+1,dig+1,newrelax,0,digits,dfs))%inf;
            }
        }
        dp[pos][dig][relax][zero]=ret;
        return ret;
    };

    ll val1 = dfs(0,0,0,1,digits1,dfs);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++)
                    dp[i][j][k][l]=-1;
            }
        }
    }

    ll val2 = dfs(0,0,0,1,digits2,dfs);
    ll ans = val2-val1;
    
    int isLowValid = 1;
    bool trailing = true;
    
    for(int i=0;i<N;i++){
        if(!trailing){
            if(abs(digits1[i]-digits1[i-1])!=1){
                isLowValid = 0;
                break;
            }
        }
        
        if(digits1[i]!=0)
                trailing=false;
    }
    
    ans = (ans+isLowValid)%inf;
    if(ans<0)
        ans+=inf;
    return ans;
}

class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        return ans(low,high);
    }
};