// 복습_수학.cpp 

// 나머지

// 나머지 : https://www.acmicpc.net/problem/10430
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int A, B, C;
//	cin >> A >> B >> C;
//
//	cout << (A + B) % C << '\n';
//	cout << ((A % C) + (B % C)) % C << '\n';
//	cout << (A * B) % C << '\n';
//	cout << ((A % C) * (B % C)) % C << '\n';
//}

// 1

// 1 : https://www.acmicpc.net/problem/4375
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        int num = 0;
//        for (int i = 1; ; i++)
//        {
//            num = num * 10 + 1;
//            num = num % n;
//
//            if (num == 0)
//            {
//                cout << i << '\n';
//                break;
//            }
//        }
//    }
//}

// 약수

// 약수 : https://www.acmicpc.net/problem/1037
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int tc;
//    cin >> tc;
//    int max = -1;
//    int min = 1000001;
//    for (int i = 0; i < tc; i++)
//    {
//        int temp;
//        cin >> temp;
//
//        if (max < temp) max = temp;
//        if (min > temp) min = temp;
//    }
//
//    cout << min * max;
//}

// 약수의 합 2

// 약수의 합 2 : https://www.acmicpc.net/problem/17427
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    long long sum = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        sum += (n / i) * i;
//    }
//
//    cout << sum;
//}

// 약수의 합

// 약수의 합 : https://www.acmicpc.net/problem/17425
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    vector<long long> g(1000001, 1);
//    g[0] = 0;
//
//    for (int i = 2; i <= 1000000; i++)
//    {
//        for (int j = 1; i * j <= 1000000; j++)
//        {
//            g[i * j] += i;
//        }
//    }
//
//    for (int i = 2; i <= 1000000; i++)
//    {
//        g[i] = g[i] + g[i - 1];
//    }
//
//    int tc;
//    cin >> tc;
//    for (int i = 0; i < tc; i++)
//    {
//        int temp;
//        cin >> temp;
//        cout << g[temp] << '\n';
//    }
//}


// 최대공약수와 최소공배수

// 최대공약수와 최소공배수 : https://www.acmicpc.net/problem/2609
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int a, b;
//    cin >> a >> b;
//
//    int originA = a;
//    int originB = b;
//
//    while (true)
//    {
//        if (a < b) swap(a, b);
//        int temp = a % b;
//        a = b;
//        b = temp;
//        if (b == 0)
//        {
//            cout << a << '\n';
//            break;
//        }
//    }
//
//    cout << a * (originA / a) * (originB / a);
//}

// 소수 찾기

// 소수 찾기 : https://www.acmicpc.net/problem/1978
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    vector<bool> isPrime(1001, true);
//    isPrime[0] = isPrime[1] = false;
//
//    for (int i = 2; i <= 1000; i++)
//    {
//        if (isPrime[i] == true)
//        {
//            for (int j = 2; i * j <= 1000; j++)
//            {
//                isPrime[i * j] = false;
//            }
//        }
//    }
//
//    int tc;
//    cin >> tc;
//
//    int sum = 0;
//    for (int i = 0; i < tc; i++)
//    {
//        int temp;
//        cin >> temp;
//        if (isPrime[temp]) ++sum;
//    }
//
//    cout << sum;
//}

// 소수 구하기

// 소수 구하기 : https://www.acmicpc.net/problem/1929
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int from, end;
//    cin >> from >> end;
//
//    vector<bool> isPrime(1000001, true);
//    isPrime[0] = false;
//    isPrime[1] = false;
//
//    for (int i = 2; i <= 1000000; i++)
//    {
//        if (isPrime[i])
//        {
//            for (int j = 2; i * j <= 1000000; j++)
//            {
//                isPrime[i * j] = false;
//            }
//        }
//    }
//
//    for (int i = from; i <= end; i++)
//    {
//        if (isPrime[i])
//            cout << i << '\n';
//    }
//}

// 골드바흐의 추측

// 골드바흐의 추측 : https://www.acmicpc.net/problem/6588
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    vector<bool> isPrime(1000001, true);
//    isPrime[0] = false;
//    isPrime[1] = false;
//
//    for (int i = 2; i <= 1000000; i++)
//    {
//        if (isPrime[i])
//        {
//            for (int j = 2; i * j <= 1000000; j++)
//            {
//                isPrime[i * j] = false;
//            }
//        }
//    }
//
//    int n;
//    while (true)
//    {
//        cin >> n;
//        if (n == 0) break;
//
//        for (int i = 3; i <= n; i++)
//        {
//            if (isPrime[i] && isPrime[n - i])
//            {
//                cout << n << " = " << i << " + " << (n - i) << '\n';
//                break;
//            }
//        }
//    }
//}

int main()
{

}