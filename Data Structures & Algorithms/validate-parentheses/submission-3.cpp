#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        // Base Case: If String length isn't even, then invalid amount of characters
        if (s.length() % 2 != 0) { return false; }

        unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> char_stack;

        for (auto &ch : s) {
            // Check if current character is in mapping
            auto value = mapping.find(ch);
            if (value != mapping.end()) {
                // Key found
                if (char_stack.empty() || value->second != char_stack.top()) {
                    return false;
                } else {
                    char_stack.pop();
                    continue;
                }
            } else {
                // Key not found, hence, opening parenthesis
                char_stack.push(ch);
            }
        }
        if (char_stack.empty()) {
            return true;
        }
        return false;
    }
};
