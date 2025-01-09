#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"

using namespace std;

int main()
{
	vector<Shape*> v;

	cout << "그래픽 에디터입니다.\n";

	while (true)
	{
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		int n;
		cin >> n;

		if (n == 4) // 4. 종료
		{
			break;
		}
		else if (n == 1) // 1. 삽입
		{
			cout << "선:1, 원:2, 사각형:3 >> ";
			cin >> n;
			
			if (n == 1)
			{
				v.push_back(new Line());
			}
			else if (n == 2)
			{
				v.push_back(new Circle());
			}
			else if (n == 3)
			{
				v.push_back(new Rect());
			}
		}
		else if (n == 2) // 2. 삭제
		{
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
			cin >> n;
			
			vector<Shape*>::iterator it;
			it = v.begin() + n;
			v.erase(it);
		}
		else if (n == 3) // 3. 모두 보기
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << i << ": ";
				v[i]->paint();
			}
		}
	}

}