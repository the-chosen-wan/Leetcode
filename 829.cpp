#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(int n)
{
    while ((n & 1) != 1)
        n >>= 1;

    int i = 3;
    int p = 1;
    while (n != 1)
    {
        int c = 1;
        while (n % i == 0)
        {
            n /= i;
            c++;
        }
        i++;
        p *= c;
    }
    return p;
}

class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        return ans(n);
    }
};