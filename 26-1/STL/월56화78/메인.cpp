//-------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			3월 24일				(4주 1 일)
//-------------------------------------------------------------------
// 스마트 포인터 -> 콜러블 타입 -> 실습 -> STL
//-------------------------------------------------------------------
#include <iostream>
#include <numeric>
#include <memory>
#include "save.h"

// [문제] 사용자가 입력한 수만큼 int를 저장할 메모리를 확보하라.
// 1부터 시작하는 정수로 메모리를 채워라.
// 합계를 화면에 출력하라.

//--------
int main()
//--------
{
	//int* p; -> 사용하지 말아야 함
	// C++11(Modern C++)에 이것의 완벽한 대체 수단이 있기 때문에 -> smart_point
	
	std::unique_ptr<int[]> p;
	while (true) {
		std::cout << "int 몇 개가 필요하신지? ";
		size_t num;
		std::cin >> num;

		try {
			p.reset( new int[num] );
		}
		catch (std::exception& e) {
			std::cout << "메모리가 고갈 - " << e.what() << std::endl;
		}

		//for (int i = 0; i < num; ++i) {
		//	p[i] = i + 1;
		//}
		std::iota(p.get(), p.get() + num, 1);

		//long long sum{};
		//for (int i = 0; i < num; ++i) {
		//	sum += p[i];
		//}

		long long sum = std::accumulate(p.get(), p.get() + num, 0LL); // 접미사 long long
		std::cout << "1 부터 " << num << "까지의 합계 ----- " << sum << std::endl; // 가산한다

		//delete[] p; 더이상 내가 직접 메모리 반환을 안해도 됨
	}

	save("메인.cpp");
}