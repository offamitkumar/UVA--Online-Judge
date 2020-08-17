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
    int t; 
    int counter{1};
    cin >> t;
    while(t--){
        cout << "Case #"<<counter++ << ":" << '\n';
        vector<pair<string,int>>v(10); 
        int searched{};
        for(auto&itr:v){
            cin >> itr.first >> itr.second;
            searched = max(searched , itr.second);
        }
        for(auto&itr:v){
            if(itr.second == searched){
                cout << itr.first<<'\n';
            }
        }
    }
    return 0;
}
