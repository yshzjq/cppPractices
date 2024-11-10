#ifndef EXP_H
#define EXP_H

// 클래스 선언부
class Exp
{
	// 멤버 변수
	int base;  // 베이스
	int exp;   // 지수
public:
	// 생성자
	Exp();
	Exp(int _base);
	Exp(int _base, int _exp);
	
	// 멤버 함수
	int getBase();
	int getExp();
	int getValue();
	bool equals(Exp exp);
	
};

#endif

