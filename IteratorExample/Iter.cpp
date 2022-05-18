#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main (int argc, char * argv[])
{

    vector<int> vint {2, 4, 6, 8, 10};

    for (typename vector<int>::const_iterator b = vint.begin(), e = vint.end(); b != e; ++b) {
        cout << *b << endl;
    }

    return 0;

}