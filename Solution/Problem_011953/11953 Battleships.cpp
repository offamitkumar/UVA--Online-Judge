#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<string>graph;
int n; 
const int DSIZE = 4;
array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};
bool check(int x , int y){
    if(x <0 || y < 0 || x>=n || y >=n || graph[x][y]=='.' || graph[x][y]=='$'){
        return false;
    }
    return true;
}
void dfs(int x, int y){
    graph[x][y] = '$';
    for(int i=0; i<DSIZE; ++i){
        int tx = x+X[i];
        int ty = y+Y[i];
        if(check(tx,ty)){
            dfs(tx,ty);
        }
    }
    return ;
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
    for(int ii=1; ii<=t; ++ii){
        graph.clear();
        cin >> n; 
        graph.resize(n); 
        for(int i=0; i<n;++i){
            cin >> graph.at(i);
        }
        int counter{};
        for(int i=0; i<n;++i){
            for(int j=0; j<n;++j){
                if(graph[i][j]=='x'){
                    ++counter;
                    dfs(i,j);
                }
            }
        }
        printf("Case %ld: %ld\n",ii , counter);
    }
    return 0;
}
