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