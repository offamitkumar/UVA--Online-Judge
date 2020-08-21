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
        cout << n << " = ";
        multiset<int>s; 
        if(n<0){
            s.insert(-1);
            n*=-1;
        }
        for(int i=2; i*i<=n; ++i){
            while(n%i==0){
                s.insert(i);
                n/=i;
            }
        }
        if(n!=1 || s.size() == 0){ // if s.size is 0 then input is 1 
            s.insert(n);
        }
        bool more = false;
        for(auto&itr:s){
            if(more){
                cout <<" x ";
            }
            more = true;
            cout << itr ;
        }
        cout << '\n'; 
    }
    return 0;
}
