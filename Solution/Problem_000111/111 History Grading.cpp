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
    int n; cin >> n; 
    vector<int>correct(n);
    for(int i=0;  i<n;++i){
        int x; cin >> x; 
        correct.at(x-1) = i;
    }
    int x;
    while(cin >> x){
        vector<int>answer(n+1);
        answer.at(x-1) = 0;
        for(int i=1; i<n;++i){
            cin  >> x; 
            answer.at(x-1) = i;
        }
        vector<vector<int>>dp(n+1 , vector<int>(n+1));
        for(int i=1; i<=n;++i){
            for(int j =1; j<=n;++j){
                if(correct[i-1] == answer[j-1]){
                    dp[i][j] = (dp[i-1][j-1])+1;
                }else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        cout << dp[n][n] << '\n'; 
    }
    return 0;
}
