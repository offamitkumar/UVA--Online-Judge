//  Author : Amit Kumar
//  Date   : Monday 27 July 2020 10:20:28 AM IST

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
    string s;
    while(cin >> s && s != "#"){
      if(next_permutation(s.begin() , s.end())){
        cout << s << endl;
      }else{
        cout << "No Successor" << endl;
      }
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count()
         << " ms" << '\n';
#endif
    return 0;
}
