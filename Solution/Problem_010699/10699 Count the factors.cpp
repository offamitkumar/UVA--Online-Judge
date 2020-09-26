#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int sol(int n) {
    set<int>s; 
    for (int i=2; i*i<=n; ++i) {
        if (n % i == 0) {
            s.insert(i); 
            while (n%i==0) {
                n/=i;
            }
        }
    }
    if (n != 1) {
        s.insert(n);
    }
    return (int)s.size();
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
    while  (cin >> n && n) {
        printf("%ld : %ld\n",n , sol(n));
    }
    return 0;
}
