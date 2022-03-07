#include <iostream>
#include <cstdlib>

int main()
{
	// int* p1 = (int*)malloc(sizeof(int));
	// free(p1);

	int* p2 = new int;
	delete p2;

	int* p3 = new int[10];
	delete[] p3;

	//			  malloc		 vs				new
	// 정체		 : 함수							연산자(키워드)
	// 인자	     : 할당할 메모리 크기				타입
	// 반환타입	 : void*						전달한 타입의 포인터 (캐스팅 필요 없음)
	//             원하는 타입으로 캐스팅 필요		
	// 해지방법   : free							delete 또는 delete[]
	// 생성자	 : 생성자 호출 안됨				생성자 호출됨



	// three way comparison operator
	// 우주선 연산자라고도 불리는 연산자
	// auto ret = (n1 <=> n2)

	/*
	int n1 = 20, n2 = 20;
	bool b1 = (n1 < n2);
	
	auto ret = (n1 <=> n2);
	if (ret == 0)
	{
		std::cout << "n1 == n2" << std::endl;
	}
	else if (ret > 0)
	{
		std::cout << "n1 > n2" << std::endl;
	}
	else if (ret > 0)
	{
		std::cout << "n1 < n2" << std::endl;
	}

	<=>는 반환 값을 cout으로 출력할 수 없다.
	// 0과 크기 비교만 가능하다.
	// 어떤 타입을 비교하는지에 따라 반환 타입이 달라진다. -> auto로 받아야 한다.
	// std::strong_ordering,
	// std::weak_ordering,
	// std::partial_ordering
	*/

}
