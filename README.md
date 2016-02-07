# LintCode
C++11 Solution to LintCode websites
Some solutions source from [http://www.jiuzhang.com/solutions/][1] and [https://github.com/kamyu104/LintCode][2]

* In C++, there is no need to apply "a == NULL", we can apply if (a) or if (!a)to test a is exit or not.

*  When we assign / equal two ListNodes, we should apply: 
```
    ListNode (star)cur = &dummy.
```

*  In C++, the pop function of the queue will not return anything.

*  We can use (const auto& word : words) to save the defintion on date type of word.

*  In C++, the map function on hasKey / containsKey equal to count().

*  Check Soltuion on Union-find.

*  Use !lookup.emplace(sum, i).second if make a decision on whether this map has this key or not.

*  In C++, we transform string to a stringstream, and use getline to split this string by delim (WTF).

*  When we want to create a const size of vector, we use 
>   vector<int> list(10);

*  When we create a 2D matrix, we use: 
```
vector<vector<int>> matrix(2, vector<int>(10, dafualt value));
```

*  When we would like to use priority queue in C++:
```
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
```

*  When we want to add string in c++:
```
	stringstream ss;
	ss << str1 << str2;
	return ss.str();
```

*  When we use map, we can use map[key] to get value (same as Python).

*  In the simple array, we can new as:
``` 
double balance[5] = {1.0, 2.0, 3.4, 17.9, 39.4};
```

*  If we use new / delete method, new as: 
```
long * res = new long[n]; delete res;
```

*  Remeber, the substr in C++ is different from JAVA, and we should define that new string is: oldString.substr(start, end - start + 1); the second argument is length of new string.

*  lower_bound in C++, excited.

*  C++ erase method, vector.erase(nums.begin() + index);

*  static_cast is able to perform with pointers to classes not only the conversions allowed implicitly, but also their opposite conversions.

*  The aim of UNION in C/C++ is to save the data space in apply class or struct.

*  If we are asked to consider of 32 bits in C++, we should use left_part >= 31 to make sure we overrange or not.

*  When we construct a tree node, we should perform Clone method to aviod pass-by-value issue.

*  After three days travel, I am totally tired, and reboot to a new life.

*  The node copy/sepeter template is in **Copy List with Random Pointer.cpp**.

*  Use & at parameter of function to make sure it can be updated all the time.

*  Upper and Lower bound method template in C++ is in **Search for a Range.cpp**. 

*  The 1/k major number solution template is located in **Majority Number II & III.cpp**.

*  We can also use foo (int * num) as function describition, and foo(&x); to perform pass-by-referencce. 

*  KMP algorithm implement in C++ lcoated in strStr.cpp file.





[1]: http://www.jiuzhang.com/solutions/
[2]: https://github.com/kamyu104/LintCode

