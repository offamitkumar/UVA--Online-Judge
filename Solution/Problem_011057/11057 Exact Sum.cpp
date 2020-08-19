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
        vector<pair<int,int>>v(n); 
        for(int i=0,x; i<n; ++i){
            cin >> x; 
            v.at(i).first = x; 
            v.at(i).second = i;
        }
        sort(v.begin() , v.end()); 
        int ans1{-1} , ans2{-1};
        // instead of this binary search you can use set or map for simplicity. 
        auto binary_Search = [&](int num){
            int left = 0; 
            int right = n-1;
            while(left <= right){
                int mid = (left + right) /2;
                if(v.at(mid).first == num){
                    return mid;
                }
                if(v.at(mid).first > num){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
            return 999999999l;
        };
        int num; cin >> num;
        for(int i=0; i<n; ++i){
            if(num-v.at(i).first<0){
                continue;
            }
            int a1 = v.at(i).first; 
            int a2 = num - v.at(i).first;
            int x = binary_Search(a2);
            if(x!=999999999 && x != i){
                if(ans1 == -1){
                    ans1 = min(a1 , a2); 
                    ans2 = max(a1 , a2);
                }else if(abs(a1 - a2) < abs(ans1-ans2)){
                    ans1 = min(a1 , a2); 
                    ans2 = max(a1 , a2);
                }
            }
        }
        printf("Peter should buy books whose prices are %ld and %ld.\n\n", ans1, ans2);
    }
    return 0;
}
