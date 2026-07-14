// Topic : Likden List

/*
Question :
Given the head of a linked list and an integer val, remove all the nodes of the linked list that
has Node.val == val, and return the new head.

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []


Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
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
    ListNode *removeElements(ListNode *head, int val)
    {

        ListNode *temp = new ListNode(0);
        temp->next = head;

        ListNode *curr = temp;

        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }

        return temp->next;
    }
};

// TC:0(n)

// SC:0(1)

/*
Apprach :

Create a dummy node and connect it to the head of the linked list. This helps handle cases where the head node itself needs to be removed.
Initialize a pointer curr to the dummy node.
Traverse the linked list while curr->next is not NULL:

If curr->next->val is equal to val, remove that node by updating:

curr->next = curr->next->next;
Otherwise, move curr to the next node.
After the traversal is complete, return dummy->next as the new head of the modified linked list.
*/