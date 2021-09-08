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
    int a,b,c,d,L; ; 
    while (cin >> a >> b >> c >> d >> L){
        if (a || b || c || d) {
            int counter{};
            for (int l=0; l<=L; ++l) {
                if ((a * l * l + b * l + c)%d==0) {
                    counter++;
                }
            }
            cout << counter << '\n'; 
        } else {
            break;
        }
    }
    return 0;
}
