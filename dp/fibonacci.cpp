
#include <iostream>

using namespace std;

int fib(int n){
    f[n+2];
    f[0]=0;
    f[1]=1;
    int i;
    for(i=2; i<=n; i++){
        f[n]=f[n-1]+f[n-2];
    }
    return f[n];
}

int main()
{
    cout<<fib(6)<<endl;

    return 0;
}
