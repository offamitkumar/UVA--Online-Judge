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
    int n; cin >> n; 
    cout <<"Lumberjacks:"<<'\n';
    while(n--){
        vector<int>v(10);
        for(auto&itr:v)cin >> itr; 
        if(is_sorted(v.begin() , v.end() , greater<int>()) || is_sorted(v.begin() , v.end(), less<int>())){
            cout <<"Ordered";
        }else{
            cout <<"Unordered";
        }
        cout<<'\n';
    }
    return 0;
}
