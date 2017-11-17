#include <iostream>
#include <vector>
#include <iterator>

template <typename RandomAccessIterator, typename Key>
RandomAccessIterator binary_search_(RandomAccessIterator p, RandomAccessIterator r, Key k)
{
    auto const e = r;
    for (auto d = r - p; d > 0; d = r - p) {
        auto m = p + d/2;
        if (k == *m) return m;
        else if (k < *m) r = m;
        else p = m + 1;
    }
    return e;
}

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9};
    std::cout << (binary_search_(begin(v), end(v), 0) == end(v)) << std::endl;
}
