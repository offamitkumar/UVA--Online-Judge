#include <bits/stdc++.h>
using namespace std;
#define int int64_t
stack<int> st; 
vector<vector<int>>graph;
vector<bool>visited;
void dfs(int node){
    visited.at(node) = true;
    for(const auto&itr: graph[node]){
        if(!visited.at(itr)){
            dfs(itr);
        }
    }
    st.push(node);
}
void scc_dfs(int node){
    visited.at(node) = false;
    for(const auto&itr:graph[node]){
        if(visited.at(itr)){ scc_dfs(itr);
        }
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
    int t; cin >> t; 
    while(t--){
        graph.clear(); 
        visited.clear();
        int n , m; cin >> n >> m; 
        graph.resize(n+1); 
        visited.assign(n+1,false);
        for(int i=0 , u , v; i < m; ++i){
            cin >> u >> v; 
            graph.at(u).push_back(v);
        }
        for(int i=1; i<=n; ++i){
            if(!visited.at(i)){
                dfs(i);
            }
        }
        int knock{};
        while(!st.empty()){
            const int &x = st.top(); 
            if(visited.at(x)){
                ++knock; 
                scc_dfs(x);
            }
            st.pop();
        }
        cout << knock << '\n'; 
    }
    return 0;
}
