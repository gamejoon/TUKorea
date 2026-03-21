//-------------------------------------------------------------------
// 한 학기 강의를 저장하기 위한 함수
// 
// 2026/03/09
//-------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "save.h"

void save(const std::string& fname)
{
	std::ifstream in{ fname };	// RAII 공부할 것

	// fname 파일이 존재하는지 확인
	if (not in) { // !는 읽기 어렵기 때문에 not으로 바꿔쓸 것
		std::cout << fname << " - 열 수 없습니다." << '\n';
		exit(202630);
	}

	std::cout << "\"" << fname << "\"" << "를 저장합니다." << '\n';

	std::ofstream out{ "2026년 1학기 STL 월56화78.txt", std::ios::app }; // std::ios::app 이전 내용에 추가하는 코드

	// 시간정보를 얻는다.

	// std::chrono::system_clock::time_point now = std::chrono::system_clock::now(); // time epoch로 부터 1초마다 증가한 tick 수
	auto now = std::chrono::system_clock::now(); // auto = 함수의 반환값으로 자동으로 변수의 자료형을 정해줌

	using namespace std::chrono_literals;
	//std::cout << now + 9h << '\n'; // 시간이 utc 기준이므로 한국 기준인 9시간을 추가로 더해줘야 함

	out << '\n' << '\n';
	out << "=====================================================================" << '\n';
	out << "Save Time - " << now + 9h << '\n';
	out << "=====================================================================" << '\n';
	out << '\n';

	//char c;
	//in >> std::noskipws;
	//while (in >> c)
	//	out << c;

	//operator >> (in, c); // 고수준 입력 명령어 
	//std::cout << c;

	// std::copy(어디에서, 어디까지를, 어디로);
	std::copy(std::istreambuf_iterator<char>{in}, {}, std::ostream_iterator<char>{out});
}