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
    int n; 
    while(cin >> n && n >=0 ){
        stack<int>s; 
        while(n){
            s.push(n%3ll);
            n/=3ll;
        }
        if(s.empty()){
            s.push(0);
        }
        while(!s.empty()){
            cout <<  s.top();
            s.pop();
        }
        cout<<'\n';
    }
    return 0;
}
