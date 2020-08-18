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
    queue<int>q; 
    q.push(6); q.push(7); 
    unordered_set<int>s; 
    while(q.front() < 4000){
        int x = q.front(); q.pop(); 
        s.insert(x); 
        q.push(x+7);
    }
    while(t--){
        int n; cin >> n; 
        int days{}; 
        int p; cin >> p; 
        set<int>strike;
        for(int i=0,x; i<p; ++i){
            cin >> x; 
            int T = x;
            while(x <= n){
                if(s.find(x)==s.end() && strike.find(x)==strike.end()){
                    strike.insert(x);
                    ++days;
                }
                x+=T;
            }
        }
        cout << days << '\n'; 
    }
    return 0;
}
