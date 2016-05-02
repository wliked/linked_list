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
	
	if(head==NULL)
	{
		return head;
	}
	
	slist_node = head->next;
	slist_node_prev = head;
	
	while(slist_node)
	{
	    slist_node_next =slist_node->next;
		slist_node->next=slist_node_prev;
		slist_node_prev=slist_node;
		slit_node=slist_node_next;
	}	
	
	head->next = NULL;
	return  slist_node_prev;
}


DListNode* reverse_double_linked_list(DListNode * head)
{
   DListNode* node, nodeprevious, nodenext;

   if(NULL==head)
   	 return head;

   node=head->next;
   nodeprevious = head;

   while(node)
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