// Linked List

/*
Question :
You are given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the head of the modified Linked List.

Examples :

Input: x = 6,

Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6
Explanation: We can see that 6 is inserted at the end of the linkedlist.

Input: x = 1,

Output: 4 -> 5 -> 1
Explanation: We can see that 1 is inserted at the end of the linked list.

Constraints:
0 ≤ number of nodes ≤ 105
0 ≤ node->data , x ≤ 103
*/

// solution :

/*
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        // Code here

        if (head == nullptr)
            return new Node(x);
        Node *temp1 = head;
        int count = 0;

        while (temp1 != nullptr)
        {
            count++;
            temp1 = temp1->next;
        }

        int len = count;

        Node *newNode = new Node(x);

        Node *temp2 = head;

        for (int i = 1; i < len; i++)
            temp2 = temp2->next;

        newNode->next = temp2->next;
        temp2->next = newNode;

        return head;
    }
};

// TC:0(n)

// SC:0(1)

/*
Apprach :

1. Create a new node with the given value `x`.
2. If the linked list is empty (`head == nullptr`), return the newly created node as the head.
3. Traverse the linked list to calculate its total length.
4. Start again from the head and move to the last node of the linked list.
5. Link the newly created node to the end by updating the `next` pointer of the last node.
6. Return the head of the modified linked list.

*/