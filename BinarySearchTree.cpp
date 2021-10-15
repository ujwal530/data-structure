#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node * left;
    Node*right;

    Node(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~Node() {
        delete left;
        delete right;
    }
};


//class node {
//public:
//    int data;
//    node* next;
//
//    node(int data) {
//        this->data = data;
//        next = NULL;
//    }
//};


class BST {
    Node<int> *root;

public:

    BST() {
        root = NULL;
    }

    ~BST() {
        delete root;
    }

private:
    bool hasData(Node<int>* node, int data) {
        if (node == NULL) {
            return 0;
        }

        cout << node->data << endl;
        if (node->data == data) {
            return true;
        }
        else if (node->data > data) {
            return hasData(node->left, data);
        }
        else
            return hasData(node->right, data);
    }
public:
    bool hasData(int data) {
        return hasData(root, data);
    }
private:
    Node<int>* insert(Node<int>* node, int data) {
        if (node == NULL) {
            Node<int>* x = new Node<int>(data);
            return x;
        }

        if (node->data >= data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }

        return root;
    }
public:
    Node<int>* insert(int data) {
         this->root = insert(root, data);
    }
    
//    
//    private:
//    	Node<int>* deleteElement(Node<int>*node, int data){
//    		if(node==NULL)
//    		return NULL;
//		if(data > node->data){
//			node->right = deleteElement(node->right,data);
//		}else if(data < node->data){
//			node->left= deleteElement(node->left,data);
//		}else{
//			if(node->left==NULL){
//			}
//		}
//		
//	}
    
    
};
void printLevelWise(Node<int>* root) {
    if (root == NULL) {
        return;
    }
    queue<Node<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty() ) {
        Node<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front != NULL) {
            cout << front->data << " ";
            if (front->left != NULL ) {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL) {
                pendingNodes.push(front->right);
            }
        } else {
            if (pendingNodes.empty()) {
                break;
            }
            cout << endl;
            pendingNodes.push(NULL);
        }
    }


}

Node<int>* takeInput() {
    int rootData;
    cout << "Enter the root data ";
    cin >> rootData;

    Node<int> *root = new Node<int>(rootData);

    queue<Node<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        Node<int> * front = pendingNodes.front();
        pendingNodes.pop();

        int leftchildData;
        cout << "Enter the left child of " << front->data << endl;
        cin >> leftchildData;
        if (leftchildData != -1) {
            Node<int> *child = new Node<int>(leftchildData);
            front->left = child;
            pendingNodes.push(child);
        }

        int rightchildData;
        cout << "Enter the right child of " << front->data << endl;
        cin >> rightchildData;
        if (rightchildData != -1) {
            Node<int> *child = new Node<int>(rightchildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;

}



void inOrder(Node<int> *root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


void printElement(Node<int>*root, int k1, int k2) {
    if (root == NULL)
        return;




    if (root->data >= k1 && root->data <= k2) {
        cout << root->data;
    }
    if (root->data > k1) {
        printElement(root->left, k1, k2);
    }

    if (root->data < k2)
        printElement(root->right, k1, k2);


}

bool isBST(Node<int>*root, int mini, int maxi) {
    if (root == NULL) {
        return true;
    }
    if (root->data < mini || root->data > maxi) {
        return false;
    }

    bool leftAns = isBST(root->left, mini, root->data - 1);
    bool rightAns = isBST(root->right, root->data, maxi);

    return (leftAns && rightAns);
}

Node<int>* constructBST(int *a, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    cout << mid << endl;
    Node<int>* root = new Node<int>(a[mid]);
    root->left = constructBST(a, start, mid - 1);
    root->right = constructBST(a, mid + 1, end);
    return root;
}

void preOrder(Node<int>*root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//pair<node*, node*> bstToLL(Node<int>*root) {
//    if (root == NULL) {
//        pair<node*, node*>p;
//        p.first = NULL;
//        p.second = NULL;
//        return p;
//    }
//
//
//    pair<node*, node*> lLinked = bstToLL(root->left);
//    pair<node*, node*> rLinked = bstToLL(root->right);
//
//    node* newNode = new node(root->data);
//    cout << root->data << endl;
//    if (lLinked.first == NULL && lLinked.second == NULL) {
//        pair<node*, node*> p  = make_pair(newNode, newNode);
//        return p;
//    } else {
//        lLinked.second->next = newNode;
//        newNode->next = rLinked.first;
//    }
//
//    node* lhead = lLinked.first;
//    node* ltail = lLinked.second;
//    node* rhead = rLinked.first;
//    node* rtail = rLinked.second;
//
//    pair<node*, node*>p;
//    p.first = lhead;
//    p.second = rtail;
//
//
//    return p;
//
//
//}

void path(Node<int>*root, int data, bool ans) {
    if (root == NULL)
    {
        return ;
    }


    if (root->data == data) {
        cout << root->data << " ";
        return ;
    }
    if (data < root->data) {
        path(root->left, data, ans);
    }
    else {
        path(root->right, data, ans);
    }

    cout << root->data << " ";

}

int main() {
	BST b;
    Node<int>* root;
    for(int i=0; i<n; i++){
    	 int data;
    cin >> data;
	}
   
    path(root, data, false);
    return 0;
}
