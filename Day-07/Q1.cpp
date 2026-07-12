// Topic : Linked List

/*
Question :

Given a linked list, check whether the length of the linked list is even or not.
Return true if it is even, otherwise false.

Examples:

Input: Linked list: 12->52->10->47->95->0

Output: true
Explanation: The length of the linked list is 6 which is even.
Input: Linked list: 9->4->3

Output: false
Explanation: The length of the linked list is 3 which is odd.

Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ elements of the linked list ≤ 105
*/

// solution :

Structure of link list node class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Solution
{
public:
    bool isEven(Node *head)
    {
        // code here

        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        if (count % 2 == 0)
            return true;

        return false;
    }
};

// TC:0(n)

// SC:0(1)

/*

Aprrach :

1. Initialize a pointer `temp` to the head of the linked list.
2. Initialize a variable `count` to `0` to keep track of the number of nodes.
3. Traverse the linked list until `temp` becomes `nullptr`.
   - Increment `count` by `1`.
   - Move `temp` to the next node.
4. After traversing the entire list, check whether `count` is even.
   - If `count % 2 == 0`, return `true`.
   - Otherwise, return `false`.

*/