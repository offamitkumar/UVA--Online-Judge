#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool good_choice(int seed, int mod) {
    return (__gcd(seed,mod) == 1);
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int step , mod; 
    //bool ok = false;
    while (cin >> step >> mod) {
//         if (ok) {
//             cout << '\n'; 
//         }
//         ok = true;
        cout << setw(10) << setfill(' ') << step; 
        cout << setw(10) << setfill(' ') << mod; 
        cout << "    ";
        if (good_choice(step, mod)) {
            cout << "Good Choice" << '\n';
        } else {
            cout << "Bad Choice" << '\n';
        }
        cout << '\n'; 
    }
    return 0;
}
