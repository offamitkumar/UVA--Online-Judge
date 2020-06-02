//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>
//  #include <iostream>
//  #include <chrono>
//  #include <string>
//  #include <utility>
//  #include <queue>
//  #include <stack>
//  #include <cmath>
//  #include <map>
//  #include <unordered_map>
//  #include <deque>
//  #include <unordered_set>
//  #include <set>
//  #include <climits>
//  #include <sstream>
//  #include <iomanip>
//  #include <cassert>
//  #include <bitset>
//  #include <numeric>
  #include <vector>
//  #include <array>
  #include <algorithm>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
#define MOD 1000000007
bool isprime(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//      auto initial_time = high_resolution_clock::now();
    int n,c; 
    while(scanf("%d %d",&n,&c)!=EOF){
        printf("%d %d: ",n,c);
        vector<int>v;v.push_back(1);
        for(int i=2;i<=n; ++i){
            if(isprime(i)){
                v.push_back(i);
            }
        }
        if(v.size() < 2*c){
            for(int i=0;i<v.size();++i){
                printf("%d",v[i]);
                if(i+1 != v.size()){
                    printf(" ");
                }
            }
        }else{
            vector<int>r;
            int bd = v.size()/2,fd =v.size()/2+1;
            --bd,--fd;
            if(v.size()&1){
                for(int i=0;i<c;++i){
                    if(i==0){
                        r.push_back(v[fd++]);
                        continue;
                    }
                    r.push_back(v[fd++]);
                    r.push_back(v[bd--]);
                }
            }else{
                for(int i=0;i<c;++i){
                    r.push_back(v[fd++]);
                    r.push_back(v[bd--]);
                }
            }
            sort(r.begin(),r.end());
            for(int i=0;i<r.size();++i){
                printf("%d",r[i]);
                if(i+1 != r.size()){
                    printf(" ");
                }
            }
        }
        puts("\n");
    }

//      auto final_time = high_resolution_clock::now();
//      cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
