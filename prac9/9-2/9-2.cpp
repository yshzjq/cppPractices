#include <iostream>

using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0; // src를 다른 단위로 변환한다 .
	virtual string getSourceString() = 0; // src 단위 명칭
	virtual string getDestString() = 0; // dest 단위 명칭
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다.";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환결과 : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter
{
public:
	WonToDollar(double ratio) : Converter(ratio) {};

	double convert(double src) { return src / ratio; }
	string getSourceString() override { return "원"; }
	string getDestString() override { return "달러"; }
};

class KmToMile : public Converter
{
public:
	KmToMile(double ratio) : Converter(ratio) {};

	double convert(double src) { return src / ratio; }
	string getSourceString() override { return "Km"; }
	string getDestString() override { return "Mile"; }
};


int main()
{
	KmToMile toMile(1.609344);
	toMile.run();

}