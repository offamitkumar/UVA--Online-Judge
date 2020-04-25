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
#define MAXN 219
#define SEPARATOR 104
#define SOURCE 217
#define SINK 218
// we need SEPARATOR to separate the hole from gopher  in the same graph
int graph[MAXN][MAXN];
int par[MAXN];
pair<double,double>gl[MAXN]/*gopher location*/, hl[MAXN]/*hawk location*/;
bool reachable(pair<double,double>&p1 , pair<double,double>&p2 , int s,int v){
    double x = (p1.first-p2.first)*(p1.first-p2.first);
    double y = (p1.second-p2.second)*(p1.second-p2.second);
    double l = sqrt(x+y);
    bool ok = (s>(l/(double)v));
    return ok;
}
int vis[MAXN]; // vis[i] is true if ith node is  already visited
bool BFS(void){
    memset(vis,0,sizeof(vis));
    memset(par,0,sizeof(par));
    queue<int>q; q.push(SOURCE);
    vis[SOURCE] = true;
    bool path_found_sink{false}; // at the end this will tell whether path is present or not
    while(!q.empty()){
        int current_node  = q.front();
        q.pop();
        if(current_node == SINK){
            return true;
        }
        for(int i=0;i<MAXN;++i){
            if(graph[current_node][i]>0 && !vis[i]){ // there exist a path (might be residual / normal)
                if(i==SINK){
                    par[i] = current_node;
                    return true;
                }
                q.push(i);
                vis[i] =true;
                par[i] = current_node;
            }
        }
    }
    return path_found_sink;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
#endif 
    int n,m,s,v;
    while(cin>>n>>m>>s>>v){
        memset(graph , 0 , sizeof(graph));
        for(int i{};i<n;++i){
            cin>>gl[i].first>>gl[i].second;
            //cerr<<gl[i].first<<gl[i].second<<'\n';;
        }
        for(int i{};i<m;++i){
            cin>>hl[i].first>>hl[i].second;
        }
        // connection to source
        for(int i{};i<n;++i){ // every gopher is connected to the source
            graph[SOURCE][i] = 1;
        }
        //middle connection 
        for(int i{};i<n;++i){// for every gopher
            for(int j{};j<m;++j){ // check if jth hole is reachable or not
                // if reachable then assign this to it
                if(reachable(gl[i],hl[j] , s,v)){
        //            printf("reachable [%lf,%lf] & [%lf,%lf]\n",gl[i].first,gl[i].second,hl[j].first,hl[j].second);
                    graph[i][SEPARATOR+j]=1;
                }
            }
        }
        // SINK connection 
        for(int j{};j<m;++j){// every hole is connected to the sink
            graph[SEPARATOR+j][SINK] = 1;
        }

        int max_flow{};
        while(BFS()){
            // as flow is given to be 1 
            // so if there exist a augmented path then we already know the flow must be 1
            int v = SINK;
            int flow{INT_MAX};
            while(v!=SOURCE){
                int u = par[v];
                if(flow > graph[u][v]){
                    flow = graph[u][v];
                }
                v = u;
            }v = SINK;
            max_flow+=flow;
            while(v != SOURCE){
                int u = par[v];
                graph[u][v]-=1;
                graph[v][u]+=1;
                v = u;
            }
        }
        // currently know maximum number of gopher saved but we have to answer the
        // query that how many gopher are eliminated 
        //
        //
        //
//        cerr<<"n = "<<n<<'\n';
//        cerr<<"max flow = "<<max_flow<<'\n';
        cout<< n - max_flow << '\n';
    }
    return 0;
}
