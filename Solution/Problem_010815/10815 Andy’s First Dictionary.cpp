#include <bits/stdc++.h>
using namespace std;
#define int int64_t
set<string>st; 
void process(string &s){
    string res{};
    for(auto&itr:s){
        if(isalpha(itr)){
            itr = char(tolower(itr));
            res+=itr;
        }else{
            if(res.size() != 0){
                st.insert(res);
            }
            res.clear();
        }
    }
    if(res.size() != 0){
        st.insert(res);
    }
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
    while(getline(cin, s)){
        if(s.size() == 0){continue;}
        istringstream ss(s); 
        while(ss >> s){
            process(s);
        }
    }
    for(auto&itr:st){
        cout << itr << '\n' ;
    }
    return 0;
}
