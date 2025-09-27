#include <iostream>
#include <unordered_set>

// 打印 unordered_multiset 的内容
void printUnorderedMultiset(const std::unordered_multiset<int>& umset) {
    for (const int& item : umset) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 创建一个空的 unordered_multiset
    std::unordered_multiset<int> myUnorderedMultiset;

    // 插入元素到 unordered_multiset
    myUnorderedMultiset.insert(10);
    myUnorderedMultiset.insert(20);
    myUnorderedMultiset.insert(10); // unordered_multiset 允许重复元素
    myUnorderedMultiset.insert(30);

    std::cout << "Unordered_multiset after insert operations: ";
    printUnorderedMultiset(myUnorderedMultiset);

    // 计数特定元素的出现次数
    int count = myUnorderedMultiset.count(10);
    std::cout << "Number of 10s in the unordered_multiset: " << count << std::endl;

    // 查找特定元素
    auto it = myUnorderedMultiset.find(20);
    if (it != myUnorderedMultiset.end()) {
        std::cout << "Found 20 in the unordered_multiset." << std::endl;
    } else {
        std::cout << "20 is not in the unordered_multiset." << std::endl;
    }

    // 删除特定元素
    myUnorderedMultiset.erase(10);
    std::cout << "Unordered_multiset after erase(10) operation: ";
    printUnorderedMultiset(myUnorderedMultiset);

    // 插入并删除所有特定值的元素
    myUnorderedMultiset.insert(10);
    myUnorderedMultiset.insert(10);
    myUnorderedMultiset.erase(10);
    std::cout << "Unordered_multiset after inserting and erasing all 10s: ";
    printUnorderedMultiset(myUnorderedMultiset);

    // 清空 unordered_multiset
    myUnorderedMultiset.clear();
    std::cout << "Unordered_multiset after clear operation: ";
    printUnorderedMultiset(myUnorderedMultiset);

    return 0;
}
