#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll inf = 1e15;
#define pb push_back
#define mp make_pair

int ans(int n,int k){
    vector<int> digits;

    while(n!=0){
        digits.pb(n%10);
        n/=10;
    }

    reverse(digits.begin(),digits.end());
    int N = digits.size();
    vector<vector<vector<int>>> dp(N,vector<vector<int>>(10,vector<int>(2,-1)));

    auto dfs = [&](int ind,int dig,int relax,auto&& dfs)->int{
        if(ind>=N-1){
            if(ind==N-1)
                dp[ind][dig][relax]=1;
            return 1;
        }

        if(dp[ind][dig][relax]!=-1)
            return dp[ind][dig][relax];

        int limit=relax ? 9 : digits[ind+1];

        dp[ind][dig][relax] = 0;
        for(int i=0;i<=limit;i++){
            int newrelax = relax ? 1 : i<limit;

            dp[ind][dig][relax]+=(dfs(ind+1,i,newrelax,dfs));
        }
        return dp[ind][dig][relax];
    };


    for(int i=0;i<=digits[0];i++){
        dfs(0,i,i<digits[0],dfs);
    }

    for(int i=0;i<N;i++)
        dp[i][0][1]--;
    
    int isrelaxed = 0;
    int ans=0;

    for(int i=0;i<N;i++){
        int lower = 0;
        isrelaxed = isrelaxed ? 1 : lower == digits[i];

        int limit = isrelaxed ? 9 : digits[i];

        while(lower<=limit){
            if(dp[i][lower][isrelaxed] == -1)
                dfs(i,lower,isrelaxed,dfs);

            cout<<dp[i][lower][isrelaxed]<<endl;
            if(dp[i][lower][isrelaxed]>=k){
                ans = (ans*10)+lower;
                break;
            }

            else{
                k-=dp[i][lower][isrelaxed];
            }
            lower++;
        }

        isrelaxed = isrelaxed ? 1 : lower == limit;        
    }
    cout<<ans<<endl;
    return ans;
}

int main(){
    int n;int k;cin>>n>>k;
    cout<<ans(n,k);
}