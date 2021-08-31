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
    string s;
    while (cin >> n && cin >> s) {
        map<string , int>dp; 
        pair<string , int>ans{"",0};
        for (int i=0; i<s.size()-n+1;++i) {
            dp[s.substr(i,n)]++;
            if (dp[s.substr(i,n)] > ans.second) {
                ans.second = dp[s.substr(i,n)]; 
                ans.first = s.substr(i,n);
            }
        }
        cout << ans.first << '\n'; 
    }
    return 0;
}
