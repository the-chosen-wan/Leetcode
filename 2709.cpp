#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
const int N = (1e5)+1;
#define pb push_back
#define pf push_front
#define mp make_pair
void initialize(int n, vector<int> &parent, vector<int> &size)
{
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    return;
}

int find_sets(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_sets(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = find_sets(a, parent);
    b = find_sets(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

bool ans(vector<int>& nums){
    int n = nums.size();
    vector<bool> quick(N,false);
    int N = -1;

    if(n==1)
        return true;
    for(int i=0;i<n;i++){
        if(nums[i]==1)
            return false;
        quick[nums[i]]=true;
        N = max(N,nums[i]);
    }

    N++;


    vector<bool> isprime(N,true);
    map<int,vector<int>> edges;
    for(int i=2;i<N;i++){
        if(isprime[i]) {
            for(int j=2*i;j<N;j+=i){
                isprime[j]=false;

                if(quick[j])
                    edges[j].pb(i);
            }
        }
    }

    vector<int> parent;
    vector<int> rank;
    initialize(N,parent,rank);

    for(int i=0;i<n;i++){
        for(int j:edges[nums[i]]){
            union_sets(nums[i],j,parent,rank);
        }
    }

    for(int i=1;i<n;i++){
        if(find_sets(nums[0],parent)!=find_sets(nums[i],parent))
            return false;
    }

    return true;
}

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        return ans(nums);
    }
};