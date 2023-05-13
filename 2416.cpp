#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

struct trie{
    int count;
    map<char,trie*> mappa;

    trie(){
        this->count=0;
    }
};

void insert(trie* t,string s,int ind){
    if(ind<0){
        t->count++;
        return;
    }

    char c = s[ind];

    if(t->mappa.find(c)==t->mappa.end()){
        t->mappa[c]= new trie();
    }

    int temp = t->count-t->mappa[c]->count;
    insert(t->mappa[c],s,ind-1);
    t->count = temp + t->mappa[c]->count;
    return;
}

void num_prefix(trie* t,string s,int ind,int& sum){
    if(ind<0){
        sum+=t->count;
    }
    
    char c = s[ind];
    if(t->mappa.find(c)==t->mappa.end())
        return;
    
    sum+=t->mappa[c]->count;
    num_prefix(t->mappa[c],s,ind-1,sum);
}


vector<int> ans(vector<string>& words){
    trie* t = new trie();
    int n = words.size();

    for(int i=0;i<n;i++)
        insert(t,words[i],words[i].size());
    
    vector<int> ans;
    int s;

    for(int i=0;i<n;i++){
        s=0;
        num_prefix(t,words[i],words[i].size(),s);
        ans.pb(s);
    }

    return ans;
}

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        return ans(words);
    }
};
