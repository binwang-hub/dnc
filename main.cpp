//
//  main.cpp
//  b
//
//  Created by wangbin on 2021/8/28.
//

#include <iostream>
using namespace std;
 
class B
{
public:
    B()
    {
        cout<<"B's constructor"<<endl;
    }
 
 
    ~B()
    {
        cout<<"B's destructor"<<endl;
    }
 
 
    void SetNum(int n)
    {
        num = n;
    }
 
 
    int GetNum()
    {
        return num;
    }
 
 
private:
    int num;
};
 
int main()
{
    B *mem = (B*)malloc(10 * sizeof(B));
    cout << mem << endl;
    B *p = new(mem)B;
    cout << p << endl;
    p->SetNum(10);
    cout << p->GetNum() << endl;
    p->~B();
    delete mem;
}



