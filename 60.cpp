#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

string ans(int n, int k)
{
    k--;
    vector<int> fact(11, 1);
    for (int i = 1; i <= 10; i++)
        fact[i] = i * fact[i - 1];

    ordered_set s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    vector<int> ans(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int num = k / fact[n - i];
        int ins = *(s.find_by_order(num));
        ans[i] = ins;
        s.erase(ins);
        k %= fact[n - i];
    }
    string ret;
    for (int i = 1; i <= n; i++)
        ret.pb(ans[i] + '0');
    return ret;
}

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        return ans(n, k);
    }
};