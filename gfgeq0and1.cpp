//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
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

int ans(string s){
    int n = s.length();
    
    int num1=0;
    
    for(int i=0;i<n;i++)
        num1+=(s[i]=='1');
    
    if(num1!=n-num1)
        return -1;
    int sum=0;
    int cnt=0;

    for(int i=0;i<n;i++){
        if(s[i]=='1')
            sum++;
        else
            sum--;
        
        if(sum==0)
            cnt++;
    }

    return cnt;
}

class Solution{
    public:
        int maxSubStr(string str){
            return ans(str);
        }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends