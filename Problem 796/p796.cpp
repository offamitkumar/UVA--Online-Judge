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
// containers

vector< vector< int       > >graph;
vector< pair  < int , int > > ans;
vector< int                 > in_time;
vector< int                 > out_time;
vector< bool                > visited;

int timer;

// solution function to compute the bridge 
void solution(int current_node , int parent ){
   in_time.at(current_node) = out_time.at(current_node) = timer++; 
   visited.at(current_node) = true;
   // explore the childs
   for(auto &itr:graph[current_node]){
       if(itr == parent){
           continue;
       }
       if(!visited.at(itr)){
           solution(itr , current_node);
           if(out_time.at(itr)>in_time.at(current_node)){
               // this is a bridge 
               ans.push_back({min(current_node ,itr) , max(current_node , itr)});
           }
           out_time.at(current_node) = min(out_time.at(current_node) , out_time.at(itr));
       }else{
           out_time.at(current_node) = min(out_time.at(current_node) , in_time.at(itr));
       }
   }
}



int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int no_of_server;
    while( cin >> no_of_server){
        cin.ignore();

        // cleaning part
        timer = 1;
        in_time.assign(no_of_server,0);
        out_time.assign(no_of_server,0);
        visited.assign(no_of_server,false);
        graph.resize(no_of_server);
        string s;

        // input part
        for(int i{0}; i < no_of_server; ++i){
            getline(cin , s);
            istringstream ss(s);
            int u; ss >> u;
            char dummy_char; ss >> dummy_char;
            int node; ss >> node;
            graph.at(u).assign(node , 0);
            ss >> dummy_char;
            int v;
            for(int j{0}; j < node; ++j){
                ss >> v;
                graph.at(u).at(j) = (v);
            }
        }

        for(int i{0}; i < no_of_server; ++i){
            if(!visited.at(i)){
                solution(i , -1); // root node is assigned -1 as parent 
            }
        }
        sort(ans.begin() , ans.end());
        printf("%d critical links\n",(int)ans.size());
        for(auto &itr:ans){
            printf("%d - %d\n",itr.first , itr.second);
        }
        puts("");
        for(int i{0}; i < no_of_server; ++i){
            graph.at(i).clear();
        }
        graph.clear();
        ans.clear();
        visited.clear();
        in_time.clear();
        out_time.clear();
//        getline(cin,s);
//        for(int i{0}; i < no_of_server; ++i){
//            printf("%d (%d) ",i , (int)graph.at(i).size());
//            for(int j{0}; j < (int)graph.at(i).size(); ++j){
//                cout << graph.at(i).at(j) << ' ';
//            }
//            cout << '\n'; 
//        }
    }
    return 0;
}
