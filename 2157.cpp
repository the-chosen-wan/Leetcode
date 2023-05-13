#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 26

inline int abs(int x){
    return x>0?x:-x;
}

bool check(string& s1,string& s2){
    int n1 = s1.size();
    int n2 = s2.size();
    vector<int> nums1(N,0);
    vector<int> nums2(N,0);

    for(int i=0;i<n1;i++)
        nums1[s1[i]-'a']++;
    for(int i=0;i<n2;i++)
        nums2[s2[i]-'a']++;
    
    int c=0;
    for(int i=0;i<N;i++){
        if(abs(nums1[i]-nums2[i])>1)
            return false;
        if(nums1[i]!=nums2[i])
            c++;
        if(c>2)
            return false;
    }
    return true;
}

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

int find_set(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

vector<int> ans(vector<string>& words){
    int n = words.size();
    vector<int> parent;
    vector<int> size;
    initialize(n,parent,size);
    
}

class Solution
{
public:
    vector<int> groupStrings(vector<string> &words)
    {
        return ans(words);
    }
};