//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#include<iostream>
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

    vector<int> nextpos(n,-1);

    for(int i=n-1;i>=0;i--){
        if(s[i]=='[')
            nextpos[i] = i;
        else{
            if(i!=n-1)
                nextpos[i] = nextpos[i+1];
        }
    }

    stack<char> st;
    int cnt=0;
    int nextavailable = nextpos[0];
    vector<bool> validpos(n,true);
    int between = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='[') {
            if(validpos[i]) {
                st.push(s[i]);
                nextavailable = nextpos[nextavailable+1];
            }
            else{
                between--;
            }
        }
        else{
            if(st.empty()){
                cnt += nextavailable - i - between;
                validpos[nextavailable]=false;
                nextavailable = nextpos[nextavailable+1];
                between++;
            }

            else{
                st.pop();
            }
        }
    }
    return cnt;
}

class Solution {
    public:
        int minimumNumberOfSwaps(string S){
        return ans(S);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends