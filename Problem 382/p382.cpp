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
    puts("PERFECTION OUTPUT");
    int n;
    while(cin>>n && n!=0){
        int sum{0};
        for(int i=1;i<=(n/2);++i){
            sum+=((n%i)?0:i);
            if(sum>n)
                goto output;
        }
output:   
        cout<<setw(5);
        cout<<n<<"  ";
        puts((n==sum)?"PERFECT":(n<sum)?"ABUNDANT":"DEFICIENT");
    }
    puts("END OF OUTPUT");
    return 0;
}
