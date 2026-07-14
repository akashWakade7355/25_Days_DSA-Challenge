// Topic : Linked List

/*
Question :
Given the head of a sorted singly linked list, remove all 
duplicate nodes so that each element appears only once.
 The resulting linked list should remain sorted.

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

// solution :

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
Approach :

step 1 :Initialize a pointer curr to the head of the linked list.
step 2 :Traverse the list while curr and curr->next are not NULL.

If curr->data is equal to curr->next->data, remove the duplicate node by updating:

curr->next = curr->next->next;
Otherwise, move curr to the next node.
Continue until the end of the list and return the head.
*/