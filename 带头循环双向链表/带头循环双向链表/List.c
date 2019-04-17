#include"List.h"
void ListInit(List* plist)
{
	assert(plist);
	assert(plist->_head);
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void ListDestory(List* plist)
{
	assert(plist);
	assert(plist->_head);
	ListNode* cur;
	ListNode* next;
	cur = plist->_head->_next;
	while (cur!=plist->_head)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* ret;
	ret = (ListNode*)malloc(sizeof(ListNode));
	ret->_data = x;
	ret->_next = NULL;
	ret->_prev = NULL;
	return ret;
}

void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	assert(plist->_head);
	ListNode* cur;
	cur = BuyListNode(x);
	ListNode* prev=plist->_head->_prev;
	cur->_next = plist->_head;
	prev->_next = cur;
	plist->_head->_prev = cur;
	cur->_prev = prev;

}
void ListPopBack(List* plist)
{
	assert(plist);
	assert(plist->_head);
	ListNode* cur = plist->_head->_prev;
	ListNode* prev = cur->_prev;
	if (cur == plist->_head)
		return;
	prev->_next = plist->_head;
	plist->_head->_prev = prev;
	free(cur);

}
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	assert(plist->_head);
	ListNode* cur;
	cur = BuyListNode(x);
	ListNode* next = plist->_head->_next;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
	cur->_next = next;
	next->_prev = cur;

}
void ListPopFront(List* plist)
{
	assert(plist);
	assert(plist->_head);
	ListNode* cur = plist->_head->_next;
	ListNode* next = plist->_head->_next->_next;
	if (cur == plist->_head)
		return;
	plist->_head->_next = next;
	next->_prev = plist->_head;
	free(cur);

}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	assert(plist->_head);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if (cur->_data==x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;

}

// 在pos的前面进行插入 
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* cur=BuyListNode(x);
	prev->_next = cur;
	cur->_prev = prev;
	cur->_next = pos;
	pos->_prev = cur;

}
// 删除pos位置的节点 
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;

}

void ListRemove(List* plist, LTDataType x)
{
	assert(plist);
	ListErase(ListFind(plist, x));

}

void ListPrint(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;

	while (cur!=plist->_head)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
}
void TestList()
{
	List set;
	ListInit(&set);

	ListPushBack(&set, 3);
	ListPushBack(&set, 4);
	ListPushBack(&set, 5);
	ListPushFront(&set, 2);
	ListPushFront(&set, 1);
	ListPushFront(&set, 0);
	ListPopFront(&set);
	ListInsert(ListFind(&set, 3), 3);
	ListErase(ListFind(&set, 4));
	ListRemove(&set, 5);

	ListPrint(&set);
	ListDestory(&set);
	set._head = NULL;
}