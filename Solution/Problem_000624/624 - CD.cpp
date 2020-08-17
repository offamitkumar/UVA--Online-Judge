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
    int n; 
    while(cin >> n){
        int k; cin >> k;
        vector<int>v(k);
        int best_time = 0; 
        vector<int>res;
        for(auto&itr:v){cin >> itr;}
        for(int i=0; i<=(1<<k); ++i){
            vector<int>temp;
            for(int j=0; j<k; ++j){
                if(i&(1<<j)){
                    temp.push_back(v.at(j));
                }
            }
            int x = accumulate(temp.begin() , temp.end() , 0); 
            if(x <= n && best_time < x){
                res = temp; 
                best_time = x; 
            }else if(x <= n && best_time  == x){
                if(res.size() < temp.size()){
                    res = temp;
                }
            }
        }
        for(auto&itr:res){
            cout << itr <<' ';
        }
        cout << "sum:" << best_time << '\n'; 
    }
    return 0;
}
