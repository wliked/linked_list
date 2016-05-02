//*************************************************************
//*
//* Copyright (c) 2016 : wang liang
//* License : Distributed under the GNU General Public License
//* created on : 4/09/2016,  by wang liang (wliked@outlook.com)
//*
//*************************************************************

//singly linked list node
struct SListNode
{
    int val;
    SListNode* next;
}

//double linked list node
struct DListNode
{
    int val;
    DListNode* next;
    DListNode* prev;
}

//reverse single linked list
SListNode* reverse_single_linked_list(SListNode* head)
{
    SListNode* slist_node=NULL;
    SListNode* slist_node_prev=NULL;
    SListNode* slist_node_next=NULL;

    if (head==NULL)
    {
        return head;
    }

    slist_node = head->next;
    slist_node_prev = head;

    while (slist_node)
    {
        slist_node_next =slist_node->next;
        slist_node->next=slist_node_prev;
        slist_node_prev=slist_node;
        slit_node=slist_node_next;
    }

    head->next = NULL;
    return  slist_node_prev;
}

//delete a node in single linked list
// @para int delete_value: node in single linked list whose value is equal to delete_value will be deleted
SListNode* delete_node_single_linked_list(SListNode* head, int delete_value)
{
    if (NULL==head)
        return head;

    SListNode* node_to_be_deleted =NULL;
    if(head->val ==delete_value)
    {
        node_to_be_deleted =head;
	 head = head-> next;
    }	  

    SListNode* node=head->next;
    SListNode* nodeprevious =head;
    while(NULL != node&& node->val !=delete_value)
       nodeprevious =node;
	node= node->next;

    if(node !=NULL)   // node whose value equal to delete_value exists
    {
        node_to_be_deleted = node;
	 nodeprevious->next=node->next;
    }

    if(NULL !=node_to_be_deleted)  // // node whose value equal to delete_value exists
    {
        delete node_to_be_deleted;
	node_to_be_deleted =NULL;
    }

    return head;
}



DListNode* reverse_double_linked_list(DListNode * head)
{
    DListNode* node, nodeprevious, nodenext;

    if (NULL==head)
        return head;

    node=head->next;
    nodeprevious = head;

    while (node)
    {
        nodenext=node->next;
        node->next=nodeprevious;
        nodeprevious->prev=node;
        nodeprevious=node;
        node=nodenext;
    }

    head->next=NULL;              //now, head become the tail of double linked list, and assume tail's next is NULL
    nodeprevious->prev =NULL;  //assume double linked list head's previous is NULL
    return nodeprevious;

}