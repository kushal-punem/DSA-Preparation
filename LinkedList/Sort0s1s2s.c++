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


void new_insertAtTail(Node* &tail, Node* curr ){

    tail -> next = curr;
    tail = curr;

}



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


// function to insert node at head
void insertAtHead(Node* &head, int d){
    
    Node* newNode = new Node(d);
    newNode -> next = head;
    head = newNode;

}

//function to insert node at tail
void insertAtTail(Node* &tail, int d){

    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;

}

void sortLL1(Node* &head){

    //approach 1 -> here data is getting replaced

    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    Node* temp = head;


    //count #0s 1s and 2s 
    while(temp != NULL){

        if(temp -> data == 0)
            countZero++;
        else if(temp -> data == 1)
            countOne++;
        else if(temp -> data == 2)
            countTwo++;

        temp = temp -> next;
    }

    // replace data according to the count
    temp = head;
    while(temp != NULL){
        if(countZero != 0){
            temp -> data = 0;
            countZero--;
        }else if (countOne != 0){
            temp -> data = 1;
            countOne--;
        }else if(countTwo != 0){
            temp -> data = 2;
            countTwo--;
        }

        temp = temp -> next;
    
    }

}




Node* sortSLL2(Node* &head){

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;


    // create separate list for 0s 1s and 2s
    Node* curr = head;
    while(curr != NULL){
        int value = curr -> data;
        
        if(value == 0){
            new_insertAtTail(zeroTail, curr);
            // if(zeroHead->data == -1) zeroHead = zeroTail;
        }
        else if(value == 1){
            new_insertAtTail(oneTail, curr);
        }
        else if(value == 2){
            new_insertAtTail(twoTail, curr);
        }

        curr = curr -> next;

    }

    //merge 3 sublist

    //1s list is not empty
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }else{

        //1s list is empty 
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;      // connect oneTail with twoHead
    twoTail -> next = NULL;                 // set last node to NULL

    //set up all heads and then remove dummpy heads
    head = zeroHead -> next;

    //first break the links for node to be delete
    zeroHead = nullptr;
    oneHead = nullptr;
    twoHead = nullptr;

    //remove dummpy heads
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}


int main(){

    //create new node 
    Node* node1 = new Node(0);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);

    print(head);

    // sortLL1(head);
    Node* newHead = sortSLL2(head);

    cout<< "After sorting: \n";
    print(newHead);

}