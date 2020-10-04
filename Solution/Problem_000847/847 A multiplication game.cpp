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
    while (cin >> n) {
        int p = 1;
        bool turn = true;
        while (true) {
            if (p * 9ll >= n) {
                break;
            } else {
                if(turn) {
                    p*=2ll;
                } else {
                    p*=9ll;
                }
            }
            turn = (!turn);
        }
        if (turn) {
            puts("Stan wins.");
        } else {
            puts("Ollie wins.");
        }
    }
    return 0;
}
