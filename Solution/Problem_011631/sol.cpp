#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<int>>graph;
vector<int>par;
bool compare(vector<int>&a , vector<int>&b) {
    return a.at(2) < b.at(2);
}
int find_parent(int node) {
    if (node == par[node]) {
        return node; 
    }
    return par[node] = find_parent(par[node]); 
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int m , n;
    while (cin >> m >> n , m+n) {
        graph.clear();
        par.clear(); 
        int total{};
        par.resize(m+10); 
        for(int i=0; i<=m; ++i) {
            par[i] = i; 
        }
        for(int i=0; i<n; ++i) {
            vector<int>v(3); 
            for(auto&itr:v) cin >> itr; 
            graph.push_back(v);
        }
        sort(graph.begin() , graph.end() , compare); 
        int cost{}; 
        for(int i=0; i<n; ++i) {
            int u = graph.at(i).at(0); 
            int v = graph.at(i).at(1); 
            int w = graph.at(i).at(2); 
            total+=w;
            u = find_parent(u); 
            v = find_parent(v); 
            if (u != v) {
                cost += w; 
                par[u] = v; 
            }
        }
        cout << total-cost << '\n'; 
    }
    return 0;
}
