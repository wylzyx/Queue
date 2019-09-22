typedef int DataType;

typedef struct QueueNode {
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue {
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueueDestory(Queue* q);

void QueuePush(Queue* q, DataType x);
void QueuePop(Queue* q);

DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);

int QueueEmpty(Queue* q);
void QueuePrint(Queue* q);
