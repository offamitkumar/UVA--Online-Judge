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
    while(cin >> n,n){
        deque<int>d; 
        for(int i=1; i<=n; ++i){
            d.push_back(i);
        }
        cout << "Discarded cards:";
        bool firstNum = true;
        while(d.size() > 1){
            if(firstNum){
                cout <<" " << d.front();
                firstNum = false;
            }else{
                cout <<", " << d.front();
            }
            d.pop_front(); 
            int x = d.front(); 
            d.pop_front(); 
            d.push_back(x);
        }
        cout << '\n' << "Remaining card: " << d.front() << '\n'; 
    }
    return 0;
}
