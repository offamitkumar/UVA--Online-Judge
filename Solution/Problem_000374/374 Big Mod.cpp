#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int power(int a, int b, int c){
    int res = 1; 
    while(b){
        if(b&1){
            (res*=a)%=c;
        }
        (a*=a)%=c;
        b>>=1;
    }
    return res;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int b, p , m; 
    while(cin >> b >> p >> m)
        cout << power(b, p , m) << endl; 
    return 0;
}
