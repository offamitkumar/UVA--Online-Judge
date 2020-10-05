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
    string s; 
    while (cin >> s && s != "0") {
        int sum{}; 
        for (auto&itr:s) {
            sum+=(itr-'0');
        }
        bool ok = (sum%9==0); 
        int degree{};
        if (ok) {
            degree = 1;
            while (sum >9) {
                int quot{}; 
                while (sum) {
                    quot+=(sum%10);
                    sum=(sum/10);
                }
                sum = quot;
                ++degree;
            }
            cout << s <<" is a multiple of 9 and has 9-degree " << degree << ".";
        } else {
            cout << s <<" is not a multiple of 9.";
        }
        cout << '\n'; 
    }
    return 0;
}
