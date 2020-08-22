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
    map<string, set<string>>f;
    while(cin >> s && s != "XXXXXX"){
        string temp = s;
        sort(s.begin() , s.end()); 
        f[s].insert(temp);
    }
    while(cin >> s && s != "XXXXXX"){
        sort(s.begin() , s.end()); 
        if(f[s].size() == 0){
            cout <<"NOT A VALID WORD" << '\n'; 
        }else{
            for(auto&itr:f[s]){
                cout << itr << '\n'; 
            }
        }
        cout <<"******"<<'\n';
    }
    return 0;
}
