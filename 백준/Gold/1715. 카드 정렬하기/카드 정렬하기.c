#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TRUE	1
#define FALSE	0
#define HEAP_LEN    100001

typedef int HData;

typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);
void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);
int GetParentIDX(int idx);
int GetLChildIDX(int idx);
int GetRChildIDX(int idx);
int GetHiPriChildIDX(Heap* ph, int idx);
int DataPriorityComp(int ch1, int ch2);


int main(void)
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	int n;
	int input_data;

	int result_data = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &input_data);
		HInsert(&heap, input_data);
	}
	
	/*printf("%d \n", HDelete(&heap));*/

	while (1) 
	{
		int temp;
		int check = HDelete(&heap);
		if (HIsEmpty(&heap)) {
			break;
		}
		else {
			HInsert(&heap, check);
		}
		temp = HDelete(&heap) + HDelete(&heap);
		result_data += temp;
		HInsert(&heap, temp);
	}

	printf("%d", result_data);

	return 0;
}

/************ 함수 정의 ************/
void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;

	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
		//	if(ph->heapArr[GetLChildIDX(idx)].pr 
		//				> ph->heapArr[GetRChildIDX(idx)].pr)
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)],
			ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData data)
{
	int idx = ph->numOfData + 1;

	while (idx != 1)
	{
		//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph)
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		//	if(lastElem.pr <= ph->heapArr[childIdx].pr)
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}

int DataPriorityComp(int ch1, int ch2)
{
	return ch2 - ch1;
}
