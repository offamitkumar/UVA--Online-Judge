// in this problem we have to find such pairs where 
// sum of 1 to C-1 is equal to the C to N. 
// i.e 1+2+3+...C-1 = C+(C+1)+(C+2)+(C+3)+(C+4)...N
//  ((C-1)*C)/2 = (N*(N+1))/2 - (C * (C+1))/2  /// for summation we need 1...C but our sequence is starting from C
// C(C-1) + C(C+1) = N*(N+1) 
// C^2 - C + C^2 + C = N*(N+1)
// 2(C^2) = N*(N+1)
// C^2 = (N*(N+1))/2
// C = sqrt((N*(N+1))/2) 
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
    vector<pair<int,int>> ans; 
    ans.push_back(make_pair(6,8)); 
    ans.push_back(make_pair(35, 49)); 
    int n = 50; 
    while(ans.size()!=10){
        int x = (n * (n+1) /2);
        int y = sqrt(x);
        if (y * y == x) {
            ans.push_back(make_pair(y,n));
        }
        ++n;
    }
    for(auto&itr:ans){
        cout << setw(10) <<setfill(' ') << itr.first << setw(10) << setfill(' ' ) << itr.second << '\n'; 
    }
    return 0;
}
