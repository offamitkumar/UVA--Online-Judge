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
    map<char,int>f; 
    f['B'] = 1; 
    f['F'] = 1; 
    f['P'] = 1; 
    f['V'] = 1; 
    f['C'] = 2; 
    f['G'] = 2; 
    f['J'] = 2; 
    f['K'] = 2; 
    f['Q'] = 2; 
    f['S'] = 2; 
    f['X'] = 2; 
    f['Z'] = 2; 
    f['D'] = 3; 
    f['T'] = 3; 
    f['L'] = 4; 
    f['M'] = 5; 
    f['N'] = 5; 
    f['R'] = 6; 
    string s; 
    while(cin >> s){
        string num{}; 
        for(int i=0; i<(int)s.size(); ++i){
            if(f[s[i]]==0){
                continue;
            }
            if(i==0){
                num+=to_string(f[s[i]]);
            }else if(f[s[i-1]]!=f[s[i]]){
                num+=to_string(f[s[i]]);
            }
        }
        cout << num << '\n'; 
    }
    return 0;
}
