#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

vector<int> ans(vector<int> &nums)
{
    int n = nums.size();
    stack<int> sp;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (sp.empty())
        {
            sp.push(nums[i]);
            ans[i] = 0;
        }
        else
        {
            int top = sp.top();
            int c = 0;
            while (nums[i] > top)
            {
                c++;
                sp.pop();
                if (sp.empty())
                    break;
                top = sp.top();
            }
            c += (!sp.empty());
            ans[i] = c;
            sp.push(nums[i]);
        }
    }
    return ans;
}

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        return ans(heights);
    }
};