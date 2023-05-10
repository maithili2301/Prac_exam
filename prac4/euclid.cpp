
#include<bits/stdc++.h>
using namespace std;

int gcdAlgo(int a,int b,int *x,int *y) {
    if(a==0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdAlgo(b%a,a,&x1,&y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

int main() {
    int x, y, a , b;
    cout<<"Enter the first number : ";
    cin>>a;
    cout<<"Enter the second number : ";
    cin>>b;
    int ans = gcdAlgo(a,b,&x,&y);
    cout<<"GCD("<<a<<","<<b<<")="<<ans<<endl;
    return 0;
}