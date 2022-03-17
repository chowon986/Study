// 다중상속
#include <iostream>


// 가상 상속
// : virtual 상속을 사용하면 File의 인스턴스가 메모리에 한 번만 생성된다.

class InputFile : virtual public File
{
public:
    void read()
    {
    }

    // void open(){}
};

class OutputFile : virtual public File
{
public:
    void write()
    {
    }

    // void open(){}
};

// 다중 상속
// 클래스가 2개 이상의 기반 클래스로부터 상속되는 것
// (문제점)
// (1) 서로 다른 기반 클래스에 동일 이름의 멤버가 있을 때 이름 충돌
// 해결 방법 : 범위 지정 연산자(::) 사용
// (2) Diamond 형태의 상속

class IOFile : public InputFile, public OutputFile
{

};

// 모든 파일의 공통의 특징을 담은 클래스 생성
class File
{
public:
    std::string filename;
    void open()
    {

    }
};

int main()
{
    //          File
    // InputFile    OutputFile
    //         IOFile
    // 다이아몬드 형태가 되면서 모호해짐
}