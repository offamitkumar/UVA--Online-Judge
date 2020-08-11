#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct obj{
    int query_number , interval; 
    int current_time = 0;
};
struct Compare{
    bool operator()(obj&a, obj&b){
        if(a.current_time == b.current_time){
            return a.query_number > b.query_number;
        }else{
            return a.current_time > b.current_time;
        }
    }
};
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    priority_queue<obj , vector<obj>, Compare>pq;
    string x; int query,interval; 
    while(cin >> x && x != "#"){
        cin >> query >> interval; 
        obj o; 
        o.query_number = query;
        o.interval = interval; 
        o.current_time = interval;
        pq.push(o);
    }
    int k; cin >> k; 
    while(k--){
        obj dummy = pq.top(); pq.pop(); 
        cout << dummy.query_number << '\n'; 
        dummy.current_time += dummy.interval; 
        pq.push(dummy);
    }
    return 0;
}
