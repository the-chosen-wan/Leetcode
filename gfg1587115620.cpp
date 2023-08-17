//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

ll ans(ll arr[], ll n ){
    priority_queue<ll,vector<ll>,greater<ll>> pq;

    for(int i=0;i<n;i++)
        pq.push(arr[i]);
    ll ans=0;
    while(!pq.empty()){
        ll top = pq.top();

        pq.pop();

        if(pq.empty())
            return ans;
        
        ll secondtop = pq.top();
        pq.pop();
        pq.push(top+secondtop);
        ans+=(top+secondtop);
    }

    return -1;
}

class Solution{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
    return ans(arr,n);
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends