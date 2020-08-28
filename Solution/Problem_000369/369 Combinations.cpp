#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int nCr(int n , int r){
    if(n-r < r){
       r = n-r;
    }
    int a{1}, b{1};
    if(r==0){
        return 1;
    }
    while(r){
        a *= r;
        b *= n;
        int x= __gcd(a,b);
        a/=x;
        b/=x;
        --n;
        --r;
    }
    return b;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n, m;
    while(cin >> n >> m && n+m){
        printf("%ld things taken %ld at a time is %ld exactly.\n",n,m,nCr(n,m));
    }
    return 0;
}
