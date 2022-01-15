Given a full binary expression tree consisting of basic binary operators (+ , – ,*, /) and some integers, Your task is to evaluate the expression tree.

Example 1:

Input: 
              +
           /     \
          *       -
        /  \    /   \
       5    4  100  20 

Output: 100

Explanation:
((5 * 4) + (100 - 20)) = 100
  
  
  //------------------------------------------------------------------------- recursive --------------------------------------------------------------------------------------
  
   int evalTree(node* root) {
        // Your code here
        if(root->left==NULL && root->right==NULL){
            return stoi(root->data);
        }
        if(root->data=="+"){
            return evalTree(root->left)+evalTree(root->right);
        }
        if(root->data=="-"){
            return evalTree(root->left)-evalTree(root->right);
        }
        if(root->data=="*"){
            return evalTree(root->left)*evalTree(root->right);
        }
        if(root->data=="/"){
            return evalTree(root->left)/evalTree(root->right);
        }
    }
