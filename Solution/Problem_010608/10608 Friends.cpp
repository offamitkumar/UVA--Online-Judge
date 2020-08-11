#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>parent,group_size;
int find_parent(int node){
    if(node == parent.at(node)){
        return node;
    }
    return parent.at(node) = find_parent(parent.at(node));
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
    while(t--){
        int n , m; cin >> n >> m; 
        parent.resize(n+1); 
        group_size.assign(n+1,1);
        iota(parent.begin() , parent.end() , 0);
        int max_group=1;
        for(int i=0; i<m;++i){
            int u , v; cin >> u >> v; 
            u = find_parent(u); 
            v = find_parent(v);
            if(u == v){continue;}
            parent[u] = v; 
            group_size[v] += group_size[u]; 
            max_group = max(max_group , group_size[v]);
        }
        cout << max_group << '\n'; 
    }
    return 0;
}
