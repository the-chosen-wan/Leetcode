#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int count_pali(string s){
    int len = s.length();
    if(len==0)
        return 0;
    
    int dp[len][len];
    for(int i=0;i<len;i++)
        dp[i][0]=1;

    for(int i=1;i<len;i++){
        for(int j=0;j<len-i;j++){
            if(s[j]!=s[j+i])
                dp[j][i] = 0;
            else 
                dp[j][i] = i==1?1:dp[j+1][i-2];
        }
    }

    int c=0;
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i;j++){
            c+=dp[j][i];
        }
    }

    return c;  
}

// int main(){
//     string s;cin>>s;
//     cout<<count_pali(s)<<endl;
// }

class Solution
{
public:
    int countSubstrings(string s)
    {
        return count_pali(s);
    }
};