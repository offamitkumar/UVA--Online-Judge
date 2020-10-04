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
    vector<int>mile(2001), juice(2001);
    mile[0] = 10; 
    juice[0] = 15; 
    for (int i=1; i<=2000;  ++i) {
        // mile 
        if (i - 30 >= 0) {
            mile[i] = mile[i-30] + 10;
        } else {
            mile[i] = max( mile[i] , mile[i-1]);
        }
        // juice
        if (i - 60 >= 0) {
            juice[i] = juice[i-60] + 15;
        } else {
            juice[i] = max(juice[i] , juice[i-1]);
        }
    }
    int counter{1};
    int t; cin >> t; 
    while (t--) {
        int n; cin >> n; 
        int mile_counter{} , juice_counter{};
        for (int i=0,u; i<n; ++i) {
            cin >> u; 
            mile_counter+=mile[u];
            juice_counter+=juice[u];
        }
        if (mile_counter == juice_counter) {
            printf("Case %ld: Mile Juice %ld\n", counter++, mile_counter);
        } else if (mile_counter < juice_counter) {
            printf("Case %ld: Mile %ld\n", counter++, mile_counter);
        } else {
            printf("Case %ld: Juice %ld\n", counter++, juice_counter);
        }
    }
    return 0;
}
