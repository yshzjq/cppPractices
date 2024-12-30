#include <iostream>
#include <string>

using namespace std;

class Printer
{
protected:
	string model;
	string manufacturer;

	int printedCount;
	int availableCount;

public:

	Printer(string model = "", string manufactuer = "", int printedCount = 0, int availableCount = 0) {};
	virtual void show() {};
	void print(int count)
	{
		if (printedCount - count < 0)
		{
			cout << "잉크가 부족하여 프린트할 수 없습니다.\n";
			return;
		}

		if (availableCount - count < 0)
		{
			cout << "용지가 부족하여 프린트할 수 없습니다.\n";
			return;
		}

		printedCount -= count;
		availableCount -= count;

		cout << "프린트 하였습니다.\n";
	};
};

class InkjetPrinter : public Printer
{
public:
	InkjetPrinter(string model, string manufactuer, int printedCount, int availableCount)
	{
		this->model = model;
		this->manufacturer = manufactuer;

		this->printedCount = printedCount;
		this->availableCount = availableCount;
	}

	void show()
	{
		cout << "잉크젯 : " << model << ", " << manufacturer << ", " << printedCount << ", " << availableCount << '\n';
	}
};

class LaserPrinter : public Printer
{
public:
	LaserPrinter(string model, string manufactuer, int printedCount, int availableCount)
	{
		this->model = model;
		this->manufacturer = manufactuer;

		this->printedCount = printedCount;
		this->availableCount = availableCount;
	}

	void show()
	{
		cout << "레이저 : " << model << ", " << manufacturer << ", " << printedCount << ", " << availableCount << '\n';
	}
};

int main()
{
	Printer printers[3];
	int printerCounts = 2;


	printers[1] = InkjetPrinter("Office jet V40" , "HP", 5, 10);
	printers[2] = LaserPrinter("SCX-6X45" , "삼성전자", 3, 20);

	cout << "현재 작동중인 " << printerCounts << "대의 프린터는 아래와 같다\n";

	while (true)
	{
		printers[1].show();
		printers[2].show();

		int printerNum;
		int pages;
		
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printerNum >> pages;

		printers[printerNum].print(pages);

		char ans;

		cout << "계속 하시겠습니까?";

		cin >> ans;

		if (ans == 'n') break;

	}

}