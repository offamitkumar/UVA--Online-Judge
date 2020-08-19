#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool subseq(const string&s , const string &t){
    int i =0; 
    for(int j=0;j<(int)t.size(); ++j){
        if(s[i] == t[j]){
            ++i;
            if(i == s.size()){
                return true;
            }
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
    string s ,t; 
    while(cin >> s >> t){
        if(subseq(s,t)){
            cout <<"Yes";
        }else{
            cout <<"No";
        }
        cout << '\n';
    }
    return 0;
}
