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


// max flow 


int residual_capacity[40][40];
int parent[40];
int visited[40];
void print(int i){
    for(int j=1;j<27; ++j){
        if(residual_capacity[i][j]==1){
            printf("%c" , j+'A'-1);
            return;
        }
    }
    printf("_");
    return;
}

bool BFS(int source , int sink){
    memset(visited , 0, sizeof(visited));
    memset(parent , -1 , sizeof(parent));
    queue< int > q;
    q.push(source);
    bool found_path{false};
    visited[source] = true;
    while(!q.empty() && found_path == false){
        int current_node = q.front();
        q.pop();
        for(int i=0; i < 38; ++i){
            if(residual_capacity[current_node][i] > 0 && !visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = current_node;
                if(i == sink){
                    found_path = true;
                    break;
                }
            }
        }
    }
    return found_path;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    string s;
    while(getline(cin , s) && !s.empty()){
        memset(residual_capacity , 0 , sizeof(residual_capacity));
        int total_flow{};
        do{
            istringstream ss(s);
            char a , b; ss >> a >> b;
            residual_capacity[0][a-'A'+1] = b-'0';
            total_flow += b - '0';
            char digit;
            while( ss >> digit && digit != ';' ){
                residual_capacity[a-'A'+1][digit-'0'+27] = 1;
            }
        }while(getline(cin ,s) && !s.empty() && s != " ");
        for(int i=27;i<37; ++i){
            residual_capacity[i][37] = 1;
        }
        int source = 0  , sink = 37; 
        memset(parent , -1 , sizeof(parent));
        int max_flow = 0;
        while(BFS(source , sink)){
            int flow = INT_MAX;
            int v = sink;
            while(v != source){
                int u = parent[v];
                if(flow > residual_capacity[u][v]){
                    flow = residual_capacity[u][v];
                }
                v = u;
            }

            max_flow += flow;

            v = sink;
            while(v != source){
                int u = parent[v];
                residual_capacity[u][v] -= flow;
                residual_capacity[v][u] += flow;
                v = u;
            }
        }

        if(max_flow == total_flow){
            for(int i=27; i<37; ++i){
                print(i);
            }
        }else{
            printf("!");
        }
        puts("");
    }
    return 0;
}
