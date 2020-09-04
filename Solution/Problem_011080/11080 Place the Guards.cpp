#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<int>>graph;
vector<bool> Color;
vector<bool>visited;
int bCounter{} , wCounter{};
int compSize =0;
// 1 = white color 
// 0 = black color
bool dfs(int node, int color){
    Color.at(node) = 1^color; 
    compSize++;
    visited.at(node) = true;
    if(Color.at(node)==0){
        bCounter++;
    }else{
        wCounter++;
    }
    bool isbi = true;
    for(auto&itr:graph[node]){
        if(!visited.at(itr)){
            isbi &= dfs(itr, Color.at(node));
        }
        if(Color.at(node) == Color.at(itr)){
            isbi = false;
        }
    }
    return isbi;
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
        graph.clear();
        visited.clear();
        int ans = 0;
        Color.clear();
        graph.resize(n+1); 
        visited.assign(n+1,false);
        Color.resize(n+1,-1);
        for(int i=0,u , v; i<m;++i){
            cin >>u >> v; 
            graph.at(u).push_back(v);
            graph.at(v).push_back(u);
        }
        bool isbi = true;
        for(int i=0; i<n && isbi;++i){
            compSize = 0;
            bCounter = 0; 
            wCounter = 0;
            if(!visited.at(i)){
                isbi &= dfs(i , 0);
            }
            if(compSize==1){
                ++ans;
            }else{
                ans+=min(wCounter, bCounter);
            }
        }
        if(isbi){
            cout <<ans<< '\n';
        }else{
            cout << -1 << '\n';
        }
    }
    return 0;
}
