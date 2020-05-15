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
#define MAXN 6
bool v[MAXN][MAXN];
int g[MAXN][MAXN];
vector<string>ans;
void sol(int c , string p , int e){
    if(e==8){
        ans.push_back(p);
        return;
    }
    for(int i{};i<=5;++i){
        if(g[c][i] && !v[c][i]){
            p.push_back(char(i+'0'));
            v[c][i]=true;
            v[i][c]=true;
            sol(i,p,e+1);
            v[c][i]=false;
            v[i][c]=false;
            p.pop_back();
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    memset(v,0,sizeof(v));
    memset(g,0,sizeof(g));
    vector<pair<int,int>>v{{1,5},{1,3},{1,2},{2,5},{2,3},{3,5},{3,4},{4,5}};
    for(auto&itr:v){
        g[itr.first][itr.second]=1;
        g[itr.second][itr.first]=1;
    }
    string s="1";
    sol(1,s,0);
    sort(ans.begin(),ans.end());
    for(auto&itr:ans)
        cout<<itr<<'\n';
    return 0;
}
