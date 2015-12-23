# LintCode
C++11 Solution to LintCode websites
Some solutions source from http://www.jiuzhang.com/solutions/
and https://github.com/kamyu104/LintCode

1. In C++, there is no need to apply "a == NULL", we can apply if (a) or if (!a)to test a is exit or not.
2. When we assign / equal two ListNodes, we should apply: ListNode (star)cur = &dummy.
3. In C++, the pop function of the queue will not return anything.
4. We can use (const auto& word : words) to save the defintion on date type of word.
5. In C++, the map function on hasKey / containsKey equal to count().
6. Check Soltuion on Union-find.
7. Use !lookup.emplace(sum, i).second if make a decision on whether this map has this key or not.
8. In C++, we transform string to a stringstream, and use getline to split this string by delim (WTF).
9. When we want to create a const size of vector, we use vector<int> list(10);
10. When we create a 2D matrix, we use: vector<vector<int>> matrix(2, vector<int>(10, dafualt value));
11. When we would like to use priority queue in C++:
    struct Compare {
        bool operator()(const Cell& a, const Cell& b) {
            return a.height > b.height;
        }
    };
        struct Cell {
        int i;
        int j;
        int height;
    };
    vector<vector<bool>> is_visited_ = vector<vector<bool>>(m_, vector<bool>(n_, false));
    priority_queue<Cell ,vector<Cell>, Compare> heap_;
12. When we want to add string in c++:
	stringstream ss;
	ss << str1 << str2;
	return ss.str();
13. When we use map, we can use map[key] to get value (same as Python).
14. In the simple array, we can new as: double balance[5] = {1.0, 2.0, 3.4, 17.9, 39.4};
15. If we use new / delete method, new as: long * res = new long[n]; delete res;
16. Remeber, the substr in C++ is different from JAVA, and we should define that new string is: oldString.substr(start, end - start + 1); the second argument is length of new string.
17. lower_bound in C++, excited.
18. C++ erase method, vector.erase(nums.begin() + index);
19. static_cast is able to perform with pointers to classes not only the conversions allowed implicitly, but also their opposite conversions.
20. The aim of UNION in C/C++ is to save the data space in apply class or struct.


