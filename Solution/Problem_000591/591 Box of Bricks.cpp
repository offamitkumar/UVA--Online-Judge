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
    int it = 1;
    while(cin >> n , n){
        cout <<"Set #" << it++ << '\n'; 
        vector<int>v(n); 
        int d1{}; 
        for(auto&itr:v){
            cin >> itr;
            d1+=itr;
        }
        d1 = (d1 / n);
        int movement{}; 
        for(auto&itr:v){
            if(itr > d1){
                movement += (itr - d1);
            }
        }
        cout << "The minimum number of moves is ";
        cout << movement << ".\n"; 
        cout << '\n'; 
    }
    return 0;
}
