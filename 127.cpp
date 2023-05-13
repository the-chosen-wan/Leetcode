#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;

int getsame(string &s1, string &s2)
{
    int c = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[i])
            c++;
    }
    return c;
}

void bfs(int src,vector<vector<int>>& adj,vector<bool>& visited, vector<int>& dist){
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    visited[src]=true;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        visited[t]=true;
        for(int k:adj[t]){
            if(!visited[k]){
                dist[k] = dist[t]+1;
                q.push(k);
            }
        }
    }
    return;
}


int can_reach(string start, string end, vector<string> &wordlist)
{
    int len = wordlist.size();
    int endind = -1;

    vector<vector<int>> adj;
    adj.resize(len + 1);

    for (int i = 0; i < len; i++)
    {
        if (getsame(start, wordlist[i]) == 1)
        {
            adj[0].push_back(i + 1);
            adj[i + 1].push_back(0);
        }

        if (wordlist[i] == end)
            endind = i + 1;
    }

    if (endind == -1)
        return 0;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (getsame(wordlist[i], wordlist[j]) == 1)
            {
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }

    vector<bool> visited(len + 1, false);
    vector<int> dist(len+1,inf);
    bfs(0,adj,visited,dist);
    if(dist[endind]==inf)
        return 0;
    return dist[endind];
}

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        return can_reach(beginWord,endWord,wordList);
    }
};