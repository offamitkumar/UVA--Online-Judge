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
    int t; scanf("%d",&t);
    while(t--){
        long long a,b;  cin>>a>>b;
        vector<int>v;
        for(int i=1;i<=sqrt(b);++i){
            if(b%i==0){
                v.push_back(i);
                if(b/i !=i){
                    v.push_back(b/i);
                }
            }
        }
        sort(v.begin() , v.end());
        for(auto&itr:v){
            if(((itr*a)/__gcd(a,(long long)itr))==b){
                cout<<itr<<'\n';
                goto hell;
            }
        }
        cout<<"NO SOLUTION"<<'\n';
hell:
        continue;
    }
    return 0;
}
