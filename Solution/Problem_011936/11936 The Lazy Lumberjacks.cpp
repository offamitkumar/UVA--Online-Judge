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
    int n;  cin >> n;
    while (n--) {
        int a, b, c; cin >> a >> b >> c; 
        if (a+b>c && b+c>a && a+c>b) {
            puts("OK");
        } else {
            puts("Wrong!!");
        }
    }
    return 0;
}
