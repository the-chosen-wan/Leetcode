#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define C 26

ll count(vector<string>& idea){
    vector<ll> indeg(C,0);
    vector<ll> outdeg(C,0);
    unordered_set<string> hash;
    for(int i=0;i<idea.size();i++)
        hash.insert(idea[i]);

    for(int i=0;i<idea.size();i++){
        string temp = idea[i];
        char c = idea[i][0];
        indeg[c-'a']++;
        for(int j=0;j<C;j++){
            if(j==c-'a')
                continue;
            idea[i][0] = j+'a';
            if(hash.find(idea[i])!=hash.end())
                outdeg[j]++;
        }
        idea[i]=temp;
    }

    ll doub = 0;
    for(int i=0;i<idea.size();i++){
        char c = idea[i][0];
        for(int j=0;j<C;j++){
            if(j==c-'a')
                continue;
            idea[i][0] = j+'a';
            if(hash.find(idea[i])!=hash.end())
        }
    }

    ll remov = 0;
    for(int i=0;i<C;i++)
        {remov+=2*(indeg[i]*outdeg[i]);remov+=(indeg[i])*(indeg[i]-1);}
    return (idea.size())*(idea.size()-1) - remov;
}

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        return count(ideas);
    }
};