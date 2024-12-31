#include <iostream>
#include <string>

using namespace std;

class Shape
{
protected:
	Shape* nextShape;
public:

	virtual void AddShape(Shape* nextShape) = 0;
	virtual void show() = 0;
	void setNextShape(Shape* nextShape) { this->nextShape = nextShape; }

	Shape* getNextShape() { return nextShape; }
};

class Line : public Shape
{
public:
	Line() { nextShape = nullptr; }

	void AddShape(Shape* nextShape)
	{
		this->nextShape = nextShape;
	}
	void show() { cout << " Line\n"; }
	
};

class Circle : public Shape
{
public:
	Circle() { nextShape = nullptr; }

	void AddShape(Shape* nextShape)
	{
		this->nextShape = nextShape;
	}
	void show() { cout << " Circle\n"; }

};

class Rect : public Shape
{
public:
	Rect() { nextShape = nullptr; }

	void AddShape(Shape* nextShape)
	{
		this->nextShape = nextShape;
	}
	void show() { cout << " Rect\n"; }

};

class GraphicEditor
{
	Shape* pStart;
	Shape* pLast;

public:
	GraphicEditor()
	{
		pStart = nullptr;
		pLast = nullptr;
	}

	~GraphicEditor()
	{
		if (pStart != nullptr)
		{
			delete pStart;
		}
	}

	void ADD(Shape* shape)
	{
		if (pStart == nullptr)
		{
			pStart = shape;
			pLast = shape;
			return;
		}
		else
		{
			pLast->AddShape(shape);
			pLast = shape;
		}
	}

	void DELETE(int n)
	{
		Shape* p = pStart;
		if (p == nullptr) return;

		if (n == 0)
		{
			if (pStart->getNextShape() != nullptr)
			{
				pStart = p->getNextShape();
				delete p;
			}
			else
			{
				delete pStart;
				pStart = nullptr;
				pLast = nullptr;
			}
			return;
		}

		n--;

		while (n--)
		{
			if (p->getNextShape() == nullptr) return;
			p = p->getNextShape();
		}

		Shape* np = p->getNextShape();

		if (np == nullptr) return;

		if (np == pLast)
		{
			delete pLast;
			pLast = p;
			pLast->setNextShape(nullptr);
			
		}
		else
		{

			p->setNextShape(np->getNextShape());
			delete np;
		}


	}

	void allShow()
	{
		Shape* p = pStart;

		int n = 0;

		if (p != nullptr)
		{
			while (true)
			{ 
				cout << n << ": ";
				p->show();
				p = p->getNextShape();
				n++;
				if (p == nullptr) break;
			}
		}
		
	}
};



class UI
{
	
public:
	static int InputCommand() 
	{
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";

		int n;

		cin >> n;

		return n;
	}

	static int InsertNumShape()
	{
		cout << "선:1, 원:2, 사각형:3 >> ";

		int n;
		
		cin >> n;

		return n;
	}

	static int DeleteNumShape()
	{
		cout << "삭제하고자 하는 도형의 인덱스 >> ";

		int n;

		cin >> n;

		return n;
	}


};



int main()
{
	GraphicEditor editor;

	cout << "그래픽 에디터입니다.\n";


	while (true)
	{
		switch (UI::InputCommand())
		{
			case 1: 
				switch (UI::InsertNumShape())
				{
					case 1:
						editor.ADD(new Line());
						break;
					case 2:
						editor.ADD(new Circle());
						break;
					case 3:
						editor.ADD(new Rect());
						break;
				}
				break;

			case 2:
				editor.DELETE(UI::DeleteNumShape());
				break;

			case 3:
				editor.allShow();
				break;

			case 4:	return 0;

		}



	}





}