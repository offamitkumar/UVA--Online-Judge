#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int get_person(int n , int m){
    int pos{};
    for(int p = 1; p < n; ++p){
        pos = (pos + m)%p;
    }
    return pos+1; // one based indexing
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; 
    while(cin >> n , n){
        for(int i=1;;++i){
            if(get_person(n,i)==12){
                cout << i << '\n'; 
                break;
            }
        }
    }
    return 0;
}
