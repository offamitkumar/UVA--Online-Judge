#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
using namespace std;
void case_2(void){
    for(int i=0;i<=9;++i){
        for(int j=0;j<=9;++j){
            string a = to_string(i);
            a+=(to_string(j));
            long long x = stoll(a);
            if(x==(j+i)*(j+i)){
                cout<<i<<j<<endl;
            }
        }
    }
}
void case_4(void){
    for(int i=10;i<=99;++i){
        for(int j=10;j<=99;++j){
            string a = to_string(i);
            a+=(to_string(j));
            long long x = stoll(a);
            if(x==(j+i)*(j+i)){
                cout<<i<<j<<endl;
            }
 
        }
    }
}
void case_6(void){
    for(int i=100;i<=999;++i){
        for(int j=100;j<=999;++j){
            string a = to_string(i);
            a+=(to_string(j));
            long long x = stoll(a);
            if(x==(j+i)*(j+i)){
                cout<<i<<j<<endl;
            }
        }
    }
}
void case_8(void){
    for(int i=1000;i<=9999;++i){
        for(int j=1000;j<=9999;++j){
            string a = to_string(i);
            a+=(to_string(j));
            long long x = stoll(a);
            if(x==(j+i)*(j+i)){
                cout<<i<<j<<endl;
            }
        }
    }
}
/*
 * As only few testcase are possible then we can just hardcode the 
 * the answers
 */
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while(cin>>n){
        switch(n){
            case 2:
                //    case_2();
                cout<<"00\n01\n81"<<endl;
                break;
            case 4:
                //   case_4();
                cout<<"0000\n0001\n2025\n3025\n9801"<<endl;
                break;
            case 6:
                //    case_6();
                cout<<"000000\n000001\n088209\n494209\n998001"<<endl;
                break;
            case 8:
                //    case_8();
                cout<<"00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001"<<endl;
                break;
        }
    }
    return 0;
}
