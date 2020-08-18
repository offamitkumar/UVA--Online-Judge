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
    int x; 
    priority_queue<int , vector<int> , greater<int>>mn_pq; 
    priority_queue<int , vector<int> , less<int>>mx_pq;
    while(cin >> x){
        // insertion in the priority-queue
        if(mn_pq.size() == 0){
            mn_pq.push(x);
        }else if(mx_pq.size() == 0){
            if(mn_pq.top() < x){
                mx_pq.push(mn_pq.top());
                mn_pq.pop();
                mn_pq.push(x);
            }else{
                mx_pq.push(x);
            }
        }else if(x > mx_pq.top()){
            mn_pq.push(x);
        }else{
            mx_pq.push(x);
        }
        // balancing 
        if(abs((int)mn_pq.size() - (int)mx_pq.size()) > 1){
            if(mn_pq.size() > mx_pq.size()){
                mx_pq.push(mn_pq.top()); 
                mn_pq.pop();
            }else{
                mn_pq.push(mx_pq.top());
                mx_pq.pop();
            }
        }
        if(mn_pq.size() == mx_pq.size()){
            cout << (mn_pq.top() + mx_pq.top())/2 << '\n'; 
        }else if(mn_pq.size() > mx_pq.size()){
            cout << mn_pq.top() << '\n'; 
        }else {
            cout << mx_pq.top() << '\n'; 
        }
    }
    return 0;
}
