#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int n, k, m; 
vector<int>taken;
int indexK , indexM;
int timer = 0;
void getK(void) {
    timer++;
    int counter = 0;
    int turn{};
    for (; turn<(n*n)+1; ++turn) {
        counter += (taken.at(indexK) == 0); 
        if (counter == k)
            break;
        ++indexK; 
        indexK = (indexK %n);
    }
    if (!taken.at(indexK)) {
        taken.at(indexK) = timer;
        cout << setw(3) << setfill(' ') << indexK+1;
        ++indexK; 
        indexK = (indexK%n);
    }
}
void getM(void) {
    int counter = 0;
    int turn{};
    for (; turn<(n*n)+1;++turn) {
        counter += (taken.at(indexM) == 0 || taken.at(indexM) == timer); 
        if (counter == m)
            break;
        --indexM; 
        indexM = (indexM+n+n)%n ;
    }
    if ( !taken.at(indexM)) {
        taken.at(indexM) = true;
        cout << setw(3) << setfill(' ') << indexM+1;
        --indexM; 
        indexM = (indexM+n+n)%n ;
    }
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    while (cin >> n >> k >> m && n+k+m) {
        timer = 0;
        taken.clear(); 
        taken.assign(n, 0);
        indexK = 0; 
        bool more = false;
        indexM = n-1; 
        while (count(taken.begin() , taken.end(), 0)) {
            if (more) {
                cout <<',';
            }
            more = true;
            getK(); 
            getM();
        }
        cout << '\n'; 
    }
    return 0;
}
