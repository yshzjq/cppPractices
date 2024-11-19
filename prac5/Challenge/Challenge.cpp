#include <iostream>
#include <string>

using namespace std;

class Morse {
	string alphabet[26]; // 알파벳의모스 부호저장
	string digit[10]; // 숫자의 모스 부호 저장
	string slash, question, comma, period, plus, equal; // 특수 문자의 모스 부호 저장
public:
	Morse(); // alphabet[], digit[] 배열 및 특수 문자의 모스 부호 초기화
	void text2Morse(string text, string& morse); // 영문 텍스트를 모스 부호로 변환
	bool morse2Text(string morse, string& text); // 모스 부호를 영문 텍스트로 변환
};

Morse::Morse()
{
    // 알파벳 모스 부호 초기화(초기화만 GPT 도움을 받음 ㅎㅎ)
    alphabet[0] = ".-";    // A
    alphabet[1] = "-...";  // B
    alphabet[2] = "-.-.";  // C
    alphabet[3] = "-..";   // D
    alphabet[4] = ".";     // E
    alphabet[5] = "..-.";  // F
    alphabet[6] = "--.";   // G
    alphabet[7] = "....";  // H
    alphabet[8] = "..";    // I
    alphabet[9] = ".---";  // J
    alphabet[10] = "-.-";  // K
    alphabet[11] = ".-.."; // L
    alphabet[12] = "--";   // M
    alphabet[13] = "-.";   // N
    alphabet[14] = "---";  // O
    alphabet[15] = ".--."; // P
    alphabet[16] = "--.-"; // Q
    alphabet[17] = ".-.";  // R
    alphabet[18] = "...";  // S
    alphabet[19] = "-";    // T
    alphabet[20] = "..-";  // U
    alphabet[21] = "...-"; // V
    alphabet[22] = ".--";  // W
    alphabet[23] = "-..-"; // X
    alphabet[24] = "-.--"; // Y
    alphabet[25] = "--.."; // Z

    // 숫자 모스 부호 초기화
    digit[0] = "-----"; // 0
    digit[1] = ".----"; // 1
    digit[2] = "..---"; // 2
    digit[3] = "...--"; // 3
    digit[4] = "....-"; // 4
    digit[5] = "....."; // 5
    digit[6] = "-...."; // 6
    digit[7] = "--..."; // 7
    digit[8] = "---.."; // 8
    digit[9] = "----."; // 9

    // 특수 문자 모스 부호 초기화
    slash = "-..-.";
    question = "..--..";
    comma = "--..--";
    period = ".-.-.-";
    plus = ".-.-.";
    equal = "-...-";
}

void Morse::text2Morse(string text, string& morse)
{
    for (char c : text)
    {
        if (isalpha(c))
        {
            cout << alphabet[toupper(c) - 'A'];
        }
        else if (isdigit(c))
        {
            cout << digit[c - '0'];
        }
        else
        {
            if (c == '/') { cout << slash; }
            else if (c == '?') { cout << question; }
            else if (c == ',') { cout << comma; }
            else if (c == '.') { cout << period; }
            else if (c == '+') { cout << plus; }
            else if (c == '=') { cout << equal; }
        }

        cout << ' ';
    }
}



int main()
{
	string str;
    string result1;
    string result2;

	cout << "아래에 영문 켁스트를 입력하세요. 모스부호로 바꿉니다.\n";

	getline(cin, str);

    Morse morse;

    morse.text2Morse(str, result1);

    cout << result1 << "\n\n";

    cout << "모스 부호를 다시 영문 텍스트로 바꿉니다.\n";

    morse.text2Morse(result1, result2);

    cout << result2;

}

