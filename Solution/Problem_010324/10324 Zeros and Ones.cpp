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
    int n;
    int counter{1};
    while(cin >> s >> n && (s != "0" && n != 0)){
        cout <<"Case " << counter++ <<":" << '\n'; 
        vector<int>v((int)s.size());
        int one = 1 , zero = 1;
        for(int i=0; i<(int)s.size();++i){
            if(s[i]=='0'){
                v[i] = zero++;
            }else{
                v[i] = one++;
            }
        }
        while(n--){
            int U , V; cin >> U >> V; 
            if(abs(V-U) == abs(v[U] - v[V])){
                cout << "Yes";
            }else{
                cout << "No" ;
            }
            cout << '\n'; 
        }
    }
    return 0;
}
