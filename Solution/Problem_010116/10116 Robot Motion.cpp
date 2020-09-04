#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int u , v , w; 
vector<string>graph;
vector<vector<int>>grid;
int ans1 , ans2;
bool check(int x , int y, int counter){
    if(x < 0 || y < 0 || x >= u || y >= v){
        ans1 =  counter;
        return false;
    }
    if(grid[x][y]!=-1){
        ans1 = grid[x][y];
        ans2 = counter - grid[x][y];
        return false;
    }
    return true;
}
int Y(int y , char dir){
    switch(dir){
        case 'N':
        case 'S':
            return y;
        case 'E':
            return y+1;
        case 'W':
            return y-1;;
    }
    assert(false);
}
int X(int x , char dir){
    switch(dir){
        case 'N':
            return x-1;
        case 'S':
            return x+1;
        case 'E':
        case 'W':
            return x;
    }
    assert(false);
}
void play(int x , int y , int counter){
    grid[x][y] = counter;
    int tx = X(x,graph[x][y]) , ty = Y(y,graph[x][y]);
    if(check(tx,ty, counter+1)){
        play(tx, ty ,counter+1);
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
    string s;
    while(cin >> u >> v >> w && (u+w+v)){
        --w;
        graph.clear();
        grid.assign(u , vector<int>(v,-1));
        for(int i=0; i<u; ++i){
            cin >> s;
            graph.push_back(s);
        }
        ans1 = -1 , ans2 =-1;
        play(0 , w , 0);
        if(ans2 == -1){
            printf("%ld step(s) to exit",ans1);
        }else{
            printf("%ld step(s) before a loop of %ld step(s)",ans1,ans2);
        }
        puts("");
    }
    return 0;
}
