#include <iostream>
#include <string>
using namespace std;
// C-string 사용

//class Book 
//{
//	char* title; // 제목 문자열
//	int price; // 가격
//public:
//	Book(const char* title, int price);
//	Book(Book& book);
//	~Book() { delete title; }
//	void set(const char* title, int price);
//	void show() { cout << title << ' ' << price << "원" << endl; }
//};
//
//Book::Book(const char* title, int price)
//{
//	this->title = new char[strlen(title)+1];
//	strcpy(this->title, title);
//	this->price = price;
//}
//
//Book::Book(Book& book)
//{
//	this->title = new char[strlen(book.title)+1];
//	strcpy(this->title, book.title);
//	this->price = book.price;
//}
//
//void Book::set(const char* title, int price)
//{
//	delete[] this->title;
//	this->title = new char[strlen(title) + 1];
//	strcpy(this->title, title);
//	this->price = price;
//}
//
//int main() {
//	Book cpp("명품C++", 10000);
//	Book java = cpp; // 복사생성자호출됨 
//	java.set("명품자바", 12000);
//	cpp.show();
//	java.show();
//
//	return 0;
//}

class Book
{
	string title; // 제목 문자열
	int price; // 가격
public:
	Book(const string title, int price);
	Book(Book& book);
	void set(const string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const string title, int price)
{
	this->title = title;
	this->price = price;
}

Book::Book(Book& book)
{

	this->title = book.title;
	this->price = book.price;
}

void Book::set(const string title, int price)
{
	this->title = title;
	this->price = price;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp; // 복사생성자호출됨 
	java.set("명품자바", 12000);
	cpp.show();
	java.show();

	return 0;
}


