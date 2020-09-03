#include <bits/stdc++.h>
using namespace std;
#define int int64_t
map<char , char> clean(string s){
    map<char , char>f; 
    f[s[0]] = s[2]; 
    f[s[4]] = s[6]; 
    f[s[8]] = s[10]; 
    f[s[12]] = s[14]; 
    f[s[16]] = s[18];
    return f;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string s; 
    while(true){
        int ans = 0 , mx_counter{};
        vector<pair<string,int>>v;
        while(cin >> s && s[0]!='e'){
            if(s[0]=='#'){
                return 0;
            }
            v.push_back(make_pair(s , 0));
        }
        int n = v.size();
        for(int i=0; i<n;++i){
            auto f1 = clean(v.at(i).first);
            int counter{};
            for(int j=0;j<n;++j ){
                auto f2 = clean(v.at(j).first);
                for(auto&itr:f1){
                    if(itr.second == f2[itr.first]){
                        ++counter;
                    }
                }
            }
            v.at(i).second = counter;
            if(counter > mx_counter){
                ans = i+1;
                mx_counter = counter;
            }
        }
        cout << ans << '\n';
        if(s[0]=='#'){
            break;
        }
    }
    return 0;
}
