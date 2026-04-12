//-------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			4월 7일			(6주 1일)
//-------------------------------------------------------------------
// STL 컨테이너 - std::string과 유사한 ZString을 만들어서 컨테이너 본질에 접근
//-------------------------------------------------------------------
#include <iostream>
#include <string>
#include<memory>
#include "save.h"

class ZString {
public:
	ZString() {
		std::cout << "생성() 글자수:" << len << " 객체:" << this << " 글자주소:" << (void*)p.get() << std::endl;
	};

	ZString(const char* s) {
		len = strlen(s);
		p = std::make_unique<char[]>(len);
		memcpy(p.get(), s, len);

		std::cout << "생성(char*) 글자수:" << len << " 객체:" << this << " 글자주소:" << (void*)p.get() << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const ZString& zs) {
		for (int i = 0; i < zs.len; ++i)
			os << *(zs.p.get() + i);
		return os;
	}

private:
	size_t len{};
	std::unique_ptr<char[]> p{};
};

//--------
int main()
//--------
{	
	// 이 동작 다시 설명하고 ZString으로 바꾸면 안되는 이유부터 시작

	std::string s{ "2026년" };
	std::string t = move(s);
	std::cout << "s - " << s << std::endl;
	std::cout << "t - " << t << std::endl;

	ZString a{ "2026" };
	std::cout << a << std::endl;
	ZString b{ "0407" };
	std::cout << b << std::endl;

	save("메인.cpp");
}