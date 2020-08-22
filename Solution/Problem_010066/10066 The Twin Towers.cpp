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
    int n , m; 
    int c_counter =1;
    while(cin >> n >> m , n+m){
        cout << "Twin Towers #" << c_counter++ << '\n';
        cout << "Number of Tiles : " ;
        vector<int>a(n),b(m); 
        for(auto&itr:a){
            cin >> itr;
        }
        for(auto&itr:b){
            cin >> itr;
        }
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m;++j){
                if(a.at(i-1) == b.at(j-1)){
                    dp.at(i).at(j) = dp.at(i-1).at(j-1) + 1;
                }else{
                    dp.at(i).at(j) = max(dp.at(i-1).at(j) , dp.at(i).at(j-1));
                }
            }
        }
        cout << dp.at(n).at(m) << '\n';
        cout << '\n'; 
    }
    return 0;
}
