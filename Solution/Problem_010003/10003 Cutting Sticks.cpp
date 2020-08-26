#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>v;
vector<vector<int>>dp(60 , vector<int>(60 , -1));
int sol(int left , int right){
    if(right - left == 1){
        dp[left][right] = 0;
        return 0;
    }
    if(dp[left][right] != -1){
        return dp[left][right];
    }
    int temp = INT_MAX;
    for(int i=left+1; i < right; ++i){
        temp = min(temp , v.at(right) - v.at(left) + sol(left , i) + sol(i , right));
    }
    dp[left][right] = temp;
    return temp;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int l;
    int n;
    while(cin >> l,l){
        cin >> n;
        v.clear(); 
        v.push_back(0); 
        for(int i=0; i<60; ++i){
            for(int j=0; j<60; ++j){
                dp[i][j] = -1;
            }
        }
        for(int i=0,x;i<n;++i){
            cin >> x;
            v.push_back(x);
        }
        v.push_back(l);
        cout << "The minimum cutting is " << sol(0, n+1) << ".\n";
    }
    return 0;
}
