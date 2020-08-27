#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<string>graph;
int m, n, xc, yc; 
bool our = false; 
const int DSIZE = 4;
array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};
char ch;
bool check(int x, int y){
    if(x<0 || x>=n || graph[x][y]!=ch){
        return false;
    }
    return true;
}
int dfs(int x, int y){
    int counter = 1; 
    if(x == xc && y == yc){
        our = true;
    }
    graph[x][y] = '$';
    for(int i=0; i<DSIZE;++i){
        int tx = x + X[i]; 
        int ty = y + Y[i];
        ty = (ty + m) % m; 
        if(check(tx , ty)){
            counter += dfs(tx, ty);
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
    while(cin >> n >> m){
        graph.resize(n); 
        for(auto&itr:graph){
            cin >> itr;
        }
        cin >> xc >> yc; 
        ch = graph[xc][yc];
        int size=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m;++j){
                if(graph[i][j]==ch){
                    our = false;
                    int x = dfs(i,j);
                    if(not(our)){
                        size = max(size , x);
                    }
                    our = false;
                }
            }
        }
        cout << size << '\n'; 
    }
    return 0;
}
