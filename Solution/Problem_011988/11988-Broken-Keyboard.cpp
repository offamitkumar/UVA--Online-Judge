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
    string res;
    while(getline(cin, res) && res.size()!=0) {
        //  string insertion will give you time limit exceed so use list for O(1) insertion 
        list<char>l;
        list<char>::iterator it = l.begin();
        for(auto&itr:res){
            if(itr=='['){
                it = l.begin();
            }else if(itr == ']'){
                it = l.end();
                prev(it);
            }else {
                l.insert(it,itr);
                next(it);
            }
        }
        cout<<string(l.begin(),l.end())<<'\n';
    }
    return 0;
}
