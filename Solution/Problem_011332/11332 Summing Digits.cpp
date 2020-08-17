#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int score(int n){
    while(n >= 10){
        int y{};
        while(n){
            y+=(n%10ll); 
            n/=10ll;
        }
        n = y;
    }
    return n;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n;
    while(cin >> n,n){
        cout << score(n) << '\n';
    }
    return 0;
}
