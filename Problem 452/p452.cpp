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
#define MAXN 200
array< vector< char > , MAXN > graph;
array< int , MAXN > time_need , dist , in_degree;
set< char > zero_degree_nodes;

void topsort(void){
    while(!zero_degree_nodes.empty()){
        char current_node = *zero_degree_nodes.begin();
        dist[current_node] += time_need[current_node];
        zero_degree_nodes.erase(current_node);
        for(auto&itr:graph[current_node]){
            in_degree[itr]--;
            dist[itr] = max(dist[itr] , dist[current_node]);
            if(in_degree[itr] == 0){
                zero_degree_nodes.insert(itr);
            }
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    string s;
    cin.ignore();
    getline(cin , s);
    while(t--){
        fill(dist.begin() , dist.end() , 0);
        fill(in_degree.begin() , in_degree.end() , 0);
        fill(time_need.begin() , time_need.end() , 0);
        for(int i{}; i < MAXN; ++i){
            graph.at(i).clear();
        }
        while(getline(cin , s) && !s.empty() && s!=" "){
            //cerr<<s<<'\n';
            istringstream ss(s);
            char current ; 
            int delay;
            string dependency; // nodes on which current node depends

            ss >> current >> delay >> dependency;

            time_need.at(current) = delay;

            if(in_degree[current] == 0){
                zero_degree_nodes.insert(current);
            }

            for(auto &itr: dependency){
                graph.at(itr).push_back(current);
                in_degree[current]++;

                if(in_degree[itr] == 0){
                    zero_degree_nodes.insert(itr);
                }else if(zero_degree_nodes.find(itr) != zero_degree_nodes.end()){
                    zero_degree_nodes.erase(itr);
                }
            }

            if(in_degree[current] != 0){
                zero_degree_nodes.erase(current);
            }
        }

        //cerr<<"this is first time"<<'\n';
        topsort();
        cout << *max_element(dist.begin() , dist.end() ) << '\n' ;
        if(t>0){
            cout << '\n' ;
        }
    }
    return 0;
}
