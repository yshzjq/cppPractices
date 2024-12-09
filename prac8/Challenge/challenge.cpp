#include <iostream>

using namespace std;

class Product
{
	int id;
	string des;
	string producter;
	int price;

	string type;
public:
	Product(int id, string des, string producter, int price, string type)
	{
		this->id = id;
		this->des = des;
		this->producter = producter;
		this->price = price;

		this->type = type;
	}

	void ProductShow()
	{
		cout << "---- 상품ID : " + id << '\n';
		cout << "상품설명 : " << des << '\n';
		cout << "생산자 : " << producter << '\n';
		cout << "가격 : " << price << '\n';
	}

	string getType()
	{
		return type;
	}
};

class Book : public Product
{
	int ISBN;
	string writer;
	string title;
public:
	Book(int id, string des, string producter, int price, int ISBN, string writer, string title, string type = "Book") : Product(id, des, producter, price, type)
	{
		this->ISBN = ISBN;
		this->writer = writer;
		this->title = title;
	}

};

class CompactDisc : public Product
{
	string title;
	string singer_name;
public:
	CompactDisc(int id, string des, string producter, int price, string title, string singer_name) : Product(id,des,producter,price,"CD")
	{
		this->title = title;
		this->singer_name = singer_name;
	};

	void CDshow()
	{
		cout << "앨범제목 : " << title << '\n';
		cout << "가수 : " << singer_name << '\n';
	}
};

class ConversationBook : public Book
{
	string language;
public:
	ConversationBook(int id, string des, string producter, int price, int ISBN, string writer, string title,string language) : Book(id, des, producter, price,ISBN,writer,title, "CBook")
	{
		this->language = language;
	}
};

int main()
{
	int idx = 0;

	Product* product[100];

	cout << "***** 상품 관리 프로그램을 작동합니다. *****\n";

	while (true)
	{
		int n;
		cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
		cin >> n;

		if (n == 1)
		{
			cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
			cin >> n;
			
			string des;
			string producter;
			int price;
			int ISBN;
			string writer;
			string title;
			string singer_name;
			string language;

			cout << "상품설명>>";
			cin >> des;
			cout << "생산자>>";
			cin >> producter;
			cout << "가격>>";
			cin >> price;

			if (n == 2)
			{
				cout << "앨범제목>>";
				cin >> title;
				cout << "가수>>";
				cin >> singer_name;

				CompactDisc cd = CompactDisc(idx, des, producter, price, title, singer_name);

				product[idx] = (Product*)&cd;
			}
			else
			{
				cout << "책제목>>";
				cin >> title;
				cout << "저자>>";
				cin >> writer;
				if (n == 3)
				{
					cout << "언어>>";
					cin >> language;
				}
				cout << "ISBN>>";
				cin >> ISBN;

				if (n == 3)
				{
					ConversationBook cbook = ConversationBook(idx, des, producter, price,ISBN, title, writer, language);
					product[idx] = (Product*)&cbook;
				}
				else if (n == 2)
				{
					Book book = Book(idx, des, producter, price, ISBN, title, writer);
					product[idx] = (Product*)&book;
				}
			}
		}
		else if (n == 2) // 모든 상품 조회
		{
			for (int i = 0; i < idx; i++)
			{
				product[idx]->ProductShow();

				if (product[idx]->getType() == "CD")
				{
					CompactDisc* cd = (CompactDisc*)product[idx];
					cd->CDshow();
				}
				else if (product[idx]->getType() == "Book")
				{

				}
				else if (product[idx]->getType() == "CBook")
				{

				}

			}
		}
		else // 끝내기
		{
			break;
		}

		idx++;
	}






	return 0;
}