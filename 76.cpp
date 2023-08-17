#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 60

string ans(string s,string t){
    int n = s.length();
    int m = t.length();

    vector<int> cnt(N,0);

    for(int i=0;i<m;i++)
        cnt[t[i]-'A']++;
    
    int low = 0;
    int high = 0;

    pii index = mp(0,inf);

    vector<int> condition(N,true);
    int numcond = 0;
    for(int i=0;i<N;i++){
        if(cnt[i]!=0){
            condition[i] = false;
            numcond++;
        }
    }

    vector<int> temp(N,0);
    while(high<n){
        while(high<n&&numcond!=0){
            int ind = s[high]-'A';
            temp[ind]++;
            if(temp[ind]>=cnt[ind]&&!condition[ind]){
                condition[ind]=true;
                numcond--;
            }
            high++;
        }

        if(numcond!=0&&high==n)
            break;
        

        while(low<n&&numcond==0){
            int ind = s[low]-'A';

            temp[ind]--;

            if(temp[ind]<cnt[ind]&&condition[ind]){
                condition[ind]=false;
                numcond++;
            }
        if(high-low-1<(index.second-index.first)){
            index.first = low;
            index.second = high-1;
        }
            low++;
        }
    }

    if(index.second==inf)
        return "";
    
    return s.substr(index.first,index.second-index.first+1);
}

class Solution
{
public:
    string minWindow(string s, string t)
    {
        return ans(s, t);
    }
};