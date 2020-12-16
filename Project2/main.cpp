#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int N)
{
	int inputVal = 0;
	int tempGap = 0;
	int finalGap = 0;
	int nCount = 0;
	int nDup = 0;
	
	inputVal = N;

	while (inputVal)
	{
		if ((inputVal % 2) == 0)
		{
			if(nCount > 0)
				tempGap++;
			nDup = 0;
		}
		else {
			if (nDup == 1)
				tempGap = 0;

			if (finalGap < tempGap)
			{
				finalGap = tempGap;
			}
			tempGap = 0;
			nDup = 1;
			nCount++;
		}
		inputVal = inputVal / 2;
	}
	if (nCount == 1)
		return 0;

	return finalGap;
}

struct Results {
	int* A;
	int N; // Length of the array
};

struct Results solution2(int A[], int N, int K) {
	struct Results result;
	// write your code in C99 (gcc 6.2.0)

	int* intputVal;
	int inputSize;
	int inputRoIndex;

	int* resultArr;

	inputSize = N;
	inputRoIndex = K;
	

	intputVal = (int*)malloc(sizeof(int) * inputSize);
	resultArr = (int*)malloc(sizeof(int) * inputSize);
	result.A = (int*)malloc(sizeof(int) * inputSize);

	memset(intputVal, 0, sizeof(int) * inputSize);
	memcpy(intputVal, A, sizeof(int) * inputSize);

	if (inputSize == 0)
	{
		memcpy(result.A, intputVal, sizeof(int) * inputSize);
		result.N = inputSize;
		return result;
	}


	if (inputSize < inputRoIndex)
		inputRoIndex = inputRoIndex % inputSize;

	if (inputRoIndex == 0)
	{
		memcpy(result.A, intputVal, sizeof(int) * inputSize);
		result.N = inputSize;
		return result;
	}


	for (int i = 0; i < inputSize; i++)
	{
		//printf("intputVal : %d \n", intputVal[i]);
		if (i < inputRoIndex)
			resultArr[i] = intputVal[inputSize - inputRoIndex + i];
		else
			resultArr[i] = intputVal[i - inputRoIndex];
	}

	memcpy(result.A, resultArr, sizeof(int) * inputSize);
	result.N = inputSize;
	return result;
}


//이중 포문 돌리면 안됨 시간 계산해서 다시
int solution3(int A[], int N)
{
	int* inputArr;
	int inputSize;
	int findFlag = 0;

	inputSize = N;
	inputArr = (int*)malloc(sizeof(int*) * inputSize);

	memset(inputArr, 0, sizeof(int) * inputSize);
	memcpy(inputArr, A, sizeof(int) * inputSize);

	for (int i = 0; i < inputSize; i++)
	{
		if (inputArr[i] == -1)
			continue;


		for (int j = i + 1; j < inputSize; j++)
		{
			if (inputArr[i] == inputArr[j])
			{
				findFlag = 1;
				inputArr[i] = -1;
				inputArr[j] = -1;
			}
		}

		if (findFlag == 0)
		{
			return inputArr[i];
			break;
		}
		else
			findFlag = 0;
	}

}

//이중 포문 돌리면 안됨 시간 계산해서 다시, 아예 없을경우도 생각 해야함
int solution4(int X, int Y, int D)
{
	int startPoint;
	int finishPoint;
	int jumpDistance;
	int jumpNum = 1;

	startPoint = X;
	finishPoint = Y;
	jumpDistance = D;

	while (1)
	{
		if (finishPoint <= startPoint + (jumpDistance * jumpNum))
			break;
		else
			jumpNum++;
	}

	return jumpNum;
}

//시간 단축, 답 틀림
int solution5(int A[], int N)
{
	int* inputArr;
	int inputSize;
	int tempVal = 0;
	int findFlag = 0;
	int i = 0;

	if(N == 0)
		return 0;

	inputSize = N;
	
	inputArr = (int*)malloc(sizeof(int*) * inputSize);
	memset(inputArr, 0, sizeof(int*) * inputSize);
	memcpy(inputArr, A, sizeof(int*) * inputSize);

	for (i = 0; i < inputSize; i++)
	{
		for (int j = i; j < inputSize; j++)
		{
			if (i + 1 == inputArr[j])
			{
				findFlag = 1;
				break;
			}
		}
		if (findFlag == 0)
			break;
	}
	return i;
}

int main(void)
{
	//printf("test : %d \n", solution(20));
	//int A[7] = { 3, 5, 7, 9, 8, 5, 10 };
	/*int *A = NULL;
	Results result;

	result = solution2(A, 0, 1);
	for (int i = 0; i < 7; i++)
	{
		printf("test : %d \n", result.A[i]);
	}*/

	//int A[7] = { 4, 4, 4, 4, 4, 4, 5};

	//int result;

	//result = solution3(A, 7);
	////for (int i = 0; i < 7; i++)
	//{
	//	printf("test : %d \n", result);
	//}

	//int result = solution4(10, 85, 30);
	//printf("test : %d \n", result);


	int A[4] = { 2, 3, 1, 5 };
	int  result = solution5(A, 4);
	printf("test : %d \n", result);
}


