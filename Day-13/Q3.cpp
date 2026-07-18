// Topic : Linked List

/*
Question :
Given the head of a singly linked list, group all the nodes with odd indices
together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
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
    ListNode *oddEvenList(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        while (even != nullptr && even->next != nullptr)
        {

            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};

/*
# Approach

### Step 1: Handle Base Cases
- If the linked list is empty or contains only one node, no reordering is required.
- Return the head as it is.

### Step 2: Initialize Pointers
- Create three pointers:
  - `odd` pointing to the first node (odd index).
  - `even` pointing to the second node (even index).
  - `evenHead` to store the head of the even-indexed list so that it can be attached after all odd-indexed nodes at the end.

### Step 3: Separate Odd and Even Indexed Nodes
- Traverse the linked list while both `even` and `even->next` are not `nullptr`.
- Connect the current odd node to the next odd-indexed node.
- Move the `odd` pointer one step forward.
- Connect the current even node to the next even-indexed node.
- Move the `even` pointer one step forward.
- Continue this process until all odd and even indexed nodes are separated.

### Step 4: Merge the Two Lists
- After the traversal, attach the head of the even-indexed list (`evenHead`) to the end of the odd-indexed list.
- Return the original head of the linked list.

---

# Time Complexity

- Traverses the linked list only once.

**Overall Time Complexity:** **O(n)**

---

# Space Complexity

- No extra data structures are used.
- Only a few pointer variables are maintained.

**Overall Space Complexity:** **O(1)**
*/
