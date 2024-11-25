#include <iostream>

using namespace std;

class ArrayUtility2
{
public:
	// S1 과 S2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	static int* concat(int s1[], int s2[], int sumsize);
	// si에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴. 리턴하는 배열의 크기는 
	// retSize에 전달. retSize가 0인 경우 NULL 리턴
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size)
{
	int* arr = new int[size];

	for (int i = 0; i < size/2; i++)
	{
		arr[i] = s1[i];
	}

	for (int i = size / 2; i < size; i++)
	{
		arr[i] = s2[i - size/2];
	}

	return arr;

}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize)
{
	int n[100];

	for (int i = 0; i < 5; i++)
	{
		int j;
		for (j = 0; j < 5; j++)
		{
			if (s1[i] == s2[j])
			{
				break;
			}
		}
		if (j == size / 2)
		{
			n[retSize] = s1[i];
			retSize++;
		}
	}

	int* arr = new int[retSize];

	for (int i = 0; i < retSize; i++)
	{
		arr[i] = n[i];
	}

	return arr;
}


int main()
{
	ArrayUtility2 arrayutility;

	int arr1[5];
	int arr2[5];

	int* result1;
	int* result2;

	cout << "정수를 5 개 입력하라. 배열 x에 삽입한다>>";

	for (int i = 0; i < 5; i++)
	{
		cin >> arr1[i];
	}

	cout << "정수를 5 개 입력하라. 배열 y에 삽입한다>>";

	for (int i = 0; i < 5; i++)
	{
		cin >> arr2[i];
	}
	
	cout << "합친 정수 배열을 출력한다.\n";

	result1 = arrayutility.concat(arr1, arr2,10);

	for (int i = 0; i < 10; i++)
	{
		cout << result1[i] << ' ';
	}

	int count = 0;

	result2 = arrayutility.remove(arr1, arr2, 10, count);

	cout << "\n배열 x[]에서 y[]를 뺀 결과를출력한다. 개수는 " << count << '\n';

	for (int i = 0; i < count; i++)
	{
		cout << result2[i] << ' ';
	}

	delete[] result1;
	delete[] result2;

	return 0;
}

