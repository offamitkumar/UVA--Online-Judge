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
        double n; cin >> n; vector<double>v(n); 
        double counter{};
        for(auto&itr:v){
            cin >> itr;
            counter+=itr;
        }
        counter = (counter / (n * 100.0f))*100.0f;
        double counter1{};
        for(auto&itr:v){
            counter1+=(itr > counter);
        }
        cout << fixed << setprecision(3) << (counter1 / n)*100.0f << "%"<<'\n'; 
    }
    return 0;
}
