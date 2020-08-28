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
    int s , d;
    while(cin >> s >> d){
        int res{s};
        int day{0};
        while(1){
            day+=res;
            if(day>= d){
                cout << res << endl;
                break;
            }
            res++;
        }
    }
    return 0;
}
