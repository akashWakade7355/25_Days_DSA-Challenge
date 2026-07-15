// Topic : Linked List

/*
Question :
Given the head of a sorted singly linked list, remove all duplicate nodes so that each element appears only once. The resulting linked list should remain sorted.

Note: Try to solve the problem without using extra space.

Examples:

Input: Head: 2->2->4->5
Output: 2 -> 4 -> 5

Explanation: In the given linked list 2 -> 2 -> 4 -> 5, only 2 occurs more than 1 time. So we need to remove it once.
Input: Head: 2->2->2->2->2
Output: 2

Explanation: In the given linked list  2 -> 2 -> 2 -> 2, 2 is the only element and is repeated 5 times. So we need to remove any four 2.
Constraints:
1 ≤ Number of nodes, data of nodes ≤ 105 
*/

// Solution :

/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if (head == NULL) return head;

        Node *curr = head;

        while (curr != NULL && curr->next != NULL) {
            if (curr->data == curr->next->data) {
                Node *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};

// TC:0(n)

// SC:0(1)

/*
Approach

Step 1:
Check if the linked list is empty. If `head` is `NULL`, return `head` since there are no nodes to process.

Step 2:
Initialize a pointer `curr` to the head of the linked list.

Step 3:
Traverse the linked list while both `curr` and `curr->next` are not `NULL`.

Step 4:
Compare the data of the current node with the next node.
- If both values are equal, a duplicate node is found.
- Remove the duplicate node by updating `curr->next` to skip the duplicate node.
- Delete the duplicate node to free the allocated memory.

Step 5:
If the current node and the next node have different values, move `curr` to the next node.

Step 6:
Continue this process until the end of the linked list is reached.

Step 7:
Return the head of the modified linked list containing only unique elements.

*/