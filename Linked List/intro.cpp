#include <bits/stdc++.h>
using namespace std;

// Represents one node in a singly linked list.
class Node{
    public:
    // The value stored in this node.
    int data;
    // Pointer to the next node in the list, or nullptr for the last node.
    Node* next;

    public:
    // Creates a node with a value and an explicitly supplied next pointer.
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // Creates a node that does not point to another node yet.
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Converts an integer array into a linked list and returns its first node.
Node* ConvertArr2LL(vector<int> &arr){
    // The first array element becomes the head of the linked list.
    Node* head = new Node(arr[0]);
    // mover always points to the last node currently in the list.
    Node* mover = head;

    // Create one node for each remaining array element and append it to the list.
    for(int i = 1; i< arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    // The head is needed to access the complete linked list.
    return head;
}

// Counts and returns the number of nodes in a linked list.
int lengthofLL(Node* head){
    int cnt = 0;
    Node* temp = head;

    // Move through the list until the pointer reaches the end.
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main(){
    // Input values that will be used to build the linked list.
    vector<int> arr = {2,3,8,7,6,5};

    // Example of creating a node with a value and a null next pointer.
    // Node* y = new Node(arr[2], nullptr);
    // cout << y->data;

    // Build the linked list from the array and keep its first node in head.
    Node* head = ConvertArr2LL(arr);
    Node* temp = head;

    // Traverse the list and print the value stored in every node.
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    // Calculate and print the total number of nodes in the list.
    cout<<"\nlength of LL: "<<lengthofLL(head) ;
}