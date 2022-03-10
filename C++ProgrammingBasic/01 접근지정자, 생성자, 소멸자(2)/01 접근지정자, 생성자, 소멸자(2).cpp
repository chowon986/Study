#include <iostream>

// 메인의 내용을 백터 클래스로 만들어보기
class vector
{
	int* buff;
	int size;
public:
	vector(int sz)
	{
		size = sz;
		buff = new int[size];
	}

	~vector()
	{
		delete[] buff;
	}

	void resize(int newsize)
	{
		if (newsize > size)
		{
			int* temp = new int[newsize];
			memcpy(temp, buff, sizeof(int) * size);
			delete[] buff;

			buff = temp;
			size = newsize;
		}
	}
	
	void setAt(int idx, int value)
	{
		buff[idx] = value;
	}

	int getAt(int idx)
	{
		return buff[idx];
	}
};

int main()
{
	int arr[5];
	// 배열의 단점 : 크기를 변경할 수 없다.
	// 크기를 변경하려면 : 처음에 필요한 만큼의 메모리를 동적 할당

	int* buff = new int[5];
	buff[0] = 10;
	int* temp = new int[10];
	memcpy(temp, buff, sizeof(int) * 5);
	delete[] buff;

	buff = temp;
	buff[7] = 10;
	delete buff;


	// 동적 배열 (vector)
	// 크기 변경이 가능한 배열, 프로그램에서 자주 사용된다.
	// c언어는 재사용 가능하게 설계하는 것이 쉽지 않다.

	vector v(5);
	v.resize(10);

	v.setAt(0, 55);
	std::cout << v.getAt(0) << std::endl;
}

// push_back 제일 뒤에 추가
// vector의 사용법은 배열과 거의 동일하다.

// 클래스 파일 분할
// 선언과 구현으로 나눔
// 단, template는 반드시 헤더 파일에 멤버 함수 구현부도 있어야한다.
