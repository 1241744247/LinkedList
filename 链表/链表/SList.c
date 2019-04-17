#include"SList.h"
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* set;
	while (plist->_head)
	{
		set = plist->_head;
		plist->_head = plist->_head->_next;
		free(set);
	}
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* ret;
	ret = (SListNode*)malloc(sizeof(SListNode));
	ret->_data = x;
	ret->_next = NULL;
	return ret;
}
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* set=BuySListNode(x);
	set->_next = plist->_head;
	plist->_head = set;
}
void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* cur=NULL;
	if (plist->_head)
	{
		cur = plist->_head;
		plist->_head = plist->_head->_next;
		free(cur);
	}
}
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = NULL;
	if (plist->_head)
	{
		cur = plist->_head;
		while (cur)
		{
			if (cur->_data == x)
				return cur;
			cur = cur->_next;
		}
	}

	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* set=BuySListNode(x);
	set->_next = pos->_next;
	pos->_next = set;
}
void SListInsertBefore(SList* plist, SListNode* pos, SLTDataType x)
{
	assert(pos);
	assert(plist);
	if (plist->_head == NULL)
	{
		return;
	}
	SListNode* cur = plist->_head;
	SListNode* next = cur->_next;
	SListNode* set = BuySListNode(x);
	while (cur&&next)
	{
		if (next == pos)
			break;
		cur = cur->_next;
		next = next->_next;
	}
	if (next)
	{
		set->_next = next;
		cur->_next = set;
	}
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->_next)
	{
		SListNode* cur = pos->_next;
		pos->_next = pos->_next->_next;
		free(cur);
	}
}
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur;
	SListNode* prev;
	cur = SListFind(plist, x);
	if (cur == NULL)
		return;
	prev = plist->_head;
	while (1)
	{
		if (prev->_next == cur)
			break;
		prev = prev->_next;
	}
	prev->_next = cur->_next;
	free(cur);
}
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur =plist->_head;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
}
void TestSList()
{
	SList set;
	SList fid;
	SListInit(&set);
	SListPushFront(&set, 5);
	SListPushFront(&set, 4);
	SListPushFront(&set, 3);
	SListPushFront(&set, 2);
	SListPushFront(&set, 1);
	SListPushFront(&set, 0);
	SListPopFront(&set);


	SListInsertBefore(&set, SListFind(&set, 2), 0);

	SListInsertAfter(SListFind(&set,5), 6);
	
	SListEraseAfter(SListFind(&set, 3));
	SListRemove(&set, 3);
	SListPrint(&set);
	SListDestory(&set);
}