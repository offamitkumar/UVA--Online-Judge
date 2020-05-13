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
    while(cin>>n,n){
        vector<pair<int,int>>buy , sell;
        for(int x,i=0;i<n;++i){
            cin>>x;
            if(x>0){
                buy.push_back(make_pair(i,x));
            }else{
                sell.push_back(make_pair(i,abs(x)));
            }
        }
        sort(buy.begin() , buy.end());
        sort(sell.begin() , sell.end());
        long long cost{};
        int i=0,n=(int)buy.size() , j=0 ,m = (int)sell.size();
        while(i<n && j<m){
            if(buy[i].second<sell[j].second){
                sell[j].second -= buy[i].second;
                cost+=(abs(buy[i].first - sell[j].first)*buy[i].second);
                ++i;
            }else{
                buy[i].second -= sell[j].second;
                cost+=(abs(sell[j].first - buy[i].first)*sell[j].second);
                ++j;
            }
        }
        cout<<cost<<'\n';
    }
    return 0;
}
