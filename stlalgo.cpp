//implementing a search in a list
 
 #include <iostream>

 #include <list>

 #include <algorithm>

 #include <cstdlib> // rand()

 #include <ctime> // time()

 int main()

 {

 using namespace std;

 srand(time(NULL)); 

 int i = 0;

 list<int> li;

 for (int count=0; count < 10; count++)

 li.push_back(rand()%5 * ((i % 2)? -1 : 1));

 list<int>::iterator it; 

 for (it = li.begin(); it != li.end(); it++)

 cout << "li[" << i++ << "] = \t" << *it << endl;

 int s;

 cout << "Enter a number to search: ";

 cin >> s;

 cout << "Inserting 111 before: " << s << endl;

 // search the value ’s’ in the list

 it = find(li.begin(), li.end(), s);

 li.insert(it, 100); // insert the value ’100’ before ’s’

 

 for (i = 0, it = li.begin(); it != li.end(); it++)

 cout << "li[" << i++ << "] = \t" << *it << endl;

 }