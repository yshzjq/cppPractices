#include <iostream>

using namespace std;

class Printer
{
	string model; // 모델명
	string manufacturer; //제조사

	int printedCount; // 인쇄 매수
	int availableCount; // 종이 잔량
public:
	Printer(string model, string manufacturer, int pages)
	{
		this->model = model;
		this->manufacturer = manufacturer;
		printedCount = 0;
		availableCount = pages;
	}

	int getavailableCount()
	{
		return availableCount;
	}

	void print(int pages)
	{
		availableCount -= pages;
	}

	void printerInfo()
	{
		cout << model << " ," << manufacturer << " ,남은 종이 " << availableCount << "장 ,";
	}
};

class Inkjet_Printer : Printer
{
	int availableInk;
public:

	Inkjet_Printer(string model, string manufacturer, int pages, int ink) : Printer(model,manufacturer,pages)
	{
		availableInk = ink;
	}

	void printInkJet(int pages)
	{
		if (availableInk < pages)
		{
			cout << "잉크가 부족하여 프린트할 수 없습니다.\n";
			return;
		}

		if (getavailableCount() < pages)
		{
			cout << "종이가 부족하여 프린트할 수 없습니다.\n";
			return;
		}

		availableInk -= pages;
		print(pages);

		cout << "프린트하였습니다.\n";
	}

	void show()
	{
		printerInfo();
		cout << "남은 잉크 " << availableInk << '\n';
	}
};

class Laser_Printer : Printer
{
	int availableToner;
public:
	Laser_Printer(string model, string manufacturer, int pages, int toner) : Printer(model, manufacturer, pages)
	{
		availableToner = toner;
	}

	void printLaser(int pages)
	{
		if (availableToner < pages)
		{
			cout << "토너가 부족하여 프린트할 수 없습니다.\n";
			return;
		}

		if (getavailableCount() < pages)
		{
			cout << "종이가 부족하여 프린트할 수 없습니다.\n";
			return;
		}

		availableToner -= pages;
		print(pages);

		cout << "프린트하였습니다.\n";
	}

	void show()
	{
		printerInfo();
		cout << "남은 토너 " << availableToner << '\n';
	}
};


int main()
{
	Inkjet_Printer ip("Officejet V40","HP",5,10);
	Laser_Printer lp("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다\n";

	cout << "잉크젯 : ";
	ip.show();
	cout << "레이저 : ";
	lp.show();

	cout << '\n';

	while (true)
	{
		cout << "(1: 잉크젯, 2:레이저)와 매수 입력>>";

		int n, pages;

		cin >> n >> pages;

		if (n == 1)
		{
			ip.printInkJet(pages);
		}
		else if (n == 2)
		{
			lp.printLaser(pages);
		}

		ip.show();
		lp.show();

		char c;

		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> c;

		if (c == 'y')continue;
		else break;

		cout << '\n';
	}

	return 0;
}