class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if (!head || !head->next || !head->next->next) return ans;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int firstIdx = -1, lastIdx = -1, prevIdx = -1;
        int minDistance = INT_MAX;
        int idx = 1;
        
        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDistance = min(minDistance, idx - prevIdx);
                }
                prevIdx = idx;
                lastIdx = idx;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        
        if (firstIdx != -1 && lastIdx != firstIdx) {
            ans[0] = minDistance;
            ans[1] = lastIdx - firstIdx;
        }
        return ans;
    }
};