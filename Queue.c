#include "Queue.h"
#include<assert.h>
#include<stdio.h>

void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_rear = NULL;
}

void QueueDestory(Queue* q) {
	assert(q);
	QueueNode* cur = q->_front;
	while (cur) {
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

void QueuePush(Queue* q, DataType x) {
	assert(q);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(newNode));
	newNode->_data = x;
	newNode->_next = NULL;

	//判断是否为空
	if (q->_front == NULL) {
		q->_front = q->_rear = newNode;
	}
	else {
		q->_rear->_next = newNode;
		q->_rear = q->_rear->_next;
	}
}

void QueuePop(Queue* q) {
	assert(q);

	if (q->_front) {
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		
		//删除的为最后一个元素
		if (q->_front == NULL) {
			q->_rear = NULL;
		}
	}
}

//获取队头元素
DataType QueueFront(Queue* q) {
	assert(q);
	return q->_front->_data;
}

//获取队尾元素
DataType QueueBack(Queue* q) {
	assert(q);
	return q->_rear->_data;
}

int QueueEmpty(Queue* q) {
	assert(q);
	if (q->_front == NULL) {
		return 1;
	}
	return 0;
}
int QueueSize(Queue* q) {
	int size = 0;
	for (QueueNode* res = q->_front; res != NULL; res = res->_next) {
		size++;
	}
	return size;
}

void QueuePrint(Queue* q) {
	assert(q);
	QueueNode* cur = q->_front;
	while (cur) {
		printf("%d", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}