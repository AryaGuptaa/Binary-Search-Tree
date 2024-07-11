#include<iostream> 
#include<queue>
using namespace std;

//insert to BST
//creation of BST
//level order traversal
//inorder traversal
//post order traversal
//pre order traversal
//min value
//max value
//search in BST
//delete in BST
// BST from Inorder


class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this-> data = data;
        this -> left = NULL;
        this-> right = NULL;
    }
};

Node* insertToBst(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root-> right = insertToBst(root-> right, data);
    }
    else{
        root-> left = insertToBst(root-> left, data);
    }
    return root;
}

void createBST(Node* &root) {
    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;

    while(data != -1) {
        root = insertToBst(root, data);
        cout<<"enter the data: "<<endl;
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<< endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data<<" ";
            if(temp -> left != NULL) {
                q.push(temp ->left);
            }
            if(temp -> right != NULL) {
                q.push(temp ->right);
            }
        }
    }
}

int inOrderTraversal(Node* root) {
    if(root == NULL){
        return 0;
    }
    inOrderTraversal(root-> left);
    cout<<root-> data<<" ";
    inOrderTraversal(root-> right);
}

int postOrderTraversal(Node* root) {
    if(root == NULL){
        return 0;
    }
    postOrderTraversal(root-> left);
    postOrderTraversal(root-> right);
    cout<<root-> data<<" ";
}

int preOrderTraversal(Node* root) {
    if(root == NULL){
        return 0;
    }
    cout<<root-> data<<" ";
    preOrderTraversal(root-> left);
    preOrderTraversal(root-> right);
}

Node* minValue(Node* root) {
    if(root == NULL){
        cout<<"No Min value"<<endl;
        return NULL;
    }
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp-> left;
    }
    return temp;
}

Node* maxValue(Node* root) {
    if(root == NULL){
        cout<<"No Max value"<<endl;
        return NULL;
    }
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp-> right;
    }
    return temp;
}

bool searchBST(Node* root, int target) {
    if(root == NULL){
        return false;
    }
    if(root ->data == target) {
        return true;
    }

    bool leftAns = false;
    bool rightAns = false;

    if(target > root -> data){
        rightAns = searchBST(root-> right, target);
    }
    else{
        leftAns = searchBST(root-> left, target);
    }

    return leftAns || rightAns;
}

Node* deleteBST(Node* root, int target) {
    if(root == NULL) {
        return NULL;
    }
    if(root-> data == target){
            
        if(root-> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        else if(root-> left != NULL && root -> right == NULL){
            Node* childST =root-> left;
            delete root;
            return childST;
        }
        else if(root-> left == NULL && root -> right != NULL){
            Node* childST = root-> right;
            delete root;
            return childST;
        }
        else if(root-> left != NULL && root -> right != NULL){
            //left subtree ki max value OR right subtree ki min value
            Node* maxi = maxValue(root->left);
            //replacement
            root-> data= maxi-> data;
            //delete actual maxi wali node
            root-> left = deleteBST(root-> left, maxi-> data);
            return root;
        }
        
    }
    if(root-> data > target) {
        root-> left =deleteBST(root -> left, target);
    }
    if(root-> data < target) {
        root-> right= deleteBST(root-> right, target);
    }
    return root;
}

Node* bstFromInorder(int inOrder[], int s, int e){
    if( s> e){
        return NULL;
    }

    int mid = (s+e)/2;
    Node* root = new Node(inOrder[mid]);

    root-> left = bstFromInorder(inOrder, s, mid -1);
    root-> right = bstFromInorder(inOrder,mid+1, e);

    return root;
}



int main() {

    // Node* root = NULL;
    // createBST(root);

    // levelOrderTraversal(root);

    // cout<<endl<<"Inorder: ";
    // inOrderTraversal(root);
    // cout<<endl<<"Preorder: ";
    // preOrderTraversal(root);
    // cout<<endl<<"Postorder: ";
    // postOrderTraversal(root);

    // cout<<endl<<endl;
    // Node* minNode = minValue(root);
    // if(minNode ==NULL){
    //     cout<<"There is no nodein a tree, hence no min value"<<endl;
    // }
    // else{
    //     cout<<"Minvalue: "<<minNode -> data<<endl;
    // }

    // cout<<endl;
    // Node* maxNode = maxValue(root);
    // if(maxNode ==NULL){
    //     cout<<"There is no node in a tree, hence no max value"<<endl;
    // }
    // else{
    //     cout<<"Maxvalue: "<<maxNode -> data<<endl;
    // }

    // // int t;
    // // cout<<"Enter the target: ";
    // // cin>>t;
    // // while(t != -1){
    // //     bool ans = searchBST(root, t);
    // //     if(ans == true){
    // //         cout<<"Found"<<endl;
    // //     }
    // //     else{
    // //         cout<<"Not found"<<endl;
    // //     }
    // //     cout<<"Enter the target: ";
    // //     cin>>t;
    // // }

    // int target;
    // cout<<"enter the element to delete:";
    // cin>>target;
    // while(target!= -1){
    //     root = deleteBST(root, target);
    //     cout<<" Level order traversal:"<<endl;
    //     levelOrderTraversal(root);

    //     cout<<"enter the element to delete:";
    //     cin>>target;
        
    // }

    //50 30 60 25 40 70 80 55 -1


    int inOrder[] = {10,20,30,40,50,60,70};
    int s = 0;
    int size = 7;
    int e= size -1;
    Node* root = bstFromInorder(inOrder,s, e);

    levelOrderTraversal(root);
    return 0;
}