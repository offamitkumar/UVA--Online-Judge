#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n, m, c; 
    int seq = 1;
    while(cin >> n >> m >> c && n + m + c){
        printf("Sequence %ld\n",seq++);
        vector<int>v(n);
        for(auto&itr:v)cin >> itr; 
        vector<bool>state(n,false); 
        bool blasted = false; 
        int consuming{},number, max_power{}; 
        for(int i=0; i<m;++i){
            cin >> number; 
            --number;
            if(state.at(number)){
                consuming-=v.at(number);
                state.at(number) = false;
            }else{
                consuming+=v.at(number);
                state.at(number) = true;;
            }
            if(consuming > c){
                blasted = true;
            }
            max_power = max(max_power , consuming);
        }
        if(blasted){
            puts("Fuse was blown.");
        }else{
            puts("Fuse was not blown.");
            printf("Maximal power consumption was %ld amperes.\n",max_power);
        }
        puts("");
    }
    return 0;
}
