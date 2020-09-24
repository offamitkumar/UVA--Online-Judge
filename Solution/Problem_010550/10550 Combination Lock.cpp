#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int antiClockWise(int start_angle , int end_angle) {
    int current = start_angle; 
    int counter1{};
    while (current != end_angle) {
        ++current;
        ++counter1;
        current%=40; 
    }
    return counter1;
}

int clockWise(int start_angle , int end_angle) {
    int current = end_angle; 
    int counter1{};
    while (current != start_angle) {
        ++current;
        ++counter1;
        current%=40; 
    }
    return counter1;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int a, b, c, d;
    while (cin >> a >> b >> c >> d , a+b+c+d) {
        int round{1080}; 
        round += (9*clockWise(a , b)); 
        round += (9*antiClockWise(b,c)); 
        round += (9*clockWise(c,d)); 
        cout << round << '\n'; 
    }
    return 0;
}
