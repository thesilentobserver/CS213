//-----Include required headers here-----
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//-----End of headers-----


//-----Add new functions here(if any)-----

//-----New functions end here-----

//-----A Doubly Linked List Node-----
// DO NOT MODIFY IT
struct DLLNode {
    struct DLLNode *prev;
    int data;
    struct DLLNode *next;
};
 
/* Representation of the stack data structure that supports findMiddle(),
   deleteMiddle() in O(1) time.  The Stack is implemented using Doubly 
   Linked List. It maintains pointer to head node, pointer to middle 
   node and count of nodes */
// DO NOT MODIFY IT
struct myStack {
    struct DLLNode *head;
    struct DLLNode *mid;
    int count;
};
 
//-----Function to create the stack data structure-----
// DO NOT uncomment the below function. It is for your reference purpose only.
// We will use this function to create the stack.
/*struct myStack *createMyStack() {
    struct myStack *ms = (struct myStack*) malloc(sizeof(struct myStack));
    ms->count = 0;
    ms->head = NULL;
    ms->mid = NULL;
    return ms;
}; */
 
//-----Function to push an element to the stack-----
void push(struct myStack *ms, int new_data) {
    /* allocate DLLNode and put in data */
    struct DLLNode* new_DLLNode = (struct DLLNode*) malloc(sizeof(struct DLLNode));
    new_DLLNode->data  = new_data;
    
    //-----Appropriately update new_DLLNode and ms to get the functionality-----
    if(ms->count!=0)
        {
            new_DLLNode->prev = ms->head;
            (ms->head)->next=new_DLLNode;
        }
    else 
        new_DLLNode->prev=NULL;

    new_DLLNode->next = NULL;
    ms->head=new_DLLNode;
    (ms->count)++;
    if(ms->count!=1)
        {
            if(((ms->count)+1)%2==0)
                ms->mid=(ms->mid)->next;
        }
    else
        ms->mid=new_DLLNode;

    
    //-----code ends here-----
}
 
//-----Function to pop an element from stack. Return the popped element-----
//-----Will not be called for empty stack-----
int pop(struct myStack *ms) {
    struct DLLNode *head = ms->head;
    int item = head->data;
    
    //-----Appropriately update ms to get the required functionality-----
    ms->head=head->prev;
    //(ms->head)->next=NULL;
    (ms->count)--;
    if(ms->mid->prev!=NULL)
        {
            if((ms->count)%2==0)
                ms->mid=(ms->mid)->prev;
        }

    
    //-----code ends here-----
 
    free(head);
 
    return item;
}
 
//-----Function for finding middle of the stack-----
//-----Will not be called for empty stack-----
int findMiddle(struct myStack *ms) {
    //-----code begins here-----
    return (ms->mid)->data;
    
    //-----code ends here-----
}

//-----Function for deleting middle of the stack-----
//-----Return the value deleted, will not be called for empty stack-----
int deleteMiddle(struct myStack *ms) {
    //-----code begins here-----
    int val=(ms->mid)->data;
    (ms->count)--;
    if(ms->count!=0)
        {   
            if(ms->count%2==0)
                ms->mid=(ms->mid)->prev;
            else
                ms->mid=(ms->mid)->next;
        }
    else
        {
            ms->mid=NULL;
            ms->head=NULL;
        }

    return val;
    //-----code ends here-----
}
