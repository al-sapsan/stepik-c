#include <iostream>
using namespace std;

// Template function to swap two variables of the same type
template <typename T>
void myswap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int k,m;
    double x,y;
    char c,d;
    cin>>k>>m>>x>>y>>c>>d;
    myswap(k,m);
    cout<<"k= "<<k<<" m= "<<m<<endl;
    myswap(x,y);
    cout<<"x= "<<x<<" y= "<<y<<endl;
    myswap(c,d);
    cout<<"c= "<<c<<" d= "<<d<<endl;
    return 0;
}