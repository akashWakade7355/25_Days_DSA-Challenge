// Topic : Linked List

/*
Question :

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

// Solution :

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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
   if(head == nullptr)
            return nullptr;

        int count = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            count++;
            temp = temp->next;
        }


        temp = head;

        for(int i = 0; i < count / 2; i++){
            temp = temp->next;
        }

        return temp;
    }
};

// TC:0(n)

// SC:0(1)

/*
Apprach :

1. Handle the Edge Case
   - If the linked list is empty (`head == nullptr`), return `nullptr`.

2. Count the Total Number of Nodes
   - Traverse the linked list using a temporary pointer.
   - Increment a counter for each node encountered.
   - After the traversal, the counter stores the length of the linked list.

3. Find the Middle Node
   - Reset the temporary pointer back to the head.
   - Move the pointer `count / 2` steps forward.
   - For an odd-length list, this lands on the middle node.
   - For an even-length list, integer division (`count / 2`) naturally positions the pointer at the **second middle node**, which satisfies the problem statement.

4. Return the Middle Node
   - Return the pointer after completing the traversal.
*/