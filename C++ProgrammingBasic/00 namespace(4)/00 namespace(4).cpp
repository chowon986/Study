#include <iostream>

namespace Video
{
    void init()
    {
    }

    namespace Render
    {
        void start()
        {
        }
    }
}
int main()
{
    Video::init();
    Video::Render::start();

    //using namespace Video;
    // init();
    // Render::start;
}

/* namespace는 중첩(nested)이 가능하다.

C++ 표준 namespace
std              | 대부분의 c++ 표준 라이브러리
std::filesystem  | 파일 관련 표준라이브러리 (c++17)
std::chrono      | 날짜/시간 관련 표준 라이브러리 (c++11)
std::this_thread | 스레드 관련 표준 라이브러리 (c++11)
*/

/* namespace alias
#include <filesystem>

int main()
{
    std::filesystem::create_directory("C:/Test");
    if(! std::fliesystem::exists("C:/Test/calc.exe"))
    {
        std::filesystem::copy_file("C:/Windows/system32/calc.exe", "C:/Test/calc.exe");
    }

이 경우, namespace를 이용해 std::filesystem을 간단하게 바꿀 수 있다.

int main()
{
    namespace fs = std::filesystem; // 이 부분은 main 밖에 놔도 된다.

    fs::create_directory("C:/Test");
    if(! fs::exists("C:/Test/calc.exe"))
    {
        fs::copy_file("C:/Windows/system32/calc.exe", "C:/Test/calc.exe");
    }
}
*/