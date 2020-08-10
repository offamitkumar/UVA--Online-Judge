#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>parent, group_size;
int find_parent(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n , m;
    while(cin >> n >> m , n+m){
        int par = 30011;
        parent.resize(n+90000); 
        group_size.assign(n+90000,0); 
        fill(group_size.begin(), group_size.begin() + n,1);
        iota(parent.begin() , parent.end() , 0);
        for(int i=0;i<m;++i){
            int k; cin >> k; 
            bool zero_parent = false;
            for(int j=0;j<k;++j){
                int l; cin >> l; 
                l = find_parent(l); 
                if(l == 0){
                    zero_parent = true;
                    continue;
                }
                if(l == par){
                    continue;
                }
                parent[l] = par; 
                group_size[par] += group_size[l];
            }
            if(zero_parent){
                parent[par] = 0; 
                group_size[0] += group_size[par];
            }
            ++par;
        }
        cout << group_size[0] << '\n'; 
    }
    return 0;
}
