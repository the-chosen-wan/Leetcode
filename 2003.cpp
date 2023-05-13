#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void get_size(int src,int parent,vector<vector<int>>& adj,vector<int>& sizes){
    sizes[src]=1;
    for(int v:adj[src]){
        if(v==parent)
            continue;
        get_size(v,src,adj,sizes);
        sizes[src]+=sizes[v];
    }
    return;
}

void get_smallest(int src,int parent,vector<vector<int>>& adj,vector<unordered_set<int>>& sets,vector<int>& sizes,vector<int>& index,vector<int>& smallest,vector<int>& nums){
    int small = 1;
    int maxind = src;
    int maxsize = -1e9;

    for(int v:adj[src]){
        if(v==parent)
            continue;
        
        get_smallest(v,src,adj,sets,sizes,index,smallest,nums);
        
        if(sizes[v]>maxsize){
            maxsize = sizes[v];
            maxind = index[v];
        }

        if(smallest[v]>small)
            small = smallest[v];

    }

    index[src] = maxind;

    for(int v:adj[src]){
        if(v==parent||index[v]==maxind)
            continue;
        sets[maxind].insert(sets[index[v]].begin(),sets[index[v]].end());
    }

    sets[maxind].insert(nums[src]);

    while(true){
        if(sets[maxind].find(small)!=sets[maxind].end())
            small++;
        else 
            break;
    }
    smallest[src] = small;
    return;
}

vector<int> initialize(vector<int>& parents, vector<int>& nums){
    int n = parents.size();

    vector<vector<int>> adj(n);
    vector<int> sizes(n);
    vector<int> index(n);
    vector<unordered_set<int>> sets(n);
    vector<int> smallest(n);

    for(int i=0;i<n;i++){
        if(parents[i]==-1)
            continue;
        adj[i].push_back(parents[i]);
        adj[parents[i]].push_back(i);
    }

    get_size(0,0,adj,sizes);
    get_smallest(0,0,adj,sets,sizes,index,smallest,nums);
    return smallest;

}

int main(){
    int n;cin>>n;
    vector<int> parents(n);
    vector<int> nums(n);

    for(int i=0;i<n;i++){
        int k;cin>>k;
        parents[i] = k;
    }

    for(int i=0;i<n;i++){
        int k;cin>>k;
    }
}

class Solution
{
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums)
    {
        return initialize(parents,nums);
    }
};
