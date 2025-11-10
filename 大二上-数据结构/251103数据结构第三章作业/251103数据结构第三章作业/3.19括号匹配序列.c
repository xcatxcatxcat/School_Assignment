#include "stdio.h"
#pragma warning(disable:4996)
#define MAX_SIZE 100

// µœ÷’ª
typedef struct
{
	char sq[MAX_SIZE];
	int size;
} self_stack;

//≥ı ºªØ’ª
void StackInit(self_stack* s)
{
	s->size = 0;
	return;
}

//≈–∂œ’ªø’
int IsEmpty(self_stack* s)
{
	if (s->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//≈–∂œ’ª¬˙
int IsFull(self_stack* s)
{
	if (s->size == MAX_SIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Ω¯’ª
int Push(self_stack* s, char e)
{
	if (!IsFull(&s))
	{
		s->sq[s->size] = e;
		s->size++;
		return 1;
	}
	else
	{
		return 0;
	}
}
//≥ˆ’ª
int Pop(self_stack* s, char* e)
{
	if (!IsEmpty(&s))
	{
		*e = s->sq[s->size - 1];
		s->size--;
		return 1;
	}
	else
	{
		return 0;
	}
}

//¿®∫≈∆•≈‰À„∑®
int BracketCheck(char *str)
{
	self_stack s;
	StackInit(&s);
	size_t i = 0;
	while (str[i])
	{
		if (str[i] == '[' || str[i] == '{' || str[i] == '(')
		{
			if (!Push(&s, str[i])) return 0;
		}
		else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
		{
			char e;
			if (!Pop(&s, &e)) return 0;
			if ((e=='('&&str[i]!=')')||(e=='['&&str[i]!=']')||(e=='{'&&str[i]!='}')) return 0;
		}
		++i;
	}
	if (!IsEmpty(&s))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	printf("%d\n", BracketCheck("[(a+b)/c]*d"));
	printf("%d\n", BracketCheck("((())]"));
	printf("%d\n", BracketCheck("{{{]"));
	return 0;
}