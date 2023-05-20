#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

vector<int> primefacts(int n)
{
    vector<int> ret;
    int i = 2;

    while (n != 1)
    {
        if (n % i == 0)
            ret.pb(i);

        while (n % i == 0)
            n /= i;

        i++;
    }

    return ret;
}

int ans(vector<int> &nums)
{
    cout<<nums.size()<<endl;
    int N = 1000000;
    
    vector<int> allprimes;
    vector<vector<int>> primes(N+1);
    for (int i = 2; i <= N; i++)
    {
        if (primes[i].size() != 0)
            continue;

        primes[i].pb(i);

        for (int j = 2* i; j <= N; j += i)
        {
            primes[j].pb(i);
        }
    }

    vector<pii> ranges(N + 1, mp(-1, -1));

    int n = nums.size();
    set<int> valid;

    for (int i = 0; i < n; i++)
    {
        for (int j : primes[nums[i]])
        {
            valid.insert(j);
            if (ranges[j].first == -1)
                ranges[j].first = i;
            ranges[j].second = i;
        }
    }
    vector<pii> primeranges;

    for (auto i : valid)
    {
        primeranges.pb(ranges[i]);
    }

    sort(primeranges.begin(), primeranges.end());
    int high = 0;

    for (pii temp : primeranges)
    {
        if (temp.first > high && high != n - 1)
            return high;

        high = max(high, temp.second);
    }
    return -1;
}

class Solution
{
public:
    int findValidSplit(vector<int> &nums)
    {
        return ans(nums);
    }
};

int main()
{
    vector<int> temp = {229309, 937187, 229309, 36007, 75533, 647503, 229309, 540157, 75533, 807259, 853733, 118861, 71119, 938459, 439883, 36007, 572053, 540157, 708733, 282383, 929737, 229309, 253787, 387721, 887057, 247421, 241343, 17569, 80687, 395491, 288257, 209401, 291367, 868489, 856553, 801859, 849763, 455737, 679603, 267017, 541529, 886537, 202751, 242129, 716543, 798713, 408623, 150707, 461581, 241337, 502087, 532447, 183877, 183877, 841913, 873139, 842857, 829469, 183877, 183877, 281557, 62299, 34963, 518311, 888541, 588241, 49307, 289973, 829469, 148501, 744407, 829469, 842857, 349241, 996847, 600361, 829469};
    cout<<ans(temp)<<endl;
}
