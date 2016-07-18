


#include <iostream>
#include <list>
using namespace std;
 
int main()
{
    list<char> lst;
    for(char chs='A'; chs<='Z'; ++chs)
        lst.push_back(chs);
    list<char>::const_iterator pos;
    for(pos = lst.begin(); pos != lst.end(); ++pos)
        cout<<*pos<<' ';
    cout<<endl;
    return 0;
}


