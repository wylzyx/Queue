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

	//�ж��Ƿ�Ϊ��
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
		
		//ɾ����Ϊ���һ��Ԫ��
		if (q->_front == NULL) {
			q->_rear = NULL;
		}
	}
}

//��ȡ��ͷԪ��
DataType QueueFront(Queue* q) {
	assert(q);
	return q->_front->_data;
}

//��ȡ��βԪ��
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