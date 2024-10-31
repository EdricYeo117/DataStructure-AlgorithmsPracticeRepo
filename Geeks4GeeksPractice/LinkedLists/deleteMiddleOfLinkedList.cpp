// C++ program to delete middle of a linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

Node* deleteMid(Node* head) {
    // Edge case, return nullptr if head is nullptr
    if(head->next == nullptr || head->next == nullptr) {
        return nullptr;
    }

    int count = 0;
    Node* p1 = head;
    Node* p2 = head;

    // First pass, count number of nodes in the linked list, use p1
    while(p1 != nullptr) {
        count++;
        p1 = p1->next;
    }

    // Get index of the middle node
    int mid = count/2;

    // If mid is 0, we only have two nodes, this is an edge case, delete head node in this case?
    if(mid == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Second pass, let p2 move towards the middle node->previous node, use p2
    for (int i = 0; i < mid-1; i++) {
        p2 = p2->next;
    }

    // Delete the middle node
    Node* temp = p2->next;
    // Set pointer of p2 to skip the node to be deleted
    p2->next = p2->next->next;
    delete temp;
    return head;
}