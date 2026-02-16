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

void iterativeInOrder(Node* root){

    stack<Node*> s;
    vector<int> inorder;
    Node* node = root;

    while(true){
        //if node is not null, then push to stack and move to left
        if(node != NULL){
            s.push(node);
            node = node -> left;
        }
        else{
            //if stack is empty do nothing
            if(s.empty() == true) break;

            //take top of stack and push it into inorder and move to right
            node = s.top();
            s.pop();
            inorder.push_back(node -> val);
            node = node -> right;

        }

    }

    for(auto &i: inorder){
        cout << i << " ";
    }

}

void iterativePostOrder_2Stack(Node* root){

    stack<Node*> s1, s2;
    vector<int> postorder;
    
    //
    if(root == NULL) return;

    s1.push(root);

    while(!s1.empty()){

        root = s1.top();
        s1.pop();

        s2.push(root);

        if(root -> left != NULL) s1.push(root -> left);
        if(root -> right != NULL) s1.push(root -> right);

    }

    while(!s2.empty()){
        postorder.push_back(s2.top() -> val);
        s2.pop();
    }

    for(auto &i: postorder){
        cout << i << " ";
    }

}


void iterativePostOrder_1Stack(Node* root){

    stack<Node*> s1;
    vector<int> postorder;
    Node* curr = root;

    while(curr != NULL || !s1.empty()){

        if(curr != NULL){
            s1.push(curr);
            curr = curr -> left;
        }
        else{
            Node* temp = s1.top() -> right;

            if(temp == NULL){
                temp = s1.top();
                s1.pop();
                postorder.push_back(temp -> val);


                while(!s1.empty() && temp == s1.top() -> right){
                    temp = s1.top();
                    s1.pop();
                    postorder.push_back(temp -> val);
            
                }

            }else{
                curr = temp;
            }
            
        }


    }
    
    for(auto &i: postorder){
        cout << i << " ";
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
    
    cout << "\niterativeInOrder: ";
    iterativeInOrder(root);
    
    cout << "\niterativePostOrder_2Stack: ";
    iterativePostOrder_2Stack(root);
    
    cout << "\niterativePostOrder_1Stack: ";
    iterativePostOrder_1Stack(root);

    //It calls the destructor ~Node() for the Node which is pointed ny root before freeing the memory.
    // delete root;


}