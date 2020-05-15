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
    string s;
    while(cin>>n && n){
        vector<string>v;
        for(auto i=0;i<n;++i){
            cin>>s;
            v.push_back(s);
        }
        auto compare = [&](string &s1 , string &s2){
            int i = 0 , j = 0;
            while(i<(int)s1.size() && j<(int)s2.size()){
                if(s[i]<s[j]){
                    return false;
                }else{
                    return true;
                }
                ++i;
                ++j;
            }
        };
        sort(v.begin() , v.end() ,compare);
        for(auto&itr:v){
            cout<<itr;
        }
        cout<<'\n';
    }
    return 0;
}
