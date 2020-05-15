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
vector< int > parent;
int find_parent(int vertex){
    if(parent[vertex] == vertex){
        return vertex;
    }
    return parent[vertex] = find_parent(parent[vertex]);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; cin >> t;
    cin.ignore();
    while(t--){
        int connection; cin >> connection;
        cin.ignore();
        parent.resize(connection+10);
        iota(parent.begin() , parent.end() , 0);
        string s;
        int success{} , fail{};
        while(getline(cin , s) && !s.empty()){
            istringstream ss(s);
            char q; int node1 , node2; ss >> q >> node1 >> node2; 
            node1 = find_parent(node1);
            node2 = find_parent(node2);
            if(q == 'c'){
                parent[node2] = node1;
            }else{
                success += (node1 == node2);
                fail += (node2 != node1);
            }
        }
        printf("%d,%d\n",success , fail);
        if(t>0){
            puts("");
        }
    }
    return 0;
}
