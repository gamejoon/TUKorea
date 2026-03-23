//-------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			3월 23일				(3주 2일)
//-------------------------------------------------------------------
// 많은 수의 자료를 다루기 - FILE I/O - binary I/O - class 객체
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <array>
#include <print>
#include <string>
#include "save.h"

class Dog {
private:
	std::string name;
	size_t id;

	friend std::istream& operator >> (std::istream& is, const Dog& dog) {
		is.read((char*)&dog, sizeof(Dog));
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, const Dog& dog) {
		std::print(os, "[{:>4}] - {}", dog.id, dog.name);
		return os;
	}
};

// [문제] 파일 "Dog천마리"에는 class Dog 객체 1000개가 저장되어있다.
// 파일은 binary mode이고 각 객체는 메모리 크기 그대로 string의 write 함수로 기록하였다.
// 모든 객체는 한번의 write 함수를 사용하여 기록하였다.
// Dog의 멤버는 위의 코드와 같다.
// 메모리에 모두 읽어 와라.
// 메모리에 있는 모든 Dog를 화면에 출력하라.

//--------
int main()
//--------
{
	std::ifstream in{ "Dog천마리", std::ios::binary };
	if (not in) {
		std::cout << "Dog 없음" << std::endl;
		return 20260323;
	}

	std::array<Dog, 1000> dogs;

	in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

	for (const Dog& dog : dogs) {
		std::cout << dog << std::endl;
	}
	save("메인.cpp");
}