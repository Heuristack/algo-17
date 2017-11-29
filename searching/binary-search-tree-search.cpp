#include <iostream>
#include <memory>
#include <utility>
#include <cassert>
using namespace std;

template <typename Key> struct BinarySearchTreeNode {
    Key data;
    std::unique_ptr<BinarySearchTreeNode<Key>> ltree,rtree;
};

template <typename Key, typename Node = BinarySearchTreeNode<Key>>
Node * binary_search_tree_search(std::unique_ptr<Node> const & tree, Key key)
{
    if (tree == nullptr) return nullptr;
    else if (key < tree->data) return binary_search_tree_search(tree->ltree, key);
    else if (key > tree->data) return binary_search_tree_search(tree->rtree, key);
    else return tree.get();
}

int main()
{
    using BST = BinarySearchTreeNode<int>;
    auto tree = std::make_unique<BST>(BST{19, std::make_unique<BST>(BST{7, nullptr, nullptr}), std::make_unique<BST>(BST{43, nullptr, nullptr})});
    assert(tree->rtree.get() == binary_search_tree_search(tree, 43));
}

