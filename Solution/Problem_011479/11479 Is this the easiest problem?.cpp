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
    int t; cin >> t; 
    for(int i=1;i<=t;++i){
        cout <<"Case "<<i<<": "; 
        int a,b,c; cin >> a >> b >> c; 
        if(a+b>c && b+c>a && c+a>b){
            if(a == b && b == c){
                cout << "Equilateral";
            }else if(a == b || b == c || c == a){
                cout << "Isosceles";
            }else{
                cout <<"Scalene";
            }
        }else{
            cout <<"Invalid";
        }
        cout << '\n'; 
    }
    return 0;
}
