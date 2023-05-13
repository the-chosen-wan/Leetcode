#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int bags(vector<int> &capa, vector<int> &bags, int k)
{
    vector<int> t;
    for (int i = 0; i < capa.size(); i++)
        t.pb(capa[i] - bags[i]);

    sort(t.begin(), t.end());
    int c = 0;
    int i = 0;
    while (i < capa.size())
    {
        if (k >= t[i])
        {
            c++;
            k -= t[i];
            i++;
            continue;
        }
        break;
    }
    return c;
}

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        return bags(capacity, rocks, additionalRocks);
    }
};