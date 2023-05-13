#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
// const int inf = (1e9) + 7;
// const int p = 31;
#define pb push_back
#define mp make_pair

ll ret(int i, int j, vector<ll> &hash, vector<ll> &pow, int inf)
{
    int n = hash.size();
    ll ret;
    if (i == 0)
        ret = hash[j];
    else
        ret = (hash[j] - hash[i - 1]);
    if (ret < 0)
        ret += inf;
    ret = (ret * pow[n - 1 - i]) % inf;
    return ret;
}

string ans(string s, int p, int inf, int k, int hashvalue)
{
    int n = s.size();
    vector<ll> pow(n);
    pow[0] = 1;
    for (int i = 1; i < n; i++)
        pow[i] = (pow[i - 1] * p) % inf;

    vector<ll> hash(n, 0);
    hash[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++)
        hash[i] = (hash[i - 1] + (s[i] - 'a' + 1) * pow[i]) % inf;
    inf = inf/__gcd((ll)inf,pow[n-1]);

    ll check = (hashvalue * pow[n - 1]) % inf;

    for (int i = 0; i < n + 1 - k; i++)
    {
            {cout<<i<<endl;return s.substr(i, k);}
    }
    return "";
}

// int main(){
//     string s = "dlojuxgftvpqpsknfgkejydsxgcgyroavsefjrejytcgflrnnxxsxowqbteycujnrbaokjibq";
//     int p = 8;
//     int inf = 54;
//     int k=30;
//     int hash = 16;

//     cout<<ans(s,p,inf,k,hash)<<endl;
//     return 0;
// }

class Solution
{
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        return ans(s, power, modulo, k, hashValue);
    }
};