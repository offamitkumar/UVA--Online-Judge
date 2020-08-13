#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int DSIZE = 8;
int X[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
int Y[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
vector<vector<int>>dist;
bool ok(int u , int v){
    if(u <= 0 || v <= 0 || u >= 9 || v>=9){
        return false;
    }
    return true;
}
int bfs(int a, int b, int c, int d){
    queue<int>q; 
    q.push(a); q.push(b); 
    dist[a][b] =0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int v = q.front(); q.pop();
        if(u == c && v == d){
            return dist[u][v]; 
        }
        for(int i=0; i<DSIZE;++i){
            if(ok(u+X[i],v+Y[i])){
                q.push(u+X[i]);
                q.push(v+Y[i]);
                dist[u+X[i]][v+Y[i]] = min((int)dist[u+X[i]][v+Y[i]] ,(int)dist[u][v]+(int)1);
            }
        }
    }
    assert(false);
    return -1;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    map<char,int>f;
    int i{1};
    for(char ch='a'; ch<='h';++ch){
        f[ch] = i++;
    }
    char a,b; int c,d;
    while(cin >> a >>  c >> b >> d){
        dist.assign(9,vector<int>(9,INT_MAX));
        cout.flush(); 
        printf("To get from %c%d to %c%d takes %d knight moves.\n",a,c,b,d,bfs(f[a],c,f[b],d));
        dist.clear();
    }
    return 0;
}
