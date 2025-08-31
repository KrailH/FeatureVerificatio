#include <iostream>
#include <queue>
#include <vector>
// 自定义对象
struct Person {
    std::string name;
    int age;

    // 自定义比较运算符，用于优先队列
    bool operator<(const Person& other) const {
        // 按照年龄由大到小排列（最大堆）
        return age < other.age;
    }
};

int main() {
//    // 创建一个空的 priority_queue，存储整数类型，默认是最大堆
//    std::priority_queue<int> pq;
//
//    // 使用 push 向优先队列中添加元素
//    pq.push(10);  // 队列中元素为 10
//    pq.push(30);  // 队列中元素为 30, 10
//    pq.push(20);  // 队列中元素为 30, 10, 20
//    pq.push(5);   // 队列中元素为 30, 10, 20, 5
//
//    // 由于是最大堆，优先队列中的元素按照优先级排列，队列顶端元素最大
//    // 队列的当前状态：30, 20, 10, 5（队列顶端最大）
//
//    // 输出队列顶端元素
//    std::cout << "Top element: " << pq.top() << std::endl;  // 输出 30
//
//    // 使用 pop 移除队列顶端元素
//    pq.pop();  // 移除 30，队列顶端元素变为 20
//
//    // 输出新的队列顶端元素
//    std::cout << "Top element after pop: " << pq.top() << std::endl;  // 输出 20
//
//    // 检查队列是否为空
//    if (pq.empty()) {
//        std::cout << "Priority Queue is empty." << std::endl;
//    } else {
//        std::cout << "Priority Queue is not empty." << std::endl;
//    }
//
//    // 获取队列中的元素个数
//    std::cout << "Size of Priority Queue: " << pq.size() << std::endl;  // 输出 3
//
//    // 清空队列
//    while (!pq.empty()) {
//        std::cout << "Popping: " << pq.top() << std::endl;  // 输出当前队列顶端元素
//        pq.pop();  // 移除当前队列顶端元素
//    }
//
//    // 再次检查队列是否为空
//    if (pq.empty()) {
//        std::cout << "Priority Queue is now empty after popping all elements." << std::endl;
//    }
//
//    // 创建一个空的 priority_queue，存储整数类型，使用 std::greater<int> 创建最小堆
//    std::priority_queue<int, std::vector<int>, std::greater<int>> pq_min;
//
//    // 使用 push 向优先队列中添加元素
//    pq_min.push(10);  // 队列中元素为 10
//    pq_min.push(30);  // 队列中元素为 10, 30
//    pq_min.push(20);  // 队列中元素为 10, 30, 20
//    pq_min.push(5);   // 队列中元素为 5, 10, 20, 30
//
//    // 由于是最小堆，优先队列中的元素按照优先级排列，队列顶端元素最小
//    // 队列的当前状态：5, 10, 20, 30（队列顶端最小）
//
//    // 输出队列顶端元素
//    std::cout << "Top element in Min-Heap: " << pq_min.top() << std::endl;  // 输出 5
//
//    return 0;
//
//    // 创建一个空的 priority_queue，存储浮点数类型，默认是最大堆
//    std::priority_queue<double> pq;
//
//    // 使用 push 向优先队列中添加元素
//    pq.push(10.5);
//    pq.push(30.2);
//    pq.push(20.8);
//    pq.push(5.1);
//
//    // 输出队列顶端元素
//    std::cout << "Top element: " << pq.top() << std::endl;  // 输出 30.2
//
//    // 清空队列
//    while (!pq.empty()) {
//        std::cout << "Popping: " << pq.top() << std::endl;  // 输出当前队列顶端元素
//        pq.pop();  // 移除当前队列顶端元素
//    }
//
//    return 0;

    // 创建一个空的 priority_queue，存储 Person 对象，使用自定义比较运算符
    std::priority_queue<Person> pq;

    // 使用 push 向优先队列中添加元素
    pq.push({"Alice", 30});
    pq.push({"Bob", 25});
    pq.push({"Charlie", 35});
    pq.push({"Dave", 28});

    // 输出队列顶端元素
    std::cout << "Top element: " << pq.top().name << " (" << pq.top().age << ")" << std::endl;  // 输出 Charlie (35)

    // 清空队列
    while (!pq.empty()) {
        const Person& topPerson = pq.top();
        std::cout << "Popping: " << topPerson.name << " (" << topPerson.age << ")" << std::endl;  // 输出当前队列顶端元素
        pq.pop();  // 移除当前队列顶端元素
    }

    return 0;
}
