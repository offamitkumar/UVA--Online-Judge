#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<string>graph;
const int DSIZE = 8;
array<int,8>X{-1,-1,-1,0,0 ,1,1,1};
array<int,8>Y{-1, 0, 1,1,-1,1,-1,0};
int u , v;
bool check(int x, int y){
    if(x < 0 || y < 0 || x >= u || y >= v || graph[x][y]=='.' || graph[x][y]=='$'){
        return false;
    }
    return true;
}
int dfs(int x , int y){
    int counter = 1; 
    graph[x][y] = '$';
    for(int i=0; i<8; ++i){
        int tx = x+X[i];
        int ty = y+Y[i];
        if(check(tx,ty)){
            counter+=dfs(tx,ty);
        }
    }
    return counter;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    while(cin >> u >> v , u + v){
        graph.resize(u); 
        for(auto&itr:graph){
            cin >> itr;
        }
        int star{};
        for(int i=0; i<u; ++i){
            for(int j=0; j<v; ++j){
                if(graph[i][j] == '*'){
                    star+=(dfs(i,j)==1);
                }
            }
        }
        cout << star << '\n'; 
    }
    return 0;
}
