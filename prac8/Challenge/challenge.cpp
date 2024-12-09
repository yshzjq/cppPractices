#include <iostream>
#include <string>

using namespace std;

class Product
{
	int id;
	string des;
	string producter;
	int price;

	string type;
public:
	Product() {};
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
		cout << "---- 상품ID : " << id << '\n';
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
	void Bookshow()
	{
		cout << "책제목 : " << title << '\n';
		cout << "저자 : " << writer << '\n';
		cout << "ISBN : " << ISBN << '\n';
	}

	int getISBN()
	{
		return ISBN;
	}

	string getWriter()
	{
		return writer;
	}

	string getTitle()
	{
		return title;
	}
};

class CompactDisc : public Product
{
	string title;
	string singer_name;
public:
	CompactDisc() {};
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

	void CBookshow()
	{
		cout << "책제목 : " << getTitle() << '\n';
		cout << "저자 : " << getWriter() << '\n';
		cout << "언어 : " << language << '\n';
		cout << "ISBN : " << getISBN() << '\n';
	}
};

int main()
{
	int idx = 0;

	Product* product[100] = {};


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
			cin.ignore();
			string des;
			string producter;
			int price;
			int ISBN;
			string writer;
			string title;
			string singer_name;
			string language;

			
			


			cout << "상품설명>>";
			getline(cin, des, '\n');
			cout << "생산자>>";
			getline(cin, producter, '\n');

			cout << "가격>>";
			cin >> price;
			cin.ignore();
			

			if (n == 2)
			{
				cout << "앨범제목>>";
				getline(cin, title, '\n');
				cout << "가수>>";
				getline(cin, singer_name, '\n');

				CompactDisc* cd = new CompactDisc(idx, des, producter, price, title, singer_name);
				product[idx] = (Product*)cd;
			}
			else
			{
				cout << "책제목>>";
				getline(cin, title, '\n');
				cout << "저자>>";
				getline(cin, writer, '\n');
				if (n == 3)
				{
					cout << "언어>>";
					getline(cin, language, '\n');
				}
				cout << "ISBN>>";
				cin >> ISBN;

				if (n == 3)
				{
					ConversationBook* cbook = new ConversationBook(idx, des, producter, price,ISBN, title, writer, language);
					product[idx] = cbook;
				}
				else if (n == 1)
				{
					Book* book = new Book(idx, des, producter, price, ISBN, title, writer);
					product[idx] = book;
				}
			}
			idx++;
		}
		else if (n == 2) // 모든 상품 조회
		{
			for (int i = 0; i < idx; i++)
			{
				product[i]->ProductShow();

				if (product[i]->getType() == "CD")
				{
					CompactDisc* cd = (CompactDisc*)product[i];
					cd->CDshow();
				}
				else if (product[i]->getType() == "Book")
				{
					Book* book = (Book*)product[i];
					book->Bookshow();
				}
				else if (product[i]->getType() == "CBook")
				{
					ConversationBook* book = (ConversationBook*)product[i];
					book->CBookshow();
				}

			}
		}
		else // 끝내기
		{
			break;
		}

		
	}






	return 0;
}