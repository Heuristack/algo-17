#include <iostream>
#include <iomanip>
using namespace std;

class master {
public:
    master(unsigned breadth, unsigned depth): b(breadth), d(depth){}

    void explore(unsigned i = 0, unsigned j = 0)
    {
        if (j != d) {
            cout << setfill('0') << setw(2) << k++ << ":" << i << "," << j << endl;
            for (unsigned i = 0; i != b; i++) {
                explore(i+1, j+1);
            }
        }
    }

private:
    unsigned b = 0;
    unsigned d = 0;
    unsigned k = 0;
};

int main()
{
    master(2,4).explore();
}

