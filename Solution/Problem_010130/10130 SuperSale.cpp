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
    while(t--){
        int n; cin >> n; 
        vector<pair<int,int>>object(n); 
        for(int i=0; i<n;++i){
            cin >> object.at(i).first >> object.at(i).second;
        }
        vector<vector<int>>dp(n+1 , vector<int>(31));
        for(int i=1; i<=n;++i){
            for(int j=1; j<=30; ++j){
                if(j < object.at(i-1).second){
                    dp[i][j] = max(dp[i][j] , dp[i-1][j]);
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i-1][j-object.at(i-1).second]+object.at(i-1).first);
                }
            }
        }
        int tt,x,counter{};
        cin >> tt; 
        while(tt--){
            cin >> x;
            counter+= dp[n][x];
        }
        cout << counter << '\n'; 
    }
    return 0;
}
