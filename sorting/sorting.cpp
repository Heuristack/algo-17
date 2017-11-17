#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template <typename ForwardIterator>
void insertion_sort(ForwardIterator p, ForwardIterator r)
{
    for (auto i = p; i != r; i++) {
        rotate(upper_bound(p,i,*i),i,next(i));
    }
}

template <typename ForwardIterator>
void selection_sort(ForwardIterator p, ForwardIterator r)
{
    for (auto i = p; i != r; i++) {
        iter_swap(min_element(i,r), i);
    }
}

template <typename BidirectionalIterator>
void bubble_sort(BidirectionalIterator p, BidirectionalIterator r)
{
    for (auto j = r; j != p; j--) {
        for (auto i = p; next(i) != j; i++) {
            if (*i > *next(i)) {
                iter_swap(i, next(i));
            }
        }
    }
}

template <typename RandomAccessIterator>
void heap_sort(RandomAccessIterator p, RandomAccessIterator r)
{
    for (auto i = p; i != r; i++) push_heap(p,i);
    for (auto i = r; i != p; i--)  pop_heap(p,i);
}

template <typename ForwardIterator>
void merge_sort(ForwardIterator p, ForwardIterator r)
{
    if (distance(p,r) <= 1) return;
    auto m = p + distance(p,r)/2;
    merge_sort(p, m);
    merge_sort(m, r);
    inplace_merge(p, m, r);
}

template <typename ForwardIterator>
void quick_sort(ForwardIterator p, ForwardIterator r)
{
    if (distance(p,r) <= 0) return;
    auto m = *(p + distance(p,r)/2);
    auto u = partition(p, r, [m](auto const & e){ return e <= m; });
    auto l = partition(p, u, [m](auto const & e){ return e <  m; });
    quick_sort(p, l);
    quick_sort(u, r);
}

int main()
{
    vector<int> u = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9};

    auto i = u;
    insertion_sort(begin(i), end(i));
    cout << is_sorted(begin(i), end(i)) << endl;

    auto s = u;
    selection_sort(begin(s), end(s));
    cout << is_sorted(begin(s), end(s)) << endl;

    auto b = u;
    bubble_sort(begin(b), end(b));
    cout << is_sorted(begin(b), end(b)) << endl;

    auto h = u;
    heap_sort(begin(h), end(h));
    cout << is_sorted(begin(h), end(h)) << endl;

    auto m = u;
    merge_sort(begin(m), end(m));
    cout << is_sorted(begin(m), end(m)) << endl;

    auto q = u;
    quick_sort(begin(q), end(q));
    cout << is_sorted(begin(q), end(q)) << endl;
}

