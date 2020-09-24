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
    cin.ignore();
    string s;
    getline(cin,s);
    while(t--) {
        map<string,double>f; 
        double counter{}; 
        while(getline(cin , s) && s.size()){
            f[s]++; 
            ++counter;
        }
        cout << fixed << setprecision(4); 
        for(auto&itr:f) {
            cout << itr.first << " " << double(itr.second / counter)*100.0f << '\n'; 
        }
        if(t)
            cout << '\n'; 
    }
    return 0;
}
