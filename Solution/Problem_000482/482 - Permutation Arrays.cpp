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
    int t; cin >> t; 
    cin.ignore();
    cout << fixed << setprecision(1); 
    while(t--){
        string s; 
        getline(cin,s);
        getline(cin , s); 
        istringstream s1(s); 
        vector<int>index;
        int k;
        while(s1 >> k){
            --k;
            index.push_back(k);
        }
        getline(cin , s); 
        istringstream s2(s); 
        string ss;
        vector<string>value; 
        while(s2 >> ss){
            value.push_back(ss);
        }
        vector<string>ans(index.size()); 
        int i = 0;
        for(auto&itr:index){
            ans[itr] = value[i++];
        }
        for(auto&itr:ans){
            cout<<itr<<'\n';
        }
        if(t){
            cout << '\n'; 
        }
    }
    return 0;
}
