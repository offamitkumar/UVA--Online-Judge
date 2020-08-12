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
    vector<pair<int,int>>v; 
    int u,v1,w; 
    while(cin >> u >> v1 >> w){
        v.push_back(make_pair(u,-v1));
        v.push_back(make_pair(w,v1));
    }
    sort(v.begin(),v.end());
    multiset<int>m{0};
    int pre{},cur{};
    vector<int>res;
    for(auto&itr:v){
        if(itr.second<0){
            m.insert(-itr.second);
        }else{
            m.erase(m.find(itr.second));
        }
        cur = *m.rbegin(); 
        if(cur != pre){
            res.push_back(itr.first); 
            res.push_back(cur);
            pre = cur;
        }
    }
    for(int i=0; i<(int)res.size();++i){
        if(i){
            cout << ' '; 
        }
        cout << res.at(i);
    }
    cout << endl;
    return 0;
}
