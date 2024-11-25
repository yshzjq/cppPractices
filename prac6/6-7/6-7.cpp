#include <iostream>


using namespace std;

class Random {
public:
	// 항상 다른 랜덤수를 발생시키기 위한 seed를 설정하는 함수
	static void seed() { srand((unsigned)time(0)); } // 씨드 설정
	static int nextInt(int min = 0, int max = 32767); // min과 max 사이의 랜덤 장수: 리턴 
	static char nextAlphabet(); // 랜덤 알파벳 문자 리턴
	static double nextDouble(); // 0보다 크거나 같고 1보다 적은 랜덤 실수 리턴
};

int Random::nextInt(int min, int max)
{
	return (rand()%(max-min + 1)) + min;
}

char Random::nextAlphabet()
{
	return (rand() % ('Z' - 'A' + 1)) + 'A';
}

double Random::nextDouble()
{
	return static_cast<double>(rand()) / RAND_MAX;
}

int main()
{
	Random random;

	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다\n";

	for (int i = 0; i < 10; i++)
	{
		cout << random.nextInt(1,100) << ' ';
	}

	cout << "\n알파벳을 랜덤하게 10개를 출력합니다\n";

	for (int i = 0; i < 10; i++)
	{
		cout << random.nextAlphabet() << ' ';
	}

	cout << "\n랜덤한 실수를 10개를 출력합니다\n";

	for (int i = 0; i < 10; i++)
	{
		cout << random.nextDouble() << ' ';
	}

	return 0;
}

