//// CycleListtest.cpp: 定义控制台应用程序的入口点。
////
//
//#include "stdafx.h"
//#include<stdlib.h>
//
//typedef struct CLinkList
//{
//	int data;
//	struct CLinkList *next;
//}node;
//
////初始化循环链表
//void ds_init(node **pNode)
//{
//	int item;
//	node *temp;
//	node *target;
//
//	printf("输入结点的值，输入0结束并完成链表的输入：\n");
//
//	while (1)
//	{
//		scanf_s("%d", &item);
//		fflush(stdin);//清空输入缓冲区
//
//		if (item == 0)
//			return;
//
//        //判断是否只有一个结点
//		if ((*pNode) == NULL)
//		{
//			*pNode = (node*)malloc(sizeof(struct CLinkList));
//			if (!(*pNode))
//				exit(0);
//			(*pNode)->data = item;
//			(*pNode)->next = *pNode;
//		}
//		else
//		{
//			//寻找next指向第一个结点的结点（即尾结点）
//			for (target = (*pNode); target->next != (*pNode); target = target->next)
//				;
//
//			//生成新结点
//			temp = (node*)malloc(sizeof(struct CLinkList));
//
//
//			if (!temp)
//				exit(0);
//			temp->data = item;
//			temp->next = *pNode;
//			target->next = temp;
//		}
//
//	}
//}
//
////插入结点（**pNode：为链表第一个结点。i：为插入位置）
//void ds_insert(node **pNode, int i)
//{
//	node *temp;
//	node *target;
//	node *p;
//	int item;
//	int j = 1;
//	
//	printf("请输入要插入结点的值：\n");
//	scanf_s("%d", &item);
//
//	if (i == 1)
//	{
//		//新插入的点为第一个结点
//		temp = (node*)malloc(sizeof(struct CLinkList));
//
//		if (!temp)
//			exit(0);
//
//		temp->data = item;
//
//		//寻找最后一个结点（使target指向头结点）
//		for (target = (*pNode); target->next != (*pNode); target = target->next);
//
//		temp->next = (*pNode);
//		target->next = temp;
//		*pNode = temp;
//
//	}
//	else
//	{
//		target = *pNode;
//
//		//遍历到要插入的位置
//		for (; j < (i - 1); ++j)
//		{
//			target = target->next;
//		}
//
//		temp = (node*)malloc(sizeof(struct CLinkList));
//		if (!temp)
//			exit(0);
//
//		temp->data = item;
//
//		//将temp插入到链表中
//		p = target->next;
//		target->next = temp;
//		temp->next = p;
//	}
//}
//
////删除结点
//void ds_delete(node **pNode, int i)
//{
//	node *target;
//	node *temp;
//	int j = 1;
//	if (i == 1)
//	{
//		//删除的是第一个结点
//		//找到最后一个结点
//		for (target = *pNode; target->next != *pNode; target = target->next);
//
//		temp = *pNode;
//		*pNode = (*pNode)->next;
//		target->next = *pNode;
//		free(temp);
//	}
//	else
//	{
//		target = *pNode;
//
//		for (; j < i - 1; ++j)
//		{
//			target = target->next;
//		}
//
//		temp = target->next;
//		target->next = temp->next;
//		free(temp);
//	}
//}
//
////返回所输入数据的结点所在位置
//int ds_search(node *pNode, int elem)
//{
//	node *target;
//	int i = 1;
//	for (target=pNode;target->data!=elem&&target->next!=pNode;++i)
//	{
//		target = target->next;
//	}
//
//	if (target->next == pNode)
//		return 0;
//	else
//		return i;
//}
//
////遍历
//void ds_traverse(node* pNode)
//{
//	node *temp;
//	temp = pNode;
//	printf("链表中的元素为：\n");
//	do
//	{
//		printf("%d   ", temp->data);
//		temp = temp->next;
//	}while(temp != pNode);
//	printf("\n");
//}
//
//int main()
//{
//	node *pHead = NULL;
//	char opp=0;
//	int find=0;
//	printf("1、初始化链表\n");
//	printf("2、插入结点\n");
//	printf("3、删除结点\n");
//	printf("4、返回结点所在位置\n");
//	printf("5、遍历链表\n");
//	printf("0、退出\n");
//	while (opp != '0')
//	{
//		printf("\n请选择你的操作：\n");
//		scanf_s("%c", &opp);
//		switch (opp)
//		{
//		case '1':
//			ds_init(&pHead);
//			printf("\n");
//			ds_traverse(pHead);
//			printf("\n");
//			break;
//		case '2':
//			printf("请输入需要插入结点的位置：\n");
//			scanf_s("%d", &find);
//			printf("\n");
//			ds_insert(&pHead, find);
//			printf("在%d位置插入结点后：\n",find);
//			ds_traverse(pHead);
//			printf("\n");
//			break;
//		case '3':
//			printf("请输入需要删除的结点位置：\n");
//			scanf_s("%d", &find);
//			printf("\n");
//			ds_delete(&pHead, find);
//			printf("删除第%d个结点后：\n",find);
//			ds_traverse(pHead);
//			printf("\n");
//			break;
//		case '4':
//			printf("请输入你所要查找位置的结点：\n");
//			scanf_s("%d", &find);
//			printf("\n");
//			printf("该结点的位置为：%d\n",ds_search(pHead, find));
//			break;
//		case '5':
//			ds_traverse(pHead);
//			break;
//		case '6':
//			exit(0);
//		default:
//			break;
//		}
//	}
//	getchar();
//    return 0;
//}
//



//约瑟夫环

#include"stdafx.h"
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

//初始化链表
node *create(int n)
{
	node *p = NULL, *head;
	head = (node*)malloc(sizeof(node));
	p = head;
	node *s;
	int i = 1;

	if (0 != n)
	{
		while (i <= n)
		{
			s = (node*)malloc(sizeof(node));
			s->data = i++;
			p->next = s;
			p = s;
		}
		p->next = head->next;

	}
	free(head);

	return p->next;
}

//

int main()
{
	int n = 41;
	int m = 3;
	int i;
	node *p = create(n);
	node *temp;
	node *a;
	node *b;

	m %= n;

	while (p != p->next)
	{
		for (i = 1; i < m - 1; i++)
		{
			b = p;
			p = p->next;
			a = p;

		}
		printf("%d->\n", p->next->data);
		printf("%d\n", p);
		temp = p->next;
		p->next = temp->next;

		free(temp);
		

		p = p->next;
	}
	printf("%d\n", p->data);



	getchar();
	return 0;
}