#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int partition(string s){
    int len = s.length();
    bool dp[len][len];

    for(int i=0;i<len;i++)
        dp[i][0] = true;
    
    for(int i=1;i<len;i++){
        for(int j=0;j<len-i;j++){
            if(i==1){
                if(s[j]==s[j+1])
                    dp[j][i] = true;
                else
                    dp[j][i]=false;
            }
            else{
                if(s[j]==s[j+i])
                    dp[j][i] = dp[j+1][i-2];
                else
                    dp[j][i] = false;
            }

        }
    }

    int mincut[len];mincut[0]=0;

    for(int i=1;i<len;i++){
        int mini=1e9;
        if(dp[0][i]){
            mincut[i] = 0;continue;
        }
        for(int j=0;j<i;j++){
            if(dp[j+1][i-j-1])
                mini = min(mini,mincut[j]);
        }
        mincut[i] = mini+1;
    }

    return mincut[len-1];
}

class Solution
{
public:
    int minCut(string s)
    {
        return partition(s);
    }
};

// int main(){
//     string s;cin>>s;
//     cout<<partition(s)<<endl;
// }