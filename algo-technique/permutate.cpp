#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//TODO: implement this in backtracking infrastructure and remove this

void generate_all_permutations(vector<int> const & elements)
{
    static vector<int> permutation;
    if (elements.size() == 0) {
        for (auto e : permutation) cout << e;
        cout << endl;
    }
    for (int i = 0; i < elements.size(); i++) {
        permutation.push_back(elements[i]);
        auto candicates = elements;
        candicates.erase(candicates.begin() + i);
        generate_all_permutations(candicates);
        permutation.pop_back();
    }
}

int main()
{
    vector<int> elements = {1, 2, 3};
    generate_all_permutations(elements);

    string sequence = "123";
    do {
        cout << sequence << endl;
    }
    while (next_permutation(sequence.begin(), sequence.end()));
}

