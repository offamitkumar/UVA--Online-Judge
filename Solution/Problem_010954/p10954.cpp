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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    while(scanf("%d",&n) && n != 0){
        priority_queue<long long , vector<long long> , greater<long long> >pq;
        for(int i{0}; i < n ; ++i){
            long long x; scanf("%lld",&x);
            pq.push(x);
        }
        long long cost{};
        while(pq.size()>=2){
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            cost+=(x+y);
            pq.push(x+y);
        }
        printf("%lld\n",cost);
    }
    return 0;
}
