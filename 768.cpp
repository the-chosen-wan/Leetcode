#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int maxa(vector<int>& nums){
    stack<pii> s;
    int group = 0;
    int len = nums.size();   

    for(int i=0;i<len;i++){
        if(s.empty())
            {s.push(mp(nums[i],group));group++;}
        
        else{
            pii top = s.top();
            if(nums[i]>=top.first){
                s.push(mp(nums[i],top.second+1));
                group++;
            }
            // else if(nums[i]==top.first){
            //     while(top.first==nums[i]){
            //         s.pop();
            //         if(s.empty())
            //             break;
            //         top = s.top();
            //     }
            //     s.push(mp(nums[i],++group));
            // }
            else{
                pii top =s.top();
                queue<pii> temp;
                while(nums[i]<top.first){
                    temp.push(top);
                    s.pop();
                    if(s.empty())
                        break;
                    top = s.top();
                    if(top.first==temp.front().first)
                        temp.pop();
                }
                group = 0;
                // while(true){
                //     pii back = temp.back();
                //     temp.pop_back();
                //     if(temp.empty())
                //         {temp.pb(back);break;}
                //     pii check = temp.back();
                //     if(check.first==back.first)
                //         s.push(back);
                //     else{
                //         temp.pb(back);
                //         break;
                //     }
                // }
                if(!s.empty())
                    group = s.top().second+1;
                s.push(mp(temp.front().first,group));
                group++;
            }
        }
    }
    // while(!s.empty())
    //     {cout<<s.top().first<<" "<<s.top().second<<endl;;s.pop();}
    return ++s.top().second;
}

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        return maxa(arr);
    }
};

// int main(){
//     vector<int> arr = {2,1,3,4,4}; cout << maxa(arr);
// }