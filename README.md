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


