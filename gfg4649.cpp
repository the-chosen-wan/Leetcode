#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair
const int N = 26;

string ans(string s){
    vector<int> cnt(N,0);

    int n = s.length();

    for(int i=0;i<n;i++)
        cnt[s[i]-'a']++;
    
    bool allowed = true;

    int free = (n+1)/2;

    sort(cnt.begin(),cnt.end(),greater<int>());
    for(int i=0;i<N;i++){
        if(cnt[i]==0)
            break;
        
        if(cnt[i]>free){
            allowed = false;
            break;
        }

        n-=cnt[i];
        free = (n+1)/2;
    }

    if(allowed) 
        return "1";
    return "0";
}

class Solution
{
    public:
    string rearrangeString(string str)
    {
        return ans(str);
    }
    
};