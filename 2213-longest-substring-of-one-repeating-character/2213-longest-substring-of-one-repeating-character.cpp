class Solution {
public:
    struct Node {
        char left_char, right_char;
        int length, prefix, suffix, best;
    };

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        vector<Node> tree(4 * n);

        auto merge = [](const Node& left, const Node& right) {
            Node res;
            res.left_char = left.left_char;
            res.right_char = right.right_char;
            res.length = left.length + right.length;

            res.prefix = left.prefix;
            if (left.left_char == right.left_char && left.prefix == left.length) {
                res.prefix = left.length + right.prefix;
            }

            res.suffix = right.suffix;
            if (right.right_char == left.right_char && right.suffix == right.length) {
                res.suffix = right.length + left.suffix;
            }

            res.best = max(left.best, right.best);
            if (left.right_char == right.left_char) {
                res.best = max(res.best, left.suffix + right.prefix);
            }

            return res;
        };

        auto build = [&](auto& self, int node, int start, int end) -> void {
            if (start == end) {
                tree[node] = {s[start], s[start], 1, 1, 1, 1};
                return;
            }
            int mid = start + (end - start) / 2;
            self(self, 2 * node, start, mid);
            self(self, 2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        };

        auto update = [&](auto& self, int node, int start, int end, int index, char ch) -> void {
            if (start == end) {
                tree[node] = {ch, ch, 1, 1, 1, 1};
                return;
            }
            int mid = start + (end - start) / 2;
            if (index <= mid) {
                self(self, 2 * node, start, mid, index, ch);
            } else {
                self(self, 2 * node + 1, mid + 1, end, index, ch);
            }
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        };

        build(build, 1, 0, n - 1);

        vector<int> answer;
        int k = queryCharacters.length();
        for (int i = 0; i < k; ++i) {
            update(update, 1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            answer.push_back(tree[1].best);
        }

        return answer;
    }
};