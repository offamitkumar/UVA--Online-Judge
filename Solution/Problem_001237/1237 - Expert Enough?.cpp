//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
//  #include <algorithm>
  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
//  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
//  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
//  #include <deque>

//  #include <climits>
//  #include <cstring>
//  #include <cmath>
//  #include <cassert>
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
const int MAXM = (int)1e5+100;
const int MAXN = (int)1e6+100;
const int MOD = (int)1e5+100;
string arr[MAXN];
int low_cost[MAXN], high_cost[MAXN];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int t; cin >> t;
    bool more = false;
    while(t--){
        if(more){
            cout << '\n';
        }
        more = true;
        int n; cin >> n;
        for(int i=0;i<n;++i){
            cin >> arr[i] >> low_cost[i] >> high_cost[i];
        }
        int  q;
        cin >> q;
        while(q--){
            int p; cin >> p;
            string company_name{"UNDETERMINED"};
            int participents = 0;
            for(int i=0;i<n;++i){
                if(p >= low_cost[i] && p<=high_cost[i]){
                    company_name = arr[i];
                    ++participents;
                    if(participents>1){
                        company_name = "UNDETERMINED";
                        break;
                    }
                }
            }
            cout << company_name << '\n'; 
        }
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
