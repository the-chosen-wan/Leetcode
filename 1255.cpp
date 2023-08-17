#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
const int N = 26;

int ans(vector<string>& words, vector<char>& letters, vector<int>& score) {
    int w = words.size();
    int l = letters.size();

    vector<int> cnt(N,0);

    for(int i=0;i<l;i++)
        cnt[letters[i]-'a']++;
    
    vector<int> dp(1<<w,-1);

    auto getScore = [&](vector<int>& charCnt)->int{
        int amt = 0;

        for(int i=0;i<N;i++){
            if(cnt[i]<charCnt[i]){
                return -1;
            }
        }

        for(int i=0;i<N;i++){
            cnt[i]-=charCnt[i];
            amt+=(charCnt[i]*score[i]);
        }
        return amt;
    };

    auto reverse = [&](vector<int>& charCnt)->void{
        for(int i=0;i<N;i++)
            cnt[i]+=charCnt[i];
        return;
    };

    auto dfs = [&](int mask,auto&& dfs)->int{
        if(mask==0){
            dp[0]=0;
            return 0;
        }

        if(dp[mask]!=-1)
            return dp[mask];

        int val = 0;
        for(int i=0;i<w;i++){
            if((mask&(1<<i))){
                vector<int> charCnt(N,0);
                int len = words[i].length();
                for(int j=0;j<len;j++){
                    charCnt[words[i][j]-'a']++;
                }

                int check = getScore(charCnt);

                if(check!=-1){
                    val = max(val,check+dfs(mask^(1<<i),dfs));
                    reverse(charCnt);
                }

                // val = max(val,dfs(mask^(1<<i),dfs));
                
            }
        }
        cout<<mask<<" "<<val<<endl;
        dp[mask]=val;
        return val;
    };

    return dfs((1<<w)-1,dfs);
}

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        return ans(words,letters,score);
    }
};