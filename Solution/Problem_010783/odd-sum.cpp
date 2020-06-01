//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>
//  #include <iostream>
//  #include <chrono>
//  #include <string>
//  #include <utility>
//  #include <queue>
//  #include <stack>
//  #include <cmath>
//  #include <map>
//  #include <unordered_map>
//  #include <deque>
//  #include <unordered_set>
//  #include <set>
//  #include <climits>
//  #include <sstream>
//  #include <iomanip>
//  #include <cassert>
//  #include <bitset>
//  #include <numeric>
//  #include <vector>
//  #include <array>
//  #include <algorithm>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
#define MOD 1000000007

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//      auto initial_time = high_resolution_clock::now();
    int t; scanf("%d",&t);
    for(int tt = 1; tt <= t; ++tt){
        int u, v; scanf("%d%d",&u,&v);
        int sum{};
        for(auto i=u; i<=v; ++i){
            sum+=(i&1)?i:0;
        }
        printf("Case %d: %d\n",tt,sum);
    }
//      auto final_time = high_resolution_clock::now();
//      cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
