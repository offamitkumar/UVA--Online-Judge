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
    string s;
    while(cin >> n && n){
        cin >> s; 
        n = s.size();
        int lastR{INT_MIN} , lastD{INT_MIN}; 
        bool zFound{false};
        int dis = INT_MAX;
        for(int i=0; i<n && (!zFound);++i){
            if(s.at(i) == 'R'){
                lastR = max(lastR , i);
            }else if(s.at(i) == 'D'){
                lastD = max(lastD , i);
            }else if(s.at(i) == 'Z'){
                zFound = true;
                dis = 0;
                continue;
            }
            if(lastD != INT_MIN && lastR != INT_MIN){
                dis = min(dis , abs(lastD - lastR));
            }
        }
        cout << dis << '\n'; 
    }
    return 0;
}
