#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool comp(tuple<double,double,double>&t1 ,tuple<double,double,double>&t2 ){
    if(get<0>(t1) == get<0>(t2)){
        if(get<1>(t1) == get<1>(t2)){
            if(get<2>(t1) == get<1>(t2)){
                return true;
            }
            return get<2>(t1) < get<2>(t2);
        }else{
            return get<1>(t1) < get<1>(t2);
        }
    }else{
        return get<0>(t1) < get<0>(t2);
    }
}
double d(tuple<double,double,double>&t1 ,tuple<double,double,double>&t2 ){
    double dis = pow(get<0>(t1) - get<0>(t2),2);
    dis += pow(get<1>(t1) - get<1>(t2),2);
    dis += pow(get<2>(t1) - get<2>(t2),2);
    return sqrt(dis);
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    double x, y, z; 
    vector<int>dd(20,0);
    vector<tuple<double,double,double>>v;
    while(cin >> x >> y >> z, x+y+z){
        v.push_back(make_tuple(x,y,z));
    }
//    sort(v.begin() , v.end(), comp);
    for(int i=0;i<(int)v.size();++i){
        double dist{INT_MAX};
        for(int j=0; j<(int)v.size(); ++j){
            if(i == j) continue;
            dist = min(dist , d(v[i] , v[j]));
        }
        if(dist < 12.0){
            dd[dist]++;
        }

    }
    for(int i=0;i<10;++i){
        cout << setw(4) << setfill(' ') << dd[i]; 
    }
    cout << '\n'; 
    return 0;
}
