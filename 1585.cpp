#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool transform(string s, string t){

    int len = s.length();
    vector<vector<int>> pref;
    pref.resize(len,vector<int>(10,0));

    vector<vector<int>> pos(10);
    vector<vector<int>> spos(10);

    for(int i=0;i<len;i++){
        pos[t[i]-'0'].pb(i);
        spos[s[i]-'0'].pb(i);
        pref[i][s[i]-'0'] = pref[i-1][s[i]-'0'] + 1;
    }

    for(int i=0;i<10;i++){
        if(spos[i].size()!=pos[i].size())
            return false;
        
        for(int j=0;j<pos[i].size();j++){
            int start = spos[i][j];
            int end = pos[i][j];
            int s_start = s[end] - '0';

            if(end>start)
                return false;
            
            for(int l=0;l<i;l++){
                if(pref[start][l] - pref[end-1][l]>0)
                    return false;
            }

            for(int k=end+1;k<=start;k++)
                pref[k][s_start]++;

            for(int k=start-1;k>=end;k--)
                pref[k][i]--;
        }
    }
    return true;
}

class Solution
{
public:
    bool isTransformable(string s, string t)
    {
        return transform(s,t);
    }
};
