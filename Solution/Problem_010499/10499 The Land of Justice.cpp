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
    // area of sphere = 4 PI r^2 
    // area of circle = PI r^2 
    // So we can see that AOS = 4 * AOC (area of Circle)  or
    // if we consider AOS as 100% then AOC will be 25% of AOS


    // as question says that sphere is going to be divided in N pieces. 
    // there will be N circles each contributing to 25% 
    int n; 
    while (cin >> n && n>0){
        if (n==1) {
            cout <<0;
        }else {
            cout << n*25;
        }
        cout <<"%"<<'\n';
    }
    return 0;
}
