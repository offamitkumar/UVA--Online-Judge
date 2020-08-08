#include <bits/stdc++.h>
using namespace std;
#define int int64_t
double dist(double x , double y){
    return sqrt(x*x + y*y);
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string s; 
    double r2 = sqrt(2.0);
    int c = 1;
    while(cin >> s && s != "END"){
        istringstream ss(s); 
        double x{},y{};
        while(getline(ss , s, ',')){
            double num{}; 
            string dir{}; 
            double i=0;
            while(i < (int)s.size() && s[i] >='0' && s[i]<='9'){
                num *=10; 
                num += (s[i]-'0');
                ++i;
            }
            while(i < (int)s.size() && s[i]>='A' && s[i]<='Z'){
                dir+=s[i];
                ++i;
            }
            if(dir =="S"){
                y-=num;
            }else if(dir == "N"){
                y+=num;
            }else if(dir == "W"){
                x-=num;
            }else if(dir == "E"){
                x+=num; 
            }else if(dir == "NE"){
                num/=r2; 
                x+=num; 
                y+=num;
            }else if(dir == "SE"){
                num/=r2; 
                x+=num; 
                y-=num;
            }else if(dir == "SW"){
                num/=r2; 
                x-=num; 
                y-=num;
            }else if(dir == "NW"){
                num/=r2; 
                x-=num; 
                y+=num;
            }
        }
        cout <<"Map #"<<c++<<'\n'; 
        cout << fixed << setprecision(3) << "The treasure is located at ("<<x<<","<<y<<")."<< '\n' 
             << "The distance to the treasure is "<<dist(x,y)<<"."<<'\n';
        cout << '\n'; 
    }
    return 0;
}
