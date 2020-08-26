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
    long double d; 
    vector<int>coin{5,10,20,50,100,200,500,1000,2000,5000,10000};
    vector<int>dp(30001);
    dp[0] = 1;
    for(int i=0; i<(int)coin.size(); ++i){
        for(int j=coin[i]; j<(int)dp.size();++j){
            dp[j] += dp[j-coin[i]];
        }
    }
    cout << fixed << setprecision(2);
    while(cin >> d && d!=0.00){
        cout << setw(6) << setfill(' ') << d; 
        d = round(d * 100.0f);
        cout << setw(17) << setfill(' ')<< dp[(int)d] << '\n'; 
    }
    return 0;
}
