#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    while (t--) {
        int n , k; cin >> n >> k; 
        vector<vector<int>>dp(n+1 , vector<int>(k+10)); 
        dp[0][0] = 1;  // dp[i][j] => if we divide i then will get reminder j
        vector<int>v(n); 
        for(auto&itr:v) {
            cin >> itr; 
            itr = abs(itr%k);
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<k; ++j) {
                if (dp[i][j]) {
                    dp[i+1][(j+v[i]+k)%k] =1; 
                    dp[i+1][(j-v[i]+k+k)%k] =1; 
                }
            }
        }
        if (dp[n][0]) {
            cout << "Divisible" << '\n'; 
        } else { 
            cout << "Not divisible" << '\n'; 
        }
    }
    return 0;
}
