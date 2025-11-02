#include <iostream>
#include <string>
#include <regex>
#include <sstream>

/*
 * replace_first
 *  替换字符串 s 中第一次出现的 `from` 为 `to`，如果找不到 `from` 则返回原字符串。
 *  这是最直观、最简单的替换操作，通常用于只需要替换第一个匹配的场景。
 */
std::string replace_first(const std::string &s, const std::string &from, const std::string &to) {
    if (from.empty()) return s; // 避免无限循环或未定义行为：不替换空串
    std::string res = s;
    std::size_t pos = res.find(from);
    if (pos != std::string::npos) {
        res.replace(pos, from.length(), to);
    }
    return res;
}

/*
 * replace_all (non-overlapping)
 *  将 s 中所有不重叠的 `from` 替换为 `to`。
 *  算法思想：
 *    - 从头开始 find `from` 的位置 pos
 *    - 在 pos 处进行 replace
 *    - 然后继续从 pos + to.length() 的位置搜索下一个（因为已替换的区域我们不再检查）
 *  这就是常见的“逐个查找并替换”的实现。
 */
std::string replace_all(const std::string &s, const std::string &from, const std::string &to) {
    if (from.empty()) return s; // 不处理空的查找串
    std::string res;
    res.reserve(s.size()); // 预分配一些空间以减少重复分配（可选优化）
    std::size_t pos = 0;
    std::size_t found;
    while ((found = s.find(from, pos)) != std::string::npos) {
        // 把 pos 到 found 之间的原始字符追加到结果
        res.append(s, pos, found - pos);
        // 追加替换字符串
        res.append(to);
        // 将 pos 移到被替换区域后面继续搜索（非重叠）
        pos = found + from.size();
    }
    // 把剩下未匹配的尾部追加
    res.append(s, pos, s.size() - pos);
    return res;
}

/*
 * replace_all_allow_overlap
 *  将 s 中所有允许重叠的 `from` 替换为 `to`。
 *  例如：s = "aaaa", from = "aa", to = "X"
 *    - non-overlapping 替换结果 = "XX"   (匹配位置 0 和 2)
 *    - overlapping  替换结果 = "XXa" 或者具体实现可能是 "XXX" 取决于策略
 *  这里的实现策略是：每次找到匹配后，下一次搜索从 found + 1 （即允许重叠的起点）开始。
 *  注意：允许重叠时要谨慎，可能引起结果长度和匹配次数的复杂变化。
 */
std::string replace_all_allow_overlap(const std::string &s, const std::string &from, const std::string &to) {
    if (from.empty()) return s;
    std::string res;
    std::size_t pos = 0;
    std::size_t found;
    while ((found = s.find(from, pos)) != std::string::npos) {
        res.append(s, pos, found - pos);
        res.append(to);
        // 与 non-overlapping 不同：只向前移动 1，允许重叠匹配
        pos = found + 1;
    }
    res.append(s, pos, s.size() - pos);
    return res;
}

/*
 * replace_with_regex
 *  使用 std::regex 进行替换（支持正则表达式）。
 *  这对更复杂的模式替换很有用（例如捕获组、字符类等）。
 *  注意：正则比纯字符串查找性能通常低，且语法需小心（尤其是转义）。
 */
std::string replace_with_regex(const std::string &s, const std::string &pattern, const std::string &replacement) {
    try {
        std::regex re(pattern);
        // std::regex_replace 会替换所有匹配项（默认行为）
        return std::regex_replace(s, re, replacement);
    } catch (const std::regex_error &e) {
        // 捕获正则语法错误，返回原字符串并输出错误信息（教学演示）
        std::cerr << "Invalid regex pattern: " << e.what() << "\n";
        return s;
    }
}

/*
 * 打印示例分割线的辅助函数，便于演示时输出更清晰
 */
void print_sep() {
    std::cout << "--------------------------------------------------\n";
}

int main() {
    // 示例：简单替换
    {
        std::string s = "Hello world, welcome to the world!";
        std::cout << "原始: " << s << "\n";
        std::cout << "replace_first(s, \"world\", \"Earth\") = "
                  << replace_first(s, "world", "Earth") << "\n";
        std::cout << "replace_all(s, \"world\", \"Earth\") = "
                  << replace_all(s, "world", "Earth") << "\n";
        print_sep();
    }

    // 示例：替换空串（不建议）
    {
        std::string s = "abc";
        std::cout << "原始: '" << s << "'\n";
        std::cout << "replace_all(s, \"\", \"X\") -> (should be unchanged) = '"
                  << replace_all(s, "", "X") << "'\n";
        print_sep();
    }

    // 示例：重叠匹配
    {
        std::string s = "aaaa";
        std::cout << "原始: " << s << "\n";
        std::cout << "replace_all(s, \"aa\", \"X\") (non-overlapping) = "
                  << replace_all(s, "aa", "X") << "\n";
        std::cout << "replace_all_allow_overlap(s, \"aa\", \"X\") (allow overlap) = "
                  << replace_all_allow_overlap(s, "aa", "X") << "\n";
        print_sep();
    }

    // 示例：替换为更长或更短的字符串（观察结果长度变化）
    {
        std::string s = "one two three two";
        std::cout << "原始: " << s << "\n";
        std::cout << "replace_all(s, \"two\", \"2\") = " << replace_all(s, "two", "2") << "\n";
        std::cout << "replace_all(s, \"two\", \"TWO_LONG\") = " << replace_all(s, "two", "TWO_LONG") << "\n";
        print_sep();
    }

    // 示例：使用正则替换（比如将多个空格替换为一个空格）
    {
        std::string s = "this    is   spaced\t\t out";
        std::cout << "原始: [" << s << "]\n";
        std::cout << "使用 regex 将连续空白替换为单个空格: ["
                  << replace_with_regex(s, "\\s+", " ") << "]\n";
        // 注意：在 C++ 字符串里，\ 需要写成 \\，所以模式是 "\\s+"
        print_sep();
    }

    // 交互示例：让用户输入想替换的内容（教学中可演示）
    {
        std::string haystack, from, to;
        std::cout << "交互示例 — 输入一行原始字符串 (或空行退出)：\n";
        std::getline(std::cin, haystack);
        if (!haystack.empty()) {
            std::cout << "输入要查找的子串 (from): ";
            std::getline(std::cin, from);
            std::cout << "输入替换为 (to): ";
            std::getline(std::cin, to);

            std::cout << "替换第一个匹配: " << replace_first(haystack, from, to) << "\n";
            std::cout << "替换全部（非重叠）: " << replace_all(haystack, from, to) << "\n";
            std::cout << "允许重叠的全部替换: " << replace_all_allow_overlap(haystack, from, to) << "\n";
        } else {
            std::cout << "跳过交互示例（输入为空）\n";
        }
    }

    return 0;
}
