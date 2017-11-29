#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template <typename T = int>
struct TreeNode {
    T data;
    vector<shared_ptr<TreeNode<T>>> children;
};

template <typename T = int>
void tree_traverse(shared_ptr<TreeNode<T>> const & tree)
{
    if (tree == nullptr) return;
    cout << tree->data;
    for (auto const & child : tree->children) tree_traverse(child);
}

int main()
{
    using TNI = TreeNode<int>;
    auto tree = make_shared<TNI>(TNI{1,{
        make_shared<TNI>(TNI{2,{
            make_shared<TNI>(TNI{5,{}}),
            make_shared<TNI>(TNI{6,{}}),
            make_shared<TNI>(TNI{7,{}})
        }}),
        make_shared<TNI>(TNI{3,{
            make_shared<TNI>(TNI{8,{}}),
            make_shared<TNI>(TNI{9,{}}),
        }}),
        make_shared<TNI>(TNI{4,{
            make_shared<TNI>(TNI{0,{}})
        }})}
    });
    tree_traverse(tree);
    cout << endl;
}
