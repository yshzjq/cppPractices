#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {};
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

void Person::set(string name, string tel)
{
	this->name = name;
	this->tel = tel;
}

int main()
{
	const int person_count = 3;

	Person* persons = new Person[person_count];

	cout << "이름과 전화 번호를 입력해 주세요\n";

	for (int i = 0; i < person_count; i++)
	{
		string info;

		string info_name;
		string info_telnumber;

		cout << "사람 " << i+1 << " >> ";
		
		getline(cin,info);

		info_name = info.substr(0,info.find(' '));
		info_telnumber = info.substr(info.find(' ')+1);

		persons[i].set(info_name, info_telnumber);
	}

	cout << "모든 사람의 이름은 ";

	for (int i = 0; i < person_count; i++)
	{
		cout << persons[i].getName() << ' ';
	}

	string find_name;

	cout << "\n전화번호를 검색합니다. 이름을 입력하세요 >>";

	cin >> find_name;

	for (int i = 0; i < person_count; i++)
	{
		if (find_name == persons[i].getName())
		{
			cout << "전화번호는 " << persons[i].getTel();
			break;
		}
	}

	delete[] persons;
}


