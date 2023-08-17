#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

vector<int> ans(vector<string>& reqs, vector<vector<string>> people) {
    int r = reqs.size();
    int p = people.size();

    unordered_map<string,int> mappa;

    int cnt = 0;
    for(int i=0;i<r;i++){
        mappa[reqs[i]] = cnt++;
    }

    vector<vector<int>> newpeople;
    unordered_map<int,int> indexmap;
    cnt=0;

    for(int i=0;i<p;i++){
        vector<int> temp;
        int num=0;
        for(string& s:people[i]){
            if(mappa.find(s)!=mappa.end()){
                temp.pb(mappa[s]);
                num++;
            }
        }

        if(num>0){
            newpeople.pb(temp);
            indexmap[cnt]=i;
            cnt++;
        }
    }
    vector<vector<int>> dp(cnt,vector<int>(1<<r,inf));
    vector<int> peopleval;

    for(int i=0;i<cnt;i++){
        int m = 0;
        for(int value:newpeople[i])
            m+=(1<<value);
        peopleval.pb(m);
    }

    auto dfs = [&](int pos,int mask,auto&& dfs)->int{
        cout<<pos<<" "<<mask<<endl;
        if(mask==0){
            if(pos>=0)
                dp[pos][mask]=0;
            return 0;
        }

        if(pos<0)   
            return inf+1;
        
        if(dp[pos][mask]!=inf)
            return dp[pos][mask];
        
        int masker = peopleval[pos];

        if((mask&masker)!=0)
            dp[pos][mask] = min(dfs(pos-1,mask,dfs),1+dfs(pos-1,mask-(mask&masker),dfs));
        else
            dp[pos][mask] = dfs(pos-1,mask,dfs);
        return dp[pos][mask];
    };

    cout<<dfs(cnt-1,(1<<r)-1,dfs)<<endl;
    int mask = (1<<r)-1;
    int pos = cnt-1;
    vector<int> ans;

    while(mask>0&&pos>=0){
        int masker = peopleval[pos];

        if(pos==0){
            if((mask-(mask&masker))==0){
                ans.pb(indexmap[0]);
            }
            break;
        }

        int val1 = dp[pos-1][mask];
        int val2 = 1+dp[pos-1][mask-(mask&masker)];
        if(val2<val1){
            mask = mask-(mask&masker);
            ans.pb(indexmap[pos]);
        }
        pos--;
    }
    return ans;
}

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        return ans(req_skills,people);
    }
};