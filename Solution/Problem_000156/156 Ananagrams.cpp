#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool Equal(const string &a , const string &b){
    if(a.size() != b.size()){
        return false;
    }
    map<char,int>f; 
    for(auto&itr:a){
        f[char(tolower(itr))]++;
    }
    for(auto&itr:b){
        f[char(tolower(itr))]--;
    }
    for(auto&itr:f){
        if(itr.second != 0){
            return false;
        }
    }
    return true;
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
    vector<string>v;
    while(getline(cin ,s) && s!="#"){
        istringstream ss(s);
        while(ss >> s){
            v.push_back(s);
        }
    }
    set<string>st;
    for(int i=0; i<(int)v.size();++i){
        bool ok=true;
        for(int j = 0; j<(int)v.size() && ok;++j){
            if(i==j)continue;
            if(Equal(v[i],v[j])){
//                 if(v[i]=="BOuT"){
//                     cerr << v[j];
//                     return 0;
//                 }
                ok=false;
            }
        }
        if(ok){
            st.insert(v[i]);
        }
    }
    for(auto&itr:st){
        cout<<itr<<'\n';
    }
    return 0;
}
