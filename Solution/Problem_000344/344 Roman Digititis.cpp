#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void print(int k) {
    printf("%ld: " , k);
    vector<int>ans(101); 
    for (int i=1; i<=k; ++i) {
        int n = i; 
        while (n >= 100) {
            n-=100; 
            ans[100]++;
        }
        if(n >=90){
            ans[10]++;
            ans[100]++;
            n-=90;
        }
        while (n >= 50) {
            n-=50; 
            ans[50]++;
        }
        if(n>=40) {
            ans[50]++;
            ans[10]++;
            n-=40;
        }
        while (n >= 10) {
            n-=10; 
            ans[10]++;
        }
        if ((n<9) && (n>=5)) {
            n-=5; 
            ans[5]++;
        }
        switch (n) {
            case 1: 
                ans[1]++; 
                break;
            case 2:
                ans[1]+=2;
                break; 
            case 3:
                ans[1]+=3; 
                break; 
            case 4:
                ans[1]+=1; 
                ans[5]+=1;
                break;
            case 9:
                ans[10]+=1;
                ans[1]+=1;
                break;
        }
    }
    printf("%ld i, %ld v, %ld x, %ld l, %ld c\n", ans[1], ans[5], ans[10], ans[50], ans[100]);
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; 
    while (cin >> n,n) {
        print(n);
    }
    return 0;
}
