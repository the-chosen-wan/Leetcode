#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

struct trie{
    map<char,trie*> edge;
    char c;
    trie(char c){
        this->c = c;
    }
};

void insert(trie* t,string s,int pos){
    if(pos==s.length())
        return;
    if(t->edge.find(s[pos])!=t->edge.end())
        insert(t->edge[s[pos]],s,pos+1);
    else{
        t->edge[s[pos]] = new trie(s[pos]);
        insert(t->edge[s[pos]],s,pos+1);
    }
}

bool search(trie* t,string s,int pos){
    if(pos==s.length())
        return true;
    if(t->edge.find(s[pos])!=t->edge.end())
        return search(t->edge[s[pos]],s,pos+1);
    else
        return false;
}

void insert_substr(trie* t,string s){
    int l = s.length();
    for(int i=0;i<l;i++)
        for(int j=i+1;j<=l;j++)
            insert(t,s.substr(i,j)+"$",0);
    return;
}

vector<string> ans(vector<vector<char>>& board, vector<string>& words){
    int n = board.size();
    int m = board[0].size();
    trie* t = new trie('1');

    string temp;
    // for(int i=0;i<n;i++){
    //     temp = string(board[i].begin(),board[i].end());
    //     insert_substr(t,temp);
    //     reverse(temp.begin(),temp.end());
    //     insert_substr(t,temp);
    // }

    // for(int i=0;i<m;i++){
    //     vector<char> c;
    //     for(int j=0;j<n;j++)
    //         c.pb(board[j][i]);
    //     temp = string(c.begin(),c.end());
    //     insert_substr(t, temp);
    //     reverse(temp.begin(), temp.end());
    //     insert_substr(t, temp);
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vector<char> temp1;
            vector<char> temp2;
            for(int k=0;k<=i;k++)
                temp2.pb(board[k][j]);
            for(int k=j+1;k<m;k++)
                temp2.pb(board[i][k]);
            for(int k=0;k<=j;k++)
                temp1.pb(board[i][k]);
            for(int k=i+1;k<n;k++)
                temp1.pb(board[k][j]);
            temp = string(temp1.begin(),temp1.end());
            insert_substr(t, temp);
            reverse(temp.begin(), temp.end());
            insert_substr(t, temp);
            temp = string(temp2.begin(),temp2.end());
            insert_substr(t, temp);
            reverse(temp.begin(), temp.end());
            insert_substr(t, temp);
        }
    }

    vector<string> ans;
    for(string val:words)
        if(search(t,val,0))
            ans.pb(val);
    return ans;
}

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        return ans(board,words);
    }
};
