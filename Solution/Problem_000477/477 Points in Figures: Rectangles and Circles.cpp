#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct figure{
    char type; 
    vector<double>v; 
    int index;
    figure(char c, int ind) {
        index = ind;
        type = c;
        if (c == 'c') {
            for (int i=0; i<3; ++i) {
                double d; cin >> d; 
                v.push_back(d);
            }
        } else {
            for (int i=0; i<4; ++i) {
                double d; cin >> d;
                v.push_back(d);
            }
        }
    }
    bool contained(double x, double y, int ind) {
        if (type == 'c') {
            double x_ = (x - v[0]) * (x - v[0]);
            double y_ = (y - v[1]) * (y - v[1]);
            double sq = sqrt(x_ + y_);
            if (sq < v[2]) {
                printf("Point %ld is contained in figure %ld\n",ind , index);
                return true;
            }
            return false;
        } else {
            if (x > v[0] && x< v[2] && y >v[3] && y <v[1]) {
                printf("Point %ld is contained in figure %ld\n",ind , index);
                return true;
            }
            return false;
        }
    }
};
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    char c; 
    int index{1};
    vector<figure> v;
    while (cin >> c && c!= '*') {
        figure f(c , index); 
        index++;
        v.push_back(f);
    }
    index =1; 
    double x, y; 
    while (cin >> x >> y && (x!=9999.9 && y!=9999.9)) {
        bool ok= false;
        for (int i=0; i<(int)v.size(); ++i) {
            ok|=v.at(i).contained(x,y,index);
        }
        if (!ok) {
            printf("Point %ld is not contained in any figure\n",index);
        }
        ++index;
    }
    return 0;
}
