#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

void toposort(int src,vector<vector<int>>& adj,vector<pii>& topo,vector<bool>& visited, int& count){
    visited[src] = true;
    // cout<<src<<endl;

    for(int v:adj[src]){
        if(!visited[v])
            toposort(v,adj,topo,visited,count);
    }
    topo[src].first = count;
    count++;
    return;
}

int solve(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> adj;
    adj.resize(n*m);
    // cout<<adj.size()<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i!=0&&mat[i-1][j]>mat[i][j])
                adj[n*i+j].push_back(n*i+j-n);
            if(i!=(m-1)&&mat[i][j]<mat[i+1][j])
                adj[n * i + j].push_back(n * i + j + n);
            if(j!=0&&mat[i][j-1]>mat[i][j])
                adj[n*i+j].push_back(n*i+j-1);
            if(j!=(n-1)&&mat[i][j]<mat[i][j+1])
                adj[n*i+j].push_back(n*i+j+1);
        }
    }
    // cout<<"hjghj"<<endl;

    int count = 0;
    vector<bool> visited(n*m,false);
    vector<pii> topo(n*m);

    for(int i=0;i<topo.size();i++){
        topo[i] = make_pair(0,i);
    }

    for(int i=0;i<topo.size();i++){
        if(!visited[i])
            toposort(i,adj,topo,visited,count);
    }
    // cout<<"fbxhcg"<<endl;

    sort(topo.begin(),topo.end());
    // for(pii k:topo){
    //     cout<<k.first<<endl;
    // }

    vector<int> dp(topo.size(),1);
    vector<int> back(n*m);
    for(int i=0;i<n*m;i++)
        back[topo[i].second] = topo[i].first;

    for(int i=0;i<=n*m-1;i++){
        int maxa = 0;
        for(int v:adj[topo[i].second]){
            maxa = max(dp[back[v]],maxa);}
        maxa++;
        dp[i] = maxa;
    }

    int global_maxa = 0;
    for(int i=0;i<topo.size();i++)
        global_maxa = max(global_maxa,dp[i]);
    
    // cout<<dp[back[6]]<<endl;
    return global_maxa;
}

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        return solve(matrix);
    }
};

// int main(){
//     int n;cin>>n;
//     vector<vector<int>> mat;
//     mat.resize(n,vector<int>(n));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>mat[i][j];
//         }
//     }
//     cout<<solve(mat)<<endl;
// }