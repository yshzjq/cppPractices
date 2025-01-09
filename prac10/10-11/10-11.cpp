#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
	int year;
	string bookName;
	string writer;
public:
	Book(int year, string bookName, string writer)
	{
		this->year = year;
		this->bookName = bookName;
		this->writer = writer;
	}

	int getYear() { return year; }
	string getBookName(){ return bookName; }
	string getWriter() { return writer; }	
};

int main()
{
	vector<Book> books;

	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다.\n";
	
	int year;
	string bookName;
	string writer;

	while (true)
	{
		cout << "년도>>";
		cin >> year;

		if (year == -1) break;

		cin.ignore();
		cout << "책이름>>";
		getline( cin, bookName);

		cout << "저자>>";
		getline(cin, writer);

		books.push_back(Book(year, bookName, writer));
	}

	cout << "총 입고된 책은 " << books.size() << "권입니다.\n";

	cout << "검색하고자 하는 저자 이름을 입력세요>>";

	string find;

	cin >> find;

	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getWriter() == find)
		{
			cout << books[i].getYear() << "년도, " << books[i].getBookName() << books[i].getWriter() << '\n';
			break;
		}
	}

	cout << "검색하고자 하는 년도를 입력세요>>";

	int year_find;

	cin >> year_find;

	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getYear() == year_find)
		{
			cout << books[i].getYear() << "년도, " << books[i].getBookName() << books[i].getWriter() << '\n';
			break;
		}
	}

	return 0;
}