#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

//车
typedef struct
{
	char id[10];
}CAR;

//存车的栈，数组实现
typedef struct
{
	CAR* data;
	size_t top;
	size_t capacity;
}Stack;

//存车的循环队列，数组实现
typedef struct
{
	CAR* data;
	size_t front;
	size_t end;
	size_t capacity;
}Queue;

//特殊车，便于返回
CAR SpecialCar = { NULL };

//栈的操作
//初始化
void StackInit(Stack* st, int cap)
{
	st->data = (CAR*)malloc(sizeof(CAR) * cap);
	st->top = 0;
	st->capacity = cap;
	return;
}
//判断栈满
int StackIsFull(Stack* st)
{
	if (st->top == st->capacity)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//判断栈空
int StackIsEmpty(Stack* st)
{
	if (st->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//入栈
void Push_Stack(Stack* st, CAR car)
{
	if (StackIsFull(st))
	{
		printf("入栈失败，栈满\n");
		return;
	}
	st->data[st->top] = car;
	++st->top;
	return;
}
//出栈
CAR Pop_Stack(Stack* st)
{
	if (StackIsEmpty(st))
	{
		printf("出栈失败，栈为空\n");
		return SpecialCar;
	}
	else
	{
		--st->top;
		return st->data[st->top];
	}
}

//队列的操作
//初始化
void QueueInit(Queue* q, int cap)
{
	q->data = (CAR*)malloc(sizeof(CAR) * (cap+1));
	q->front = 0;
	q->end = 0;
	q->capacity = cap;
	return;
}
//判断队列满
int QueueIsFull(Queue* q)
{
	if ((q->end + 1) % (q->capacity+1) == q->front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//判断队列空
int QueueIsEmpty(Queue* q)
{
	if (q->front == q->end)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//进入队列
void Push_Queue(Queue* q, CAR car)
{
	if (QueueIsFull(q))
	{
		printf("加入队列失败，队列满\n");
		return;
	}
	q->data[q->end] = car;
	q->end = (q->end + 1) % (q->capacity + 1);
	return;
}
//离开队列
CAR Pop_Queue(Queue* q)
{
	if (QueueIsEmpty(q))
	{
		printf("离开队列失败，队列为空\n");
		return SpecialCar;
	}
	else
	{
		int idx = q->front;
		q->front = (q->front + 1) % (q->capacity + 1);
		return q->data[idx];
	}
}

//功能
//进入停车场
void EnterPark(Stack* st, Queue* q, CAR car)
{
	//如果停车场没满
	if (!StackIsFull(st))
	{
		Push_Stack(st, car);
		printf("%s进入停车场\n", car.id);
	}
	else
	{
		//如果等待队列没满
		if (!QueueIsFull(q))
		{
			Push_Queue(q, car);
			printf("%s进入等待队列\n", car.id);
		}
		else
		{
			printf("%s进入失败，容量已满\n",car.id);
		}
	}
	return;
}
//离开停车场
void LeavePark(Stack* st, Queue* q,const char* str)
{
	for (size_t i = 0; i < st->top; ++i)
	{
		//如果找到该车牌号的车
		if (strcmp(st->data[i].id, str) == 0)
		{
			//后边的出来，存到临时栈中
			Stack tmp;
			StackInit(&tmp, st->capacity);
			for (; st->top >i+1;)
			{
				Push_Stack(&tmp, Pop_Stack(st));
			}

			//该车牌号的车离开
			printf("%s离开停车场\n",Pop_Stack(st).id);

			//临时栈中车进
			while (tmp.top)
			{
				Push_Stack(st, Pop_Stack(&tmp));
			}

			//等待队列里进一辆，如果有的话
			if (!QueueIsEmpty(q))
			{
				Push_Stack(st, Pop_Queue(q));
			}

			return;
		}
	}
	//没找到
	printf("停车场中没有%s\n", str);
	return;
}
//按车牌号查找车辆位置
void Find(Stack* st, Queue* q, const char* str)
{
	//找停车场
	if (!StackIsEmpty(st))
	{
		for (size_t i = 0; i < st->top; ++i)
		{
			if (strcmp(st->data[i].id, str) == 0)
			{
				printf("%s在停车场第%d位\n", str, i + 1);
				return;
			}
		}
	}

	//找等待队列
	if (!QueueIsEmpty(q))
	{
		for (size_t i = q->front; i != q->end; i = (i + 1) % (q->capacity + 1))
		{
			if (strcmp(q->data[i].id, str) == 0)
			{
				printf("%s在等待队列第%d位\n", str, (i + 1 + q->capacity + 1 - q->front) % (q->capacity + 1));
				return;
			}
		}
	}

	//没找到
	printf("未找到%99s\n", str);
	return;
}
//显示出全部车辆
void Show(Stack* st, Queue* q)
{
	if (StackIsEmpty(st) && QueueIsEmpty(q))
	{
		printf("没有车辆\n");
		return;
	}

	//如果停车场不空
	if (!StackIsEmpty(st))
	{
		printf("停车场：\n");
		for (size_t i = 0; i < st->top; ++i)
		{
			printf("	%s\n", st->data[i].id);
		}
	}
	//如果等待队列不空
	if (!QueueIsEmpty(q))
	{
		printf("等待队列：\n");
		for (size_t i = q->front; i != q->end; i = (i + 1) % (q->capacity + 1))
		{
			printf("	%s\n", q->data[i].id);
		}
	}
	return;
}

int main()
{
	//初始化停车场和等待队列
	int n, m;
	printf("输入n（停车场容量） m（排队容量）：\n", &n, &m);
	scanf("%d %d", &n, &m);
	Stack parking;
	StackInit(&parking, n);
	Queue line;
	QueueInit(&line, m);

	//操作
	int flag = 1;
	while (flag)
	{
		int x;
		printf("请输入操作数（1停车 2离开车 3查找车 4显示 5退出）：");
		scanf("%d", &x);
		switch (x)
		{
			case 1:
			{
				CAR tmp;
				printf("请输入车牌号：");
				scanf("%99s", tmp.id);
				EnterPark(&parking, &line, tmp);
				break;
			}
			case 2:
			{
				char id[10];
				printf("请输入车牌号：");
				scanf("%99s", id);
				LeavePark(&parking, &line, id);
				break;
			}
			case 3:
			{
				char id[10];
				printf("请输入车牌号：\n");
				scanf("%99s", id);
				Find(&parking, &line, id);
				break;
			}
			case 4:
			{
				Show(&parking, &line);
				break;
			}
			case 5:
			{
				flag = 0;
				break;
			}
			default:
			{
				printf("操作数错误，请重新输入\n");
				break;
			}
		}
	}
	return 0;
}