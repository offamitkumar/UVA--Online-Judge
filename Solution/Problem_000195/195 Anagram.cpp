#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool compare(string &a , string &b){
    for(int i=0; i<(int)a.size();++i){
        if(a[i]==b[i])continue;
        if(tolower(a[i]) == tolower(b[i])){
            if(isupper(a[i])){
                return true;
            }else{
                return false;
            }
        }else if((isupper(a[i]) && isupper(b[i])) || (islower(a[i]) && islower(b[i]))){
            return a[i] < b[i];
        }else{
            return char(tolower(a[i])) < char(tolower(b[i]));
        }
    }
    return false;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    string s;
    while(t--){
        cin >> s; 
        sort(s.begin() , s.end());
        set<string>st;
        do{
            st.insert(s);
        }while(next_permutation(s.begin() , s.end()));
        vector<string>ans(st.begin() , st.end());
        sort(ans.begin() , ans.end() , compare);
        for(auto&itr:ans){
            cout << itr << '\n'; 
        }
    }
    return 0;
}
