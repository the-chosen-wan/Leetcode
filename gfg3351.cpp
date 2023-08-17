//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(int arr[],int n, int k){
    sort(arr,arr+n);
    int ans = inf;

    ans = min(ans,arr[n-1]-arr[0]);

    for(int i=0;i<n-1;i++){

        if(arr[i+1]<k)
            continue;

        int prefmax = arr[i]+k;
        int prefmin = arr[0]+k;

        int suffmin = arr[i+1]-k;
        int suffmax = arr[n-1]-k;

        ans = min(ans,max(prefmax,suffmax) - min(prefmin,suffmin));
    }
    return ans;
}

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        return ans(arr,n,k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends