#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr); 
//     cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    double n; 
    while(cin >> n,n){
        vector<double>v(n); 
        double sum{};
        char ch;
        for(double i=0; i<n;++i){
            int x , y; cin >> x >> ch >> y; 
            v.at(i) += (x * 100 + y);
            sum+=v.at(i);
        }
        sum/=n;
        double counter{};
        double counter1{};
        for(auto&itr:v){
            if(itr > sum){
                counter += (double) (long)(itr - sum);
            }else{
                counter1 += (double) (long)(sum - itr);
            }
        }
        cout <<"$";
//         counter = min(counter1 , counter);
//         cout << counter/100 << '.' << setw(2) <<setfill('0') << (int(counter) % 100) << '\n'; 
        cout << fixed << setprecision(2); 
        cout << max(counter/100 , counter1/100) << '\n'; 
    }
    return 0;
}
