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

    if(root == NULL) return ans;

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

            //store the current level in the answer vector
            ans.push_back(level);

        }

        return ans;
    }
    
}

int main(){
    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> right = new Node(5);

    cout << "\n InOrder: ";
    recursiveInorder(root);
    cout << "\n PreOrder: ";
    recursivePreOrder(root);
    cout << "\n PostOrder: ";
    recursivePostOrder(root);

    cout << endl;
    
    //It calls the destructor ~Node() for the Node which is pointed ny root before freeing the memory.
    delete root;


}