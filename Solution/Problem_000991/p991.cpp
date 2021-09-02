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
    int n; 
    vector<int>dp(11); 
    dp[0] = dp[1] = 1;
    for (int i=2; i<11; ++i) {
        for (int j=0; j<i; ++j) {
            dp[i] += (dp[j] * dp[i-j-1]);
        }
    }
    bool first = true;
    while (cin >> n) {
        if (!first) {
            cout << '\n'; 
        } first = false;
        cout << dp[n] << '\n' ; 
    }
    return 0;
}
