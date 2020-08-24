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
    int a,b,c; 
    while(cin >> a >> b >> c){
        if(b==c && a!=b){
            cout<<"A";
        }else if(a ==c && a != b){
            cout<<"B";
        }else if(a == b && a != c){
            cout<<"C";
        }else{
            cout<<"*";
        }
        cout<<'\n';
    }
    return 0;
}
