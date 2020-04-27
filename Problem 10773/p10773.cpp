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
    int total_case;
    cin>>total_case;
    for(int Case{1};Case<=total_case;++Case){
        double displacement,river_speed,boat_speed;
        cin>>displacement>>river_speed>>boat_speed;
        if(river_speed >= boat_speed || boat_speed == 0 || river_speed == 0 /* read question, it also ask if there are present both case */){
            printf("Case %d: can't determine\n",Case);
            continue;
        }
        double t1,t2;
        t1 = displacement/boat_speed;
        t2 = displacement/sqrt(boat_speed*boat_speed - river_speed*river_speed); // remember boat & river problem from physics 
        cout<<"Case "<<Case<<": "<<fixed<<setprecision(3)<<(double)(fabs(t1-t2))<<'\n';
    }
output:   
    return 0;
}
