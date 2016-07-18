
#include <iostream>
#include <set>
using namespace std;
 
int main()
{
    set<int> tst;
    tst.insert(2);
    tst.insert(70);
    tst.insert(28);
    tst.insert(65);
    tst.insert(9);
    tst.insert(12);
    tst.insert(20);
    tst.insert(31);
    tst.insert(5);
    set<int>::const_iterator pos;
    for(pos = tst.begin(); pos != tst.end(); ++pos)
        cout<<*pos<<' ';
    cout<<endl;
    return 0;
}
