//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
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

int ans(int arr[],int n,int k){
    for(int i=0;i<n;i++)
        arr[i]=(arr[i]<=k);
        
    int cnt = 0;
    for(int i=0;i<n;i++)
        cnt+=arr[i];
    
    
    int ans = inf;
    int bad = 0;
    
    for(int i=0;i<cnt;i++)
        if(!arr[i])
            bad++;
        
    
    ans = min(ans,bad);
    for(int i=cnt;i<n;i++){
        if(!arr[i])
            bad++;
        
        if(!arr[i-cnt])
            bad--;
        
        ans = min(ans,bad);
    }
    
    return ans;
}

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        return ans(arr,n,k);
    }
};



//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends