#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int Fig = 1;
struct Rectangle{
    int fig{};
    double lx, ly; 
    double rx, ry;
    bool contains(double x , double y){
        if(lx < x && rx > x && ly > y && ry < y){
            return true;
        }
        return false;
    }
};
vector<Rectangle>v;
signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    char ch;
    Rectangle r1; 
    while(cin >> ch && ch != '*'){
        r1.fig = Fig++;
        cin >> r1.lx >> r1.ly >> r1.rx >> r1.ry; 
        v.push_back(r1);
    }
    int i=1;
    while(cin>> r1.lx >> r1.ly && (r1.lx != 9999.9 && r1.ly != 9999.9)){
        bool found = false;
        for(auto&rectangle:v){
            if(rectangle.contains(r1.lx , r1.ly)){
                found = true;
                printf("Point %ld is contained in figure %ld\n", i , rectangle.fig);
            } 
        }
        if(!found){
            printf("Point %ld is not contained in any figure\n",i);
        }
        ++i;
    }
    return 0;
}
