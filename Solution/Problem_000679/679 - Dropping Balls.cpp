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
    while(t--){
        int d , i; cin >> d >> i; 
        d = (1<<d);
        int current_node = 1; 
        while(current_node < d){
            int left = current_node << 1; 
            int right = (current_node << 1) + 1; 
            if(left < d && right < d){
                if(i&1){
                    current_node = left; 
                    i = i/2+1;
                }else{
                    current_node = right; 
                    i = i/2;
                }
            }else{
                break;
            }
        }
        cout << current_node << '\n'; 
    }
    return 0;
}
