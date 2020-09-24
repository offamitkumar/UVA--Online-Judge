#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool compare(pair<int,int>&a , pair<int,int>&b) {
    if(a.second == b.second) {
        return a.first > b.first; 
    }else {
        return a.second < b.second; 
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
    bool more = false;
    while(getline(cin,s)){
        if(more) {
            cout << '\n'; 
        }
        more = true;
        map<int,int>f; 
        for(auto&itr:s){
            f[(int)itr]++; 
        }
        vector<pair<int,int>>v; 
        for(auto&itr:f){
            v.push_back(itr);
        }
        sort(v.begin() , v.end() , compare);
        for(auto&itr:v) {
            cout << itr.first << ' ' << itr.second << '\n'; 
        }
    }
    return 0;
}
