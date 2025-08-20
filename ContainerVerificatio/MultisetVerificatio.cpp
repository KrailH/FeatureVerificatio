#include <iostream>
#include <set>

// 打印 multiset 的内容
void printMultiset(const std::multiset<int>& mset) {
    for (const int& item : mset) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 创建一个空的 multiset
    std::multiset<int> myMultiset;

    // 插入元素到 multiset
    myMultiset.insert(10);
    myMultiset.insert(20);
    myMultiset.insert(10); // multiset 允许重复元素
    myMultiset.insert(30);

    std::cout << "Multiset after insert operations: ";
    printMultiset(myMultiset);

    // 计数特定元素的出现次数
    int count = myMultiset.count(10);
    std::cout << "Number of 10s in the multiset: " << count << std::endl;

    // 查找特定元素
    auto it = myMultiset.find(20);
    if (it != myMultiset.end()) {
        std::cout << "Found 20 in the multiset." << std::endl;
    } else {
        std::cout << "20 is not in the multiset." << std::endl;
    }

    // 删除特定元素
    myMultiset.erase(10);
    std::cout << "Multiset after erase(10) operation: ";
    printMultiset(myMultiset);

    // 删除所有特定值的元素
    myMultiset.insert(10);
    myMultiset.insert(10);
    myMultiset.erase(10);
    std::cout << "Multiset after inserting and erasing all 10s: ";
    printMultiset(myMultiset);

    // 使用 equal_range 查找范围
    myMultiset.insert(10);
    myMultiset.insert(20);
    auto range = myMultiset.equal_range(20);
    std::cout << "Elements equal to 20: ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 清空 multiset
    myMultiset.clear();
    std::cout << "Multiset after clear operation: ";
    printMultiset(myMultiset);

    return 0;
}
