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
#define MAXN 30
int graph[MAXN][MAXN]; //graph
int d[MAXN]; // degree
int c[MAXN];
int dij(int s , int e){
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push(make_pair(0,s));
    c[s] = 0;
    bool vi[MAXN];memset(vi,false,sizeof(vi));
    vi[s]=true;
    while(!pq.empty()){
        int cn,co;
        tie(co,cn)=pq.top();pq.pop();
        if(cn==e)
            return co;
        for(int i=0;i<MAXN;++i){
            if(graph[cn][i]!=0){
                if(c[i]>graph[cn][i]+co){
                    c[i]= graph[cn][i]+co;
                    pq.push(make_pair(c[i],i));
                }
                if(!vi[i]){
                    pq.push(make_pair(c[i],i));
                }
                vi[i]=true;
            }
        }
    }

}
int ans(void){ int ans{};
    bool io=false;
    int arr[2],in{};
    for(int i=0;i<MAXN;++i){
        c[i]=INT_MAX;
        io|=(d[i]%2);
        if(d[i]%2){
            arr[in++] = i;
        }
    }
    for(int i=0;i<MAXN;++i){
        for(int j=i+1;j<MAXN;++j){
            ans+=graph[i][j];
        }
    }
    if(!io){
        return ans;
    }else{ 
        return ans+dij(arr[0],arr[1]);
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    string s;
    while(cin >> s && s!="deadend"){
        memset(graph,0,sizeof(graph));
        memset(d,0,sizeof(d));
        do{
            int u = s[0]-'a' , v = s[s.size()-1]-'a' , w = (int)s.size();
            graph[u][v] =w;
            graph[v][u] =w;
            d[u]+=1;
            d[v]+=1;
        }while(cin >> s && s!="deadend");
        cout<<ans()<<'\n';
    }
    return 0;
}
