#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

void recurse(int index,int worker,int sum,int localmax,int& globalmin,vector<int>& times,vector<bool>& visited,int& k){
        if(sum>=globalmin)
            return;
        
        if(localmax>=globalmin)
            return;

        if(worker==k){
            for(int i=0;i<visited.size();i++)
                if(!visited[i])
                    return;
            globalmin = min(globalmin,localmax);
            return;
        }

        if(index==times.size()){
            localmax = max(localmax,sum);
            recurse(0,worker+1,0,localmax,globalmin,times,visited,k);
            return;
        }
        
        if(!visited[index]){
        visited[index] = true;
        recurse(index+1,worker,sum+times[index],localmax,globalmin,times,visited,k);
        visited[index] = false;
        }

        if(worker==k-1&&!visited[index])
            return;
        recurse(index + 1, worker, sum, localmax, globalmin, times, visited, k);

        return;
}

int ret(vector<int>& jobs,int k){
    int localmax = -inf;
    int globalmin = inf;
    int n = jobs.size();
    sort(jobs.begin(),jobs.begin());
    vector<bool> visited(n,false);

    recurse(0,0,0,localmax,globalmin,jobs,visited,k);
    return globalmin;
}

class Solution
{
public:
    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        return ret(jobs,k);
    }
};

int main(){
    vector<int> jobs = {9899456, 8291115, 9477657, 9288480, 5146275, 7697968, 8573153, 3582365, 3758448, 9881935, 2420271, 4542202};
    int k = 9;
    cout<<ret(jobs,k);
}
//{1, 2, 4, 7, 8};