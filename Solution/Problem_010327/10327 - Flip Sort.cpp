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
    while(cin >> n){
        vector<int>v(n); 
        for(auto&itr:v){
            cin >>itr;
        }
        int counter{};
        for(int i=0; i<n;++i){
            for(int j=i; j < n; ++j){
                if(v.at(i) > v.at(j)){
                    ++counter;
                }
            }
        }
        cout << "Minimum exchange operations : " << counter << '\n';
    }
    return 0;
}
