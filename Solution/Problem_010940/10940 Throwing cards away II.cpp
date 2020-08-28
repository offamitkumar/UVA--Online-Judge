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
    int endPoint = 2;
    vector<int>dp(500001);
    dp[1] =1;
    for(int i=2, counter = 2; i<500001; ++i){
        dp[i] = counter;
        if(counter == endPoint){
            counter=2;
            endPoint *= 2;
        }else{
            counter+=2;
        }
    }
    int n;
    while(cin >> n && n!=0){
        cout << dp[n] << endl;
    }
    return 0;
}
