#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool ans(int sx, int sy, int tx, int ty)
{
    pii src = mp(sx, sy);
    pii dest = mp(tx, ty);

    while (dest.first != 0 && dest.second != 0)
    {
        if (src == dest)
            return true;
        if (dest.first > dest.second)
        {
            if (dest.second == src.second)
            {
                if (dest.first >= src.first && (dest.first - src.first) % dest.second == 0)
                    return true;
            }
            dest.first %= dest.second;
        }
        else
        {
            if (dest.first == src.first)
            {
                if (dest.second >= src.second && (dest.second - src.second) % dest.first == 0)
                    return true;
            }
            dest.second %= dest.first;
        }
    }

    if (dest == src)
        return true;
    return false;
}

class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        return ans(sx, sy, tx, ty);
    }
};