#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    Node* left;
    int val;
    Node* right;

    Node(int d){
        this -> left = NULL;
        this -> val = d;
        this -> right = NULL;
    }

    // Recursively delete left and right children to prevent memory leaks
    ~Node(){
        int data = this -> val;

        if(this -> left != NULL){
            delete left;
            this -> left = NULL;
        }

        if(this -> right != NULL){
            delete right;
            this -> right = NULL;
        }


        cout << "Node with the data: " << data << " is deleted \n";
    }

};

void recursiveInorder(Node* root){
    
    if(root == NULL) return;

    //[LNR]
    recursiveInorder(root -> left);
    cout << root -> val << " ";
    recursiveInorder(root -> right);
    
}

void recursivePreOrder(Node* root){
    
    if(root == NULL) return;
    
    //[NLR]
    cout << root -> val << " ";
    recursivePreOrder(root -> left);
    recursivePreOrder(root -> right);
    
}

void recursivePostOrder(Node* root){
    
    if(root == NULL) return;
    
    //[LRN]
    recursivePostOrder(root -> left);
    recursivePostOrder(root -> right);
    cout << root -> val << " ";
    
}

void levelOrder(Node* root){

    //2D vector to store the level-wise node
    // level 1 -> [1]
    // level 2 -> [2 3]
    // level 3 -> [4 5 6 7]
    vector<vector<int>> ans;

    if(root == NULL) return;

    //Create Queue to store the element|node of type Node*
    queue<Node*> q;
    
    //Step 1: ensure|ADD root node in Queue
    q.push(root);

    while(!q.empty()){
        //This size indicates the number of nodes at the current level.
        int size = q.size();

        //Create a vector ‘level’ to store the nodes at the current level.
        vector<int> level;

        for(int i = 0; i < size; i++){

            Node* front = q.front();
            q.pop();

            // Store the front value in the current level vector
            level.push_back(front -> val);

            // Enqueue the child nodes if they exist
            if(front -> left != NULL) q.push(front -> left);
            if(front -> right != NULL) q.push(front -> right);

        }   

        //store the current level in the answer vector
        ans.push_back(level);
    }

    cout << " ";
    for(auto &level: ans){
        for(int ele: level)
        cout << ele << " ";
    }
    
}

void iterativePreOrder(Node* root){

    if(root == NULL) return;

    stack<Node*> s;
    vector<int> preorder;

    s.push(root);

    while(!s.empty()){

        Node* top = s.top();
        s.pop();

        preorder.push_back(top -> val);

        if(top -> right != NULL) s.push(top -> right);
        if(top -> left != NULL) s.push(top -> left);

    }

    for(auto &ele: preorder){
        cout << ele << " ";
    }

}

int main(){
    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);


    cout << "\n InOrder: ";
    recursiveInorder(root);
    cout << "\n PreOrder: ";
    recursivePreOrder(root);
    cout << "\n PostOrder: ";
    recursivePostOrder(root);
    cout << "\nlevelOrder: " ;
    levelOrder(root);
    cout << "\niterativePreOrder: ";
    iterativePreOrder(root);
    
    //It calls the destructor ~Node() for the Node which is pointed ny root before freeing the memory.
    // delete root;


}