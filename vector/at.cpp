// vector::at
#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    cout << ' ' << myvector.at(i);
  cout << '\n';

  return 0;
}
