#include <bits/stdc++.h>
using namespace std;
#define int int64_t
pair<int,int> getPos(int current, int dest) {
    pair<int,int>p; 
    int d = current*current;
    if(d&1){
        p = {1, current};
        int end_d = d - current + 1;
        if(end_d <= dest) {
            while(d != dest) {
                p.first++;
                --d;
            }
        }else{
            p.first = current;
            d = end_d;
            while(d != dest) {
                p.second--;
                --d;
            }
        }
        return p;
    }
    p = {current,1};
    int end_d = d - current + 1;
    if(end_d >= dest) {
        p.second = current; 
        d = end_d;
        while(d != dest) {
            p.first--;
            --d;
        }
    }else{
        p.second = current;
        d = end_d;
        while(d != dest) {
            p.second--;
            ++d;
        }
    }
    return p;
}

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int x; 
    while(cin >> x , x) { 
        int y = ceil(sqrt(x+0.0)); 
        auto itr = getPos(y , x); 
        cout << itr.first << ' ' << itr.second << '\n'; 
    }
    return 0;
}
