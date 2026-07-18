// Topic : Linked List

/*
Question :
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
*/

// solution :

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return;

        // Step 1: Find middle
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split
        ListNode *second = slow->next;
        slow->next = nullptr;

        // Step 3: Reverse second half
        ListNode *prev = nullptr;

        while (second != nullptr)
        {
            ListNode *nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }

        second = prev;

        // Step 4: Merge
        ListNode *first = head;

        while (second != nullptr)
        {

            ListNode *firstNext = first->next;
            ListNode *secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};

/*
# Approach

### Step 1: Find the Middle of the Linked List
- Use two pointers:
  - `slow` moves one node at a time.
  - `fast` moves two nodes at a time.
- When `fast` reaches the end of the list, `slow` will be at the middle.

### Step 2: Split the Linked List
- Store the node after the middle as the head of the second half.
- Break the linked list into two separate halves by setting:
  ```cpp
  slow->next = nullptr;
  ```

### Step 3: Reverse the Second Half
- Reverse the second half of the linked list using the iterative reversal technique.
- After reversing, the last node of the original list becomes the head of the reversed second half.

### Step 4: Merge the Two Halves
- Maintain two pointers:
  - One for the first half.
  - One for the reversed second half.
- Alternately connect one node from the first half and one node from the second half until all nodes of the second half are merged.
- This produces the required order:
  ```
  L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
  ```

---

# Time Complexity

- Finding the middle: **O(n)**
- Reversing the second half: **O(n/2)**
- Merging the two halves: **O(n)**

Overall Time Complexity:

**O(n)**

---

# Space Complexity

- No extra data structures are used.
- Only a few pointer variables are maintained.

Overall Space Complexity:

**O(1)**
*/