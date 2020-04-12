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
#define MAXN 105
vector< tuple< pair< double , double> , pair< double , double > , double > >edges; // tuple { start , end , length } 
array< pair< double , double > , MAXN>temp_edge; // storing the initially edges
map< pair< double , double> , pair< double , double> > par;
// we have to calculate the distance manually 
double length(pair< double , double >&start , pair< double , double >&end){
    // simple distance calculating function 
    // _/(x1-x2)^2 + (y1-y2)^2
    return sqrt(((abs(start.first - end.first))*(abs(start.first - end.first)))+(abs(start.second - end.second)*abs(start.second - end.second)));
}

// map to implement disjoint - Union operations 
pair< double , double > find_parent( pair< double , double > a ){
    if(par[a] == a){
        return a;
    }
    return par[a] = find_parent(par[a]);
}
// comparator 
bool compare(tuple< pair< double , double > , pair< double , double > , double >&a , tuple< pair< double , double > , pair< double , double > , double >&b){
    return get<2>(a) < get<2>(b);
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
        edges.clear();
        par.clear();
        string s;  getline(cin , s);
        int edge; cin >> edge;
        for(int i{0}; i < edge; ++i){
            double u , v; cin >> u >> v; 
            temp_edge.at(i) = {u,v};
        }
        for(int i{0}; i < edge; ++i){
            for(int j{i+1}; j < edge; ++j){
                edges.push_back(make_tuple(temp_edge.at(i) , temp_edge.at(j) , length(temp_edge.at(i) , temp_edge.at(j))));
                par[temp_edge.at(i)] = temp_edge.at(i);
                par[temp_edge.at(j)] = temp_edge.at(j);
            }
        }
        // sorting edges for kruskal's algorithm 
        sort(edges.begin() , edges.end() , compare);
        double ans{};
        for(int i{0}; i < (int)edges.size(); ++i){
            pair< double , double > a = find_parent(get<0>(edges.at(i)));
            pair< double , double > b = find_parent(get<1>(edges.at(i)));
            if(a == b){
                continue;
            }
            ans+=get<2>(edges.at(i));
            par[a] = b;
        }
        cout << fixed << setprecision(2) << ans << '\n';
        if(t!=0){
            cout << '\n' ;
        }
    }
    return 0;
}
