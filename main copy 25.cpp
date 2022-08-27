#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class A{
public:
    void f(){
        cout<<"non const"<<endl;
    }
    void f() const{
        cout<<" const"<<endl;
    }
};
 
int main(int argc, char **argv)
{
    A a;
    a.f();
    const A &b=a;
    b.f();
    const A *c=&a;
    c->f();
    A *const d=&a;
    d->f();
    A *const e=d;
    e->f();
    const A *f=c;
    f->f();
    return 0;
}
