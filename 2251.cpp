#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e7;
#define pb push_back
#define mp make_pair

vector<int> ans(vector<vector<int>> &flowers, vector<int> &person)
{
    vector<int> start;
    vector<int> end;
    vector<pii> persons;
    int n = flowers.size();

    for (int i = 0; i < flowers.size(); i++)
    {
        start.pb(flowers[i][0]);
        end.pb(flowers[i][1]);
    }

    for (int i = 0; i < person.size(); i++)
        persons.pb(mp(person[i], i));

    sort(persons.begin(), persons.end());
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int c_start = 0;
    int c_end = 0;
    int c = 0;

    vector<int> ret(person.size());

    for (int i = 0; i < persons.size(); i++)
    {
        while (c_start < n && start[c_start] <= persons[i].first)
        {
            c_start++;
            c++;
        }
        while (c_end < n && end[c_end] < persons[i].first)
        {
            c_end++;
            c--;
        }
        ret[persons[i].second] = c;
    }
    return ret;
}

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
    {
        return ans(flowers, persons);
    }
};