//  Author : Amit Kumar 
//  Date   : Monday 20 July 2020 03:15:01 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t

signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            // DISABLE FOR INTERACTIVE PROBLEMS
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    double h , m; 
    char ch;
    while(cin >> h >>ch >> m  && h+m){
        h = (int)h % 12;
        double H = (h + (m / 60.0f))*30.0f; 
        double M = m * 6.0f; 
        double angle = fabs(H - M); 
        if(angle > 180.0f){
            angle = 360.0f - angle;
        }
        cout << fixed << setprecision(3) << angle << '\n';
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
