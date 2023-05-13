#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

string ans(string s){
    int n=s.size();
    string ans;

    for(int i=0;i<n;i++){
        if(s[i]=='*')
            ans.pop_back();
        else
            ans.pb(s[i]);
    }
    return ans;
}

class Solution
{
public:
    string removeStars(string s)
    {
        return ans(s);
    }
};