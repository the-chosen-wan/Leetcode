//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

//{ Driver Code Starts
//Initial template for C++
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

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


string ans(int arr[],int n){
    sort(arr,arr+n);

    string n1="";
    string n2 = "";

    if(n&1)
        n2+='0';

    for(int i=0;i<n;i++){
        if(i&1)
            n2+=(arr[i]+'0');
        else
            n1+=(arr[i]+'0');
    }

    int len = n1.length();
    int carry = 0;
    string ans(len+1,'0');

    for(int i=len-1;i>=0;i--){
        int val1 = n1[i]-'0';
        int val2 = n2[i] - '0';

        int num = val1+val2+carry;

        int digit = num%10;
        carry = num/10;

        ans[i+1] = digit+'0';
    }

    if(carry!=0){
        ans[0] = carry+'0';
    }

    int zeropos = 0;

    for(int i=0;i<=len;i++){
        if(ans[i]!='0')
            break;
        zeropos++;
    }
    if(zeropos==len+1)
        return "0";
    return ans.substr(zeropos,len+1-zeropos);
}

class Solution{   
public:
    string solve(int arr[], int n) {
        return ans(arr,n);
    }
};

// } Driver Code Ends

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends