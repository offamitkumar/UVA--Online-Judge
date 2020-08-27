#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<string>graph;
int x_p{};
const int DSIZE = 8;
array<int,8>X{-1,-1,-1,0,0 ,1,1,1};
array<int,8>Y{-1, 0, 1,1,-1,1,-1,0};
bool check(int x, int y){
    if(x<0 || y <0 || x>=x_p || y>=graph[x].size()|| graph[x][y]!=' '){
        return false;
    }
    return true;
}
void dfs(int x, int y){
    graph[x][y] = '#';
    for(int i=0; i<8; ++i){
        int tx = x+X[i];
        int ty = y+Y[i];
        if(check(tx,ty)){
            dfs(tx,ty);
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
    int t; cin >> t; cin.ignore();
    string s;
    while(t--){
        graph.clear();
        pair<int,int>point;
        x_p = 0;
        while(true){
            getline(cin , s);
            if(s[0]=='_')break;
            bool ok = true;
            graph.emplace_back(s);
            for(int i=0; i<(int)s.size() && ok;++i){
                if(graph[x_p][i]=='*'){
                    point.first = x_p; 
                    point.second = i;
                    ok = false;
                }
            }
            ++x_p;
        }
        dfs(point.first , point.second);
        int v{};
        for(auto&itr:graph){
            cout << itr << '\n'; 
            v = max(v , (int)itr.size());
        }
        cout << s <<'\n'; 
    }
    return 0;
}
