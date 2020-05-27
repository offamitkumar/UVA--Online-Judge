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
    map<int , pair<int,int>>f_counter; // keep record of when number appeared, what is number , what is it's frequency
    map<int , int> appearing_place; // keep record of when is this number appeared , so that  we can increase it's frequency 
    int number =1 , n;
    while(cin>>n){
        if(appearing_place.find(n) != appearing_place.end()) {
            const int &loc = appearing_place[n];
            f_counter[loc].second++;
        }else{ // this number is seen first time 
            appearing_place[n] = number++; // increase number for next new number slot 
            const int &loc = appearing_place[n];
            f_counter[loc] = make_pair(n , 1);
        }
    }
    for(auto&itr:f_counter){
        cout<<itr.second.first<<' '<<itr.second.second<<'\n';
    }
    return 0;
}
