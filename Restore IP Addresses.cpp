/*
    Given a string containing only digits, restore it by returning all possible valid IP address combinations.
    Link: http://www.lintcode.com/en/problem/restore-ip-addresses/
    Example:
    Given "25525511135", return
		[
		  "255.255.11.135",
		  "255.255.111.35"
		]
    Solution: Perform a typic DFS algorithm to solve it.
    Source: http://www.cnblogs.com/yuzhangcmu/p/4106686.html
*/

class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> ret;
        if (s.empty() || s.length() < 4) {
            return ret;
        }
        vector<string> path;
        
        dfs(s, path, ret, 0);
        return ret;
    }
    
    void dfs(string& s, vector<string>& path, vector<string> &ret, int index) {
        int len = s.size();
        if (path.size() == 4) {
            if (index == len) {
                stringstream ss;
                for (const auto &str : path) {
                    ss << str << ".";
                }
                string sol = ss.str();
                sol.pop_back();
                ret.emplace_back(sol);
            }
            return; // find a solution
        }
        for (int i = index; i < index + 3 && i < len; i++) {
            string sub = s.substr(index, i - index + 1);
            if (s[index] == '0' && i != index) {
                break;
            }
            if (!isValid(sub)) {
                continue;
            }
            path.emplace_back(sub);
            dfs(s, path, ret, i + 1);
            path.pop_back();
        }
    }
    
    bool isValid(const string &s) {
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
    
};