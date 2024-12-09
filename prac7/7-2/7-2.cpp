#include <iostream>	
#include <string>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	friend bool operator==(Book book, int price);
	friend bool operator==(Book book, string title);
	friend bool operator==(Book book1, Book book2);

	/*
	bool operator==(int price)
	{
		if (this->price == price) return true;
		return false;
	}

	bool operator==(string title)
	{
		if (this->title == title) return true;
		return false;
	}

	bool operator==(Book book)
	{
		if (this->title == book.title && this->price == book.price && this->pages == book.pages) return true;
		return false;
	}
	*/

};

bool operator==(Book book, int price)
{
	if (book.price == price) return true;
	return false;
} 

bool operator==(Book book, string title)
{
	if (book.title == title) return true;
	return false;
}

bool operator==(Book book1, Book book2)
{
	if (book1.title == book2.title && book1.pages == book2.pages && book1.price == book1.price) return true;
	return false;
}




int main()
{
	Book a("명품 C++", 30000, 500), b("명품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원," << endl; // price 비교
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl; // 책 title 비교
	if (a == b) cout << "두 책이 같은 책입니다." << endl; // title, price, pages 모두 비교
}

