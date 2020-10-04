#include <bits/stdc++.h>
using namespace std;
#define int int64_t
map<int,int>f;
int counter{};
int stepsTaken(int stairs) {
    int bestCounter{};
    int taken{0};
    for (auto&itr:f) {
        if (stairs < itr.first) {
            break;
        }
        if (abs(stairs - itr.first)<abs(stairs-taken)) {
            bestCounter = itr.second; 
            taken = itr.first;
        }
    }
    counter += bestCounter;
    return taken;
}
void preCalculate(void) {
    // map[stairs, steps] 
    int stairs = 2ll, steps = 1ll; 
    f[1] =1;
    while (stairs <= (1ll<<31ll)) {
        f[stairs] = 2ll*steps;
        steps+=1ll;
        f[stairs + steps] = 2ll*(steps-1)+1;
        stairs += (steps+steps); 
    }
    cerr << f.size() << '\n'; 
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    preCalculate();
    while (t--) {
        counter = 0;
        int x, y;  cin >> x >> y;
        x = (y - x);
        x-=stepsTaken(x);
        if(x) {
            counter+=1;
        }
        cout << counter << '\n'; 
    }
    return 0;
}
