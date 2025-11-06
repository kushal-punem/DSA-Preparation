#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    
    //constrcutor
    Node(int d ){
        this -> data = d;
        this -> next = NULL;
    }
    
    //destructor
    ~Node(){
        int value = this -> data;
        
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        
        cout << "Memory is free for this node with the data: " << value;
        
    }
};


//print data of LinkedList
void print(Node* head){

    //if list is empty
    if(head == NULL){
        cout << "List is empty: " << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;

}

//function to insert node at tail
void insertAtTail(Node* &tail, int d){

    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;

}

void solve(Node* first, Node* second){

    //if only single node is  present in first list respectively then merge both of them
    if(first -> next == NULL){
        first -> next = second;

    }

        



}


void sortTwoList(Node* first, Node* second){
    
    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first ->  data <= second -> data)
        solve(first, second);
    else
        solve(second, first);
    
}

int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(10);

    Node* head1 = node1;
    Node* tail1 = node1;

    Node* head2 = node2;
    Node* tail2 = node2;

    insertAtTail(tail1, 2);
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 2);

    insertAtTail(tail2, 20);
    insertAtTail(tail2, 30);
    insertAtTail(tail2, 20);
    insertAtTail(tail2, 20);

    print(head1);
    print(head2);



    return 0;
}