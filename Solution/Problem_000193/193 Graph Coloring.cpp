#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<int>>graph;
vector<int>color; 
vector<int>bestcolor;
int best{};
void bipartite(int node , int c, int blackNode) {
    if (node == (int)graph.size()) {
        if (blackNode > best) {
            best = blackNode; 
            bestcolor =color;
        }
        return;
    }
    bool ok=true;
    for (auto&itr: graph[node]) {
        ok&= (color.at(itr) != 1);
    }
    if (ok) {
        color.at(node) = 1; 
        bipartite(node+1 , c+1 , blackNode+1);
    }
    color.at(node) = 2; 
    bipartite(node+1 , c+1 , blackNode);
    color.at(node) = 0;
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
    while (t--) {
        graph.clear();
        color.clear();
        best = 0;
        bestcolor.clear();
        int n , m; cin >> n >> m; 
        graph.resize(n+1);
        color.assign(n+1,0);
        while (m--) {
            int u , v; 
            cin >> u >> v; 
            graph.at(u).push_back(v); 
            graph.at(v).push_back(u);
        }
        for (int i=1; i<=n; ++i)
            bipartite(i , 0 , 0);
        bool printed = false;
        cout << best << '\n'; 
        for (int i=1; i<=n; ++i) {
            if (bestcolor.at(i) == 1) {
                if (printed) cout << ' ';
                printed = true;
                cout << i;
            }
        }
        cout << '\n'; 
    }
    return 0;
}
