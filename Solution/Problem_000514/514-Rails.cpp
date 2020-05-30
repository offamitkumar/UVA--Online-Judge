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
#include <unordered_map>
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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n;
    while(cin >> n, n){
        int more; 
        while(cin >> more,more) { 
            bool possible = true;
            stack<int>s; s.push(0);
            int max_gone = 0;
            for (int coach,i=0; i < n; ++i){
                if(i == 0){
                    coach = more;
                }else{
                    cin >> coach;
                }
                if (!possible) {
                    continue;
                }
                if (coach < s.top()){
                    possible = false;
                } else if(coach == s.top()){
                    s.pop();
                } else {
                    int start = max(s.top(), max_gone+1);
                    for(; start <= coach; ++ start){
                        s.push(start);
                    }
                    s.pop();
                }
                max_gone = max(max_gone, coach);
            }
            puts(possible ? "Yes" : "No");
        }
        puts("");
    }
    return 0;
}
