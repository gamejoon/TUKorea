//-------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			3월 30일			(4주 2일)
//-------------------------------------------------------------------
// CALLABLE TYPE -> 실습 -> STL
//-------------------------------------------------------------------
#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"

//--------
INT MAIN()
//--------
{	
	STD::IFSTREAM IN{ "메인.CPP" };
	IF (NOT IN) {
		RETURN 20260330;
	}

	STD::OFSTREAM OUT{ "메인대문자.CPP" };

	//TRANSFORM(뭐를->메인.CPP, 뭘로->메인대문자.CPP, 어떻게->소문자를 대문자로);
	STD::TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, STD::OSTREAMBUF_ITERATOR<CHAR>{OUT}, 
		[](CHAR C) {
			RETURN C = TOUPPER(C);
		});

	SAVE("메인.CPP");
}