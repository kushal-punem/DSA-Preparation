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