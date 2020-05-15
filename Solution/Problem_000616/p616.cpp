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
        long long ,
        null_type ,
        less<long long> ,
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
    long long n; 
    auto check = [](long long i , long long n){
        long long sum{};
        for(long long j=0;j<i;++j){
            if(n%i!=1){
                return false;
            }
            n-=1;
            sum+=(n/i);
            n-=(n/i);
        }
        if((n)%i!=0){
            return false;
        }
        return true;
    };
    while(cin>>n && n!=-1){
        bool answer_found = false;
        long long i;
        for(i=(sqrt(n)+1); i>=1; --i){
            if(check(i , n)){
                answer_found = true;
                goto output;
            }
        }
output:
        if(answer_found){
            cout<<n<<" coconuts, "<<i<<" people and 1 monkey\n";
        }else
            cout<<n<<" coconuts, no solution\n";
    }
    return 0;
}
