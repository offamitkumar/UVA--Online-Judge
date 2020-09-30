#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int exu(int a, int b, int &x, int &y) {
    if (a==0) {
        x = 0; 
        y = 1; 
        return b; 
    }
    int x1, y1; 
    int d = exu(b%a, a, x1, y1); 
    x = y1 - (b/a) * x1; 
    y = x1; 
    return d; 
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int A , B; 
    while (cin >> A >> B) {
        if (A == 0 && B == 0 ) {
            cout << "1 0 0" << '\n'; 
            continue;
        }
        int x, y, d; 
        d = exu(A, B, x, y); 
        if (A == B && x > y) {
            swap(x,y);
        }
        cout << x <<' ' << y <<' ' << d << '\n'; 
    }
    return 0;
}
