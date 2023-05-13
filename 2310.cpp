#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(int num, int k)
{
    if (num == 0)
        return 0;
    for (int i = 1; i <= 10; i++)
        if ((num - i * k) % 10 == 0 && i * k <= num)
            return i;
    return -1;
}

class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        return ans(num, k);
    }
};