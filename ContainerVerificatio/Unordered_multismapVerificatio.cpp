#include <iostream>
#include <unordered_map>

// 打印 unordered_multimap 的内容
void printUnorderedMultimap(const std::unordered_multimap<std::string, int>& ummap) {
    for (const auto& pair : ummap) {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;
}

int main() {
    // 创建一个空的 unordered_multimap
    std::unordered_multimap<std::string, int> myUnorderedMultimap;

    // 插入元素到 unordered_multimap
    myUnorderedMultimap.emplace("apple", 1);
    myUnorderedMultimap.emplace("banana", 2);
    myUnorderedMultimap.emplace("apple", 3); // unordered_multimap 允许重复的键
    myUnorderedMultimap.emplace("cherry", 4);

    std::cout << "Unordered_multimap after insert operations: ";
    printUnorderedMultimap(myUnorderedMultimap);

    // 计数特定键的元素数量
    int count = myUnorderedMultimap.count("apple");
    std::cout << "Number of 'apple' in the unordered_multimap: " << count << std::endl;

    // 查找特定键的一个元素
    auto it = myUnorderedMultimap.find("banana");
    if (it != myUnorderedMultimap.end()) {
        std::cout << "Found 'banana' in the unordered_multimap with value: " << it->second << std::endl;
    } else {
        std::cout << "'banana' is not in the unordered_multimap." << std::endl;
    }

    // 查找特定键的所有元素
    auto range = myUnorderedMultimap.equal_range("apple");
    std::cout << "Elements with key 'apple': ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "{" << it->first << ", " << it->second << "} ";
    }
    std::cout << std::endl;

    // 删除特定键的元素
    myUnorderedMultimap.erase("banana");
    std::cout << "Unordered_multimap after erase('banana') operation: ";
    printUnorderedMultimap(myUnorderedMultimap);

    // 清空 unordered_multimap
    myUnorderedMultimap.clear();
    std::cout << "Unordered_multimap after clear operation: ";
    printUnorderedMultimap(myUnorderedMultimap);

    return 0;
}
