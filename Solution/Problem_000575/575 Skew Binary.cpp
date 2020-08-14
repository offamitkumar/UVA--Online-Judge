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
    string s; 
    while(cin >> s && s!="0"){
        reverse(s.begin(),s.end());
        int counter{};
        for(int i=0; i<(int)s.size(); ++i){
            counter += ((s[i]-'0') * ((1ll << (i+1ll))-1));
        }
        cout << counter << '\n'; 
    }
    return 0;
}
