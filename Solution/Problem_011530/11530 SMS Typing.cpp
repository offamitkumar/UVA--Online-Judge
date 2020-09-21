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
    char ch = 'a'; 
    map<char , int> f;
    int counter = 1;
    for(; ch<='o'; ++ch) {
        f[ch] = counter++;
        if(counter == 4){
            counter = 1;
        }
    }
    f['p'] = 1;
    f['q'] = 2;
    f['r'] = 3;
    f['s'] = 4;
    f['t'] = 1;
    f['u'] = 2;
    f['v'] = 3;
    f['w'] = 1;
    f['x'] = 2;
    f['y'] = 3;
    f['z'] = 4;
    f[' '] = 1;
    int t; cin >> t; 
    cin.ignore();
    int caseCounter{1};
    while(t--) {
        cout << "Case #" << caseCounter++ <<": ";
        string s; 
        int sum{};
        getline(cin , s); 
        for(auto&itr:s) {
            sum+=(f[itr]);
        }
        cout << sum << '\n'; 
    }
    return 0;
}
