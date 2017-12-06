Sorting
=======

Sorting is to find a particular permutation among all permutations of a given sequence of elements, in this perspective, sorting problem could be solved by searching - the universal problem-solving mechanism in AI. Permutation or arrangement of collection of elements hides an important information, that is, the concept of position, either relative or absolute, each permutation is actually a set of `<position, element>` pair, so the problem can be solved by (transformed as) finding out all those pairs, either brute-forcingly or systematically. Finding out all binary relations can be carried out in two reverse directions, left-to-right and right-to-left, particularly in sorting problem is to find out every element for each of those positions or reversely find out every position for each of those elements. Roughly speaking, these are the basic ideas of selection sort and insertion sort respectively.

The procedure is many-to-many, i.e., find many positions for many elements or find many elements for many positions, the key to solve such problem is to transform it to many one-to-many and potentially further to many many one-to-one problem (which is the solution in this case).  Here, it's just to find the element for a given position or find the position for a given element, and then continue, thinking mathematical induction and recurrence.

Given an element to find its final (absolute, requiring a fixed size sequence as input) position can be easily solved by counting, thinking the partition algorithm (STL algorithm: `partition` and `partition_point`) algorithm, however, given a position to find its element is not that easy but an order statistics problem, but fortunately, for extreme situations, it's straight forward, i.e., find the first and last (precisely, min and max, because the order is defined by comparison operation) element (STL algorithm: `min_element`, `max_element`, and `minmax_element`).

When implementing these algorithms, one important consideration is whether space is restricted, i.e., sort-in-place (rearrange by rotate or swap, STL prefix inplace, e.g., `inplace_merge`) or sort-by-copy (pass in an arbitrary collection of elements and return the ordered permutation, STL suffix copy, e.g., `partition_copy`), or further sort-by-move (like sort-by-copy, but read of the unsorted collection could be destructive).

Different sorting algorithms requre different manners in accessing the unsorted sequence, for example, insertion-sort requires to read one element once at most in the original sequence collection, i.e., for sort-by-copy implementation, the input could be `InputIterator` over a stream. While selection-sort has to repeatly read elements and expects to remove the selected one after each selecting iteration.

Another consideration is technically how to access element, for C++ it could be achieved by using iterators and indexes, both of which have advantages and disadvantages. By using iterators, it is possible to implement a generic algorithm by assuming the iterators are `ForwardIterator` so that it could be applied to all standard sequence containers, however, iterator-based ranges are half-open making boundary check error-prone. Constraints of `ForwardIterator` will affect some implementation details, e.g., size or distance has to be caculated by one-by-one counting because address arithematic is not allowed (only available for `RandomAccessIterator`). As a contrast, the goodness of using indexes is that algorithm implementations will be consistent with those in classic textbooks which is easy to prototype and verify its correctness. The drawback is caused by the convinence it provided, i.e., indexes can only be applied to contineous storage containers, such as built-in array, `array`, `vector` and `deque`, which generate `RandomAccessIterator` implicitly or explicitly.

STL algorithms can also be used to express relative high-order semantics used by different sorting strategies, e.g., `partition` and `partition_point` can be used in quick sort for dividing the unsorted collection of elements in-place, while `merge` or `inplace_merge` can be used in merge sort for combining sorted subsequences, heap algorithms like `make_heap` and `sort_heap` can be used in heap sort, and `rotate` can be used in insertion sort, etc. This will result in nice and neat implementations so called *declarative programming*.

Sorting in linear time is also possible if some assumptions are hold on inputs, however, for most of them I can think of are distribution sort, such as counting sort, radix sort and bucket sort, etc. In short, a comparison is a binary-distribution in terms of putting the smaller (or larger) element on left side (first position) and the other element on the other position.

**Insertion Sort** - insert an arbitrary element from the remaining unsorted sequence into its equal range of the increasing sorted sequence
```
template <typename ForwardIterator>
void insertion_sort(ForwardIterator p, ForwardIterator r)
{
    for (auto i = p; i != r; i++) {
        rotate(upper_bound(p,i,*i),i,next(i));
    }
}
```

**Selection Sort** - move minimum element from remaining the unsorted sequence to end position of sorted sequence one-by-one
```
template <typename ForwardIterator>
void selection_sort(ForwardIterator p, ForwardIterator r)
{
    for (auto i = p; i != r; i++) {
        iter_swap(min_element(i,r), i);
    }
}
```

**Bubble Sort** -  reduce inversions exhaustively
```
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
```

**Heap Sort** - push heap forward then pop heap backward
```
template <typename RandomAccessIterator>
void heap_sort(RandomAccessIterator p, RandomAccessIterator r)
{
    for (auto i = p; i != r; i++) push_heap(p,i);		// make_heap(p,r);
    for (auto i = r; i != p; i--)  pop_heap(p,i);		// sort_heap(p,r);
}
```

**Merge Sort** - divide and conquer then merge  to combine
```
template <typename ForwardIterator>
void merge_sort(ForwardIterator p, ForwardIterator r)
{
    if (distance(p,r) <= 1) return;
    auto m = p + distance(p,r)/2;
    merge_sort(p, m);
    merge_sort(m, r);
    inplace_merge(p, m, r);
}
```

**Quick Sort** - partition then conquer and no need to combine
```
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
```

