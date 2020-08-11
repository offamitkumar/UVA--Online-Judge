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
    vector<map<char,int>>v; 
    while(cin >> s && s!="#"){
        map<char,int>f; 
        for(auto&itr:s){
            f[itr]++;
        }
        v.emplace_back(f);
    }
    getline(cin,s); 
    while(getline(cin,s) && s!="#"){
        istringstream ss(s); 
        map<char, int>f;
        while(ss >> s){
            f[s[0]]++;
        }
        int counter{};
        for(int i=0; i<v.size(); ++i){
            bool ok = true;
            for(auto itr = v[i].begin(); itr != v[i].end(); ++itr){
                ok &= ((f[itr->first]) && f[itr->first]>= itr->second);
            }
            counter += ok;
        }
        cout << counter << '\n'; 
    }
    return 0;
}
