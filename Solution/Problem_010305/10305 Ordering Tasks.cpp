#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<int>>graph;
vector<int>dependency;
vector<int>res;
queue<int>node;
void bfs(void){
    while(!node.empty()){
        int n = node.front(); 
        res.push_back(n);
        node.pop();
        for(auto&itr:graph[n]){
            dependency[itr]--;
            if(dependency[itr]==0){
                node.push(itr);
            }
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
    int n , m; 
    while(cin >> n >> m , n+m){
        dependency.assign(n+1,0);
        res.clear();
        graph.resize(n+1); 
        for(int i=0,u,v; i<m;++i){
            cin >> u >> v; 
            graph.at(u).push_back(v);
            dependency.at(v)++;
        }
        for(int i=1;i<=n;++i){
            if(dependency.at(i)==0){
                node.push(i);
            }
        }
        bfs();
        for(int i=0;i<n;++i){
            if(i){
                cout <<' ';
            }
            cout << res[i];
        }
        graph.clear();
        cout << '\n'; 
    }
    return 0;
}
