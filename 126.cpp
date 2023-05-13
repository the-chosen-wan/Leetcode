#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool getsame(string &s1, string &s2)
{
    int c = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            c++;
    }
    return c == 1;
}

vector<vector<string>> ans(string beg, string end, vector<string> &wordlist)
{
    int n = wordlist.size();
    vector<vector<int>> adj(n + 2);
    bool present = false;

    if (getsame(beg, end))
        adj[n].pb(n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (getsame(wordlist[i], wordlist[j]))
            {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
        if (getsame(beg, wordlist[i]))
            adj[n].pb(i);
        if (getsame(end, wordlist[i]))
        {
            adj[i].pb(n + 1);
            adj[n + 1].pb(i);
        }
        if (wordlist[i] == end)
            present = true;
    }

    vector<vector<string>> ans;
    vector<string> temp;
    vector<int> mindist(n + 2, inf);
    mindist[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int v : adj[front])
        {
            if (mindist[v] == inf)
            {
                q.push(v);
                mindist[v] = mindist[front] + 1;
            }
        }
    }
    if (mindist[n + 1] == inf || !present)
        return ans;

    vector<vector<int>> minadj(n + 2);

    for (int i = 0; i < n + 2; i++)
    {
        for (int v : adj[i])
        {
            if (mindist[i] + 1 == mindist[v])
                minadj[i].pb(v);
        }
    }

    auto dfs = [&](int src, auto &&dfs) -> void
    {
        if (src == n)
        {
            temp.pb(beg);
        }
        else if (src == n + 1)
        {
            temp.pb(end);
            ans.pb(temp);
            temp.pop_back();
            return;
        }
        else
            temp.pb(wordlist[src]);

        for (int v : minadj[src])
            dfs(v, dfs);
        temp.pop_back();
        return;
    };
    dfs(n, dfs);
    return ans;
}

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        return ans(beginWord, endWord, wordList);
    }
};
