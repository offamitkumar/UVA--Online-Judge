#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<string>>graph;
vector<vector<vector<bool>>>visited;

const int DSIZE = 4;
array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};
int n,m,o;
bool check(int zz, int xx , int yy) {
    if (xx < 0 || yy < 0 || zz < 0 || xx>=n  || yy>=m || zz>=o || visited[zz][xx][yy] || graph[zz][xx][yy] =='#') {
        return false;
    }
    return true;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    tuple<int,int,int>start, End;
    int x, y, z; 
    while (cin >> z >> x >> y && x+y+z) {
        n = x; 
        m = y;
        o = z;
        graph.clear();
        visited.clear();
        graph.resize(z, vector<string>(x));
        visited.resize(z, vector<vector<bool>>(x, vector<bool>(y,false)));
        for (int i=0; i<z; ++i) {
            for (int j=0; j<x; ++j) {
                cin >> graph[i][j]; 
                for (int k=0; k<y; ++k) {
                    if (graph[i][j][k] == 'S') {
                        start = make_tuple(i,j,k);
                    } else if (graph[i][j][k] == 'E') {
                        End = make_tuple(i,j,k);
                    }
                }
            }
        }
        queue<int> q; 
        q.push(get<0>(start)); 
        q.push(get<1>(start)); 
        q.push(get<2>(start)); 
        q.push(0);
        int ans = -1;
        while (!q.empty()) {
            z = q.front(); q.pop(); 
            x = q.front(); q.pop(); 
            y = q.front(); q.pop(); 
            int t = q.front(); q.pop(); 
            if (z == get<0>(End) && x == get<1>(End) && y == get<2>(End)) {
                ans = t;
                break;
            }
            visited[z][x][y] = true; 
            for (int i=0; i < DSIZE; ++i) {
                int tx = x + X[i]; 
                int ty = y + Y[i];
                if (check(z,tx,ty)) {
                    visited[z][tx][ty] = true;
                    q.push(z); 
                    q.push(tx); 
                    q.push(ty);
                    q.push(t+1);
                }
            }
            if (check(z-1,x,y)) {
                    visited[z-1][x][y] = true;
                    q.push(z-1); 
                    q.push(x); 
                    q.push(y);
                    q.push(t+1);
            }
            if (check(z+1,x,y)) {
                    visited[z+1][x][y] = true;
                    q.push(z+1); 
                    q.push(x); 
                    q.push(y);
                    q.push(t+1);
            }
        }
        if (ans != -1) {
            printf("Escaped in %ld minute(s).\n",ans);
        } else {
            puts("Trapped!");
        }
    }
    return 0;
}
