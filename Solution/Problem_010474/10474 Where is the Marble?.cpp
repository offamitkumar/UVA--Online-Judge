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
    int n , q; 
    int case_counter{1};
    while(cin >> n >> q , (n+q)){
        cout <<"CASE# " << case_counter++ <<":\n";
        vector<int>v(n); 
        for(auto&itr:v)  cin >> itr; 
        sort(v.begin() , v.end());
        while(q--){
            int num;  cin>> num; 
            int ans{};
            int left = 0 , right= v.size()-1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(num == v.at(mid)){
                    ans = mid+1;
                }
                if(num > v.at(mid)){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
//              linear search will also work fine
//              for(int i=0; i<n;++i){
//                  if(v.at(i) == num){
//                      ans = i+1;
//                      break;
//                  }
//              }
            cout << num;
            if(!ans){
                cout <<" not found";
            }else{
                cout <<" found at " << ans ;
            }
            cout << '\n'; 
        }
    }
    return 0;
}
