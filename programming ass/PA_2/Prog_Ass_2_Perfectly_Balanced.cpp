/*------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * Here we have taken definition of perfectly balanced corresponding to difference of sized and not height.
 *
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define N 200005
int TOBALANCE=1; // TOBALANCE is 1 when the condition is Perfectly balanced, 0 otherwise. By changing this constant you can change balance condition.
int NEARLY_BALANCED = 0;
int PERFECTLY_BALANCED = 1;
double BALANCE_RATIO = 0.75; //You may change this ratio.

/* structure of a node of the binary tree.
val: value at the node
size: size of subtree rooted at node
left,right:pointers to right and left sub tree 
*/
struct Node{
	int val;
	int size;
	struct Node *left,*right;  
};

/*
   This function takes a value and initialises and returns a new node whose value is set to the given parameter.
   */
Node* init(int val){
	Node *curr = (Node *)malloc(sizeof(Node));
	curr->val=val;
	curr->size=1;
	curr->left=curr->right=NULL;
	return curr;
}
/*
SortedArrayFromBST: This function takes as input a node, pointer to an array, and an integer that denotes the next free position in the array.
This function fills in the array all the values in the tree whose root is the given node i.e. output array finally contains the elements in 
increasing order.
This function must return the number of array positions it has filled. i.e. if initial value of parameter fst = p, then after returning from the function the final value must increase by the size of subtree i.e p+curr->size.
*/
int SortedArrayFromBST(Node *curr,int output[],int fst){
	int temp= fst;
	if(curr == NULL )
		return 0;
	fst+=SortedArrayFromBST( curr -> left , output , fst   );
	output[fst] = curr -> val;
	fst++;
	fst+=SortedArrayFromBST( curr -> right , output , fst );
	return fst-temp;

}

/*
   This function creates a BST from an array. It takes as parameters input array and the length of array. It returns the root of the BST
   that is formed by the array
   */
Node *BSTFromSortedArray(int input[], int len){
	if( len == 0)
	{	Node *curr = NULL;  	
		return curr;
	}
	else if( len == 1  )
	{ Node *curr = init( input[0]  ) ;  
		return curr;
	}

	else
	{	
		Node *curr = init( input[len/2]  ) ;
		curr -> size = len ;

		curr -> left = BSTFromSortedArray( input , len/2    ); 
		if ( len != 2 )
			curr -> right = BSTFromSortedArray( (input+len/2+1) , (len - len/2 - 1)  );
		return curr;
	}




}

/*
   This function recursively deletes all the nodes in the tree whose root in pointed by curr
   */
void deleteNode(Node *curr){
	if(curr==NULL) return;
	deleteNode(curr->left); 
	deleteNode(curr->right);
	delete curr;
}

/*
   This function returns true if the current node satisfies the nearly balanced condition and false otherwise
   */
bool checkNearBalance(Node *curr){

	if( curr != NULL )  
	{if ( (curr -> left) != NULL && (curr -> right) != NULL   )
		return   max((curr -> left -> size) , (curr -> right -> size ) ) <= BALANCE_RATIO * ( curr -> size  )  ;
		else if ( (curr -> left) == NULL && (curr -> right) == NULL   )
			return true;	
		else if ( curr -> left == NULL  )
			return  curr -> right -> size <= BALANCE_RATIO * ( curr -> size ) ;
		else   
			return 	 curr -> left -> size <= BALANCE_RATIO * ( curr -> size ) ;
	}
	return true; 

}

/*
   This function returns true if the current node satisfies the perfectly balanced condition and false otherwise
   */
bool checkPerfectBalance(Node *curr){
	if( curr != NULL )  
	{if ( curr -> left != NULL && curr -> right != NULL   )
		return abs((curr -> left -> size)  - (curr -> right -> size) ) <=1;
		else if( (curr -> left) == NULL && (curr -> right) == NULL )
			return true;
		else if ( curr -> left == NULL  )
			return  curr -> right -> size <= 1;
		else 
			return 	 curr -> left -> size <= 1;
	}
	return true; 

}

/*
   This function takes as input a pointer to a node and inserts a node in the subtree of the node depending on the value.
   out[] array is used as a helper array which will be used when the BST does not satisfy the balanced condition.

   -when the insert returns then the tree must satisfy the balanced condition
   */
void insert(Node *&curr,int val,int out[]){
	Node* temp =  curr;
	Node* pretemp= NULL;
	Node* UnBalancedPapa;
	bool NotBalanceNodeFound = false;
	Node *NotBalancedNode = NULL;
	bool ToLeft ;
	((temp) -> size)++;
	while((temp) != NULL )
	{
		if((temp) -> val > val  )
		{ if((temp) -> left != NULL )  
			((temp) -> left -> size)++;
			ToLeft = true;	
		}
		else
		{
			if((temp) -> right != NULL )  
				((temp) -> right -> size)++;
			ToLeft = false;  
		}
		if(! NotBalanceNodeFound )
		{ 
			if(TOBALANCE == PERFECTLY_BALANCED )
			{
				if(!checkPerfectBalance((temp)))
				{
					NotBalanceNodeFound = true;
					NotBalancedNode = (temp);
					UnBalancedPapa=pretemp;
				}
			}
			else if ( TOBALANCE == NEARLY_BALANCED  )	
			{
				if(!checkNearBalance((temp)))
				{
					NotBalanceNodeFound=true;
					NotBalancedNode = (temp);
					UnBalancedPapa=pretemp;	
				}

			}

		}
		if(ToLeft  )
		{	  if(temp -> left != NULL ){
							   pretemp=temp;		      	   
							   (temp) = (temp) -> left;
						   }
		else{     
			temp -> left = init(val);
			break;
		}
		}	  
		else
		{	if(temp -> right != NULL ){
							  pretemp=temp;			  
							  (temp) = (temp) -> right;
						  }
		else{	
			temp -> right = init(val);
			break;
		}		
		}
	}
	if(NotBalancedNode != NULL)
	{		
		SortedArrayFromBST (NotBalancedNode ,out,0  );
		if( UnBalancedPapa == NULL )
			curr = 	BSTFromSortedArray (out , NotBalancedNode -> size );
		else{		if( UnBalancedPapa -> left == NotBalancedNode   )
			UnBalancedPapa -> left = BSTFromSortedArray (out , NotBalancedNode -> size );
			else
				UnBalancedPapa -> right = BSTFromSortedArray (out , NotBalancedNode -> size );
		}
	}


}

/*
   This function takes as input a node pointer and a val and searches for a node which has value val in the subtree of node.
   It returns true if the value is found, false otherwise.
   */
bool search(Node *curr,int val){
	bool isFound=false;
	if(curr != NULL )
	{   if( curr -> val == val  )
		{
			return  true;


		}

		else{	
			isFound =  search (curr -> left , val );
			if( isFound  )  
				return true;	     
			isFound =  search (curr -> right , val ) ;
			if( isFound  )  
				return true;
		}
	}

	return isFound ;
}

int main(){
	Node *root = NULL;
	int out[N];
	int queries; scanf("%d",&queries);
	while(queries--){
		int c,val; scanf("%d%d",&c,&val);
		if(c==1){
			//insert
			if(root){
				insert(root,val,out);

			}else{
				root = init(val);
			}
		}else{
			//search query
			if(search(root,val)) printf("Yes\n"); else printf("No\n");
		}
	}
	return 0;
}
