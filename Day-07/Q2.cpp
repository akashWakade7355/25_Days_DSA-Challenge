// Topic : Linked List

/*
Question :

Given the head of a Singly Linked List and a number k, find the data of the modular node of the linked list.
If no such index is present return -1.

A modular node is defined as the last node in the linked list whose position is divisible by k (pos % k==0).

Note: 1-based position is followed, i.e., position of the first node is 1 and second node is 2.

Examples :

Input: head: 19->28->37->46->55, k = 2

Output: 46
Explanation: The position 4 is divisible by k. The node at this position is 46.
Input: head: 1->2->3->4->5->6->7, k = 10

Output: -1
Explanation: No position is divisible by k as the max position is 7 only.

Constraints:
1 <= number of nodes <= 105
1 <= node->data , k <= 105
*/

// solution :

// Struture of the node of the linked list is as:

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int modularNode(Node *head, int k)
    {
        // code here
        Node *temp1 = head;
        Node *temp2 = head;

        int count = 0;
        while (temp1 != nullptr)
        {
            count++;
            temp1 = temp1->next;
        }

        int len = count;

        int diff = len - len % k;

        if (diff == 0)
            return -1;

        for (int i = 1; i < diff; i++)
            temp2 = temp2->next;

        return temp2->data;
    }
};

// TC:0(n)

// SC:0(1)

/*
Approach :

1. Traverse the linked list to calculate its total length `len`.
2. Find the largest position that is divisible by `k` using:
   diff = len - (len % k);

   This gives the position of the last modular node.
3. If `diff == 0`, it means no position in the linked list is divisible by `k`, so return `-1`.
4. Otherwise, start from the head and move `diff - 1` steps to reach the node at position `diff`.
5. Return the data of that node.

*/