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

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    
    //insert if no Node is present
    if(head == NULL){
        insertAtHead(head, d);
        return;
    }

    //insert at last Node
    if(head -> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    //create cnt to traverse to that position 
    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    
    }

    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;


}

void deleteNode(Node* &head, int position){
    
    //delete start node 
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }else{

        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < position){
            curr = curr -> next;
            prev = curr;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }

}

bool isCircularList(Node* &head){

    Node* temp = head -> next;

    while(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    }else{
        return false;
    }
}

bool detecLoop(Node* &head){

    //empty list
    if(head == NULL) return false;
     
    //using map
    map<Node*, bool> visited;

    Node* temp = head;
    while(temp != NULL){

        //if cycle is present
        if(visited[temp] == true) return true;

        visited[temp] = true;
        temp = temp -> next;
        
    }

    return false;

}


//detect loop using slow and fast approach
Node* floydDetectLoop(Node* head){

    //if empty list
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL){
        fast = fast -> next;

        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast){
            cout << "present at: " << slow -> next << endl;
            return slow;
        }

        return NULL;

    }


}


// Distance travelled by fast = 2 * distance travelled by slow
// A + X * C = A + Y * C + B
// A + B = x times of C
Node* getStartingNode(Node* head){
    
    if(head == NULL) return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;

    }

    return slow;

}


void removeLoop(Node* head){
    
    if(head == NULL) return NULL;

    Node* startOfLoop = floydDetectLoop(head);
    Node* temp = head;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }

    temp -> next = NULL;

}


int main(){
    
    //creating new Node
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtPosition(head, tail, 5, 55);
    print(head);

    //20 10 30 40 50 
    
}