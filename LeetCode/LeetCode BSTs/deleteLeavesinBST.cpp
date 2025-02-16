
struct BinaryNode
{
   int item;
   BinaryNode* left;
   BinaryNode* right;
};


void BST::removeLeaves(BinaryNode* &t)
{
   if (t != NULL)                                   
   {
	if (t->left == NULL && t->right == NULL)      
      {
	   // remove(t->item);
	   BinaryNode* temp = t;                      
	   t = NULL;                                  
	   delete(temp);                              
      }
	else                                          
	{
	   removeLeaves(t->left);                     
	   removeLeaves(t->right);                    
	}
   }
}
