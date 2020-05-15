#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN 101
array<string,MAXN>grid;
bool visited[MAXN][MAXN];
array<int , 8>X{-1,-1,-1,0,0,1,1,1};
array<int , 8>Y{-1,0,1,-1,1,-1,0,1};
int n;
bool check(int x, int y){
    return (x>=0 && x<n && y>=0 && y<(int)grid[0].size() && visited[x][y]==false && grid[x][y]=='W');
}
int dfs(int x, int y){
    visited[x][y] = true;
    int counter{1};
    for(int i=0;i<8;++i){
        if(check(x+X[i],y+Y[i])){
            counter+=(dfs(x+X[i] , y+Y[i]));
        }
    }
    return counter;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    cin.ignore();
    string s;
    getline(cin,s);
    while(t--){
        for(int i=0;i<MAXN;++i){
            grid[i].clear();
        }
    //    getline(cin,s);
        n=0;
        while(true){
            getline(cin,s);
            if(s[0]>='0' && s[0]<='9'){
                break;
            }
            grid[n++] = (s);
        }
        stringstream ss(s);
        while(true){
            memset(visited,false,sizeof(visited));
            int x = s[0] - '0';
            int y = s[2] - '0';
            ss>>x;
            ss>>y;
            --x;--y;
            printf("%d\n",dfs(x,y));
            if(!getline(cin,s)||s.empty()){
                break;
            }
            ss.clear();
            ss.str(s);
        }
        if(t>0){
            puts("");
        }
    }
    return 0;
}
