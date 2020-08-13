#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<int>>graph;
vector<bool>visited;
void dfs( int node ){
    for(auto&itr:graph[node]){
        if(!visited[itr]){
            visited[itr] = true; 
            dfs(itr);
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
    int n; 
    deque<int>d;
    while(cin >> n , n){
        graph.resize(n+1);
        visited.assign(n+1,false);
        int u , v; 
        while(cin >> u,u){
            while(cin >> v , v){
                graph.at(u).push_back(v);
            }
        }
        cin >> u; 
        for(int i=0; i<u; ++i){
            fill(visited.begin() , visited.end() , false);
            cin >> v; 
            dfs(v);

            for(int j=1;j<=n;++j){
                if(!visited[j]){
                    d.push_back(j);
                }
            }
            cout << d.size(); 
            while(!d.empty()){
                cout <<' ';
                cout << d.front(); 
                d.pop_front();
            }
            cout << '\n'; 
        }
        graph.clear();
        visited.clear();
    }
    return 0;
}
