/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node *ptr = head;
        while (ptr != nullptr) {
            if (ptr->child != nullptr) {
                child2brother(ptr);
            }
            else {
                ptr = ptr->next;
            }
        }
        return head;
    }

    Node *child2brother(Node *parent) {
        Node *nextNode = parent->next;
        Node *child = parent->child;
        parent->child = nullptr;
        parent->next = child;
        child->prev = parent;
        while (child != nullptr) {
            if (child->child != nullptr) {
                child2brother(child);
            }
            else {
                if (child->next != nullptr)
                    child = child->next;
                else 
                    break;
            }
        }
        child->next = nextNode;
        if (nextNode != nullptr)
            nextNode->prev = child;
        return child;
    }
        
};