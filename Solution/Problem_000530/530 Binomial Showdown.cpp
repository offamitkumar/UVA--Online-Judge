#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int nCr(int n , int r) {
    if(n-r > r){
        r = (n-r);
    }
    int res = 1; 
    int counter = 1;
    for(int i=n; i>r; --i){
        res*=i; 
        res/=counter++;
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
    int n , k; 
    while(cin >> n >> k && n+k) {
        cout << nCr(n ,k) << '\n'; 
    }
    return 0;
}
