// 복습_브루트포스

// 일곱 난쟁이 : https://www.acmicpc.net/problem/2309 

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    vector<int> talls;
//    int cnt = 9;
//    int sum = 0;
//    for (int i = 0; i < cnt; i++)
//    {
//        int tall;
//        cin >> tall;
//        talls.push_back(tall);
//        sum += tall;
//    }
//
//    sort(talls.begin(), talls.end());
//
//    for (int i = 0; i < 9; i++)
//    {
//        for (int j = 0; j < 9; j++)
//        {
//            if (i == j) continue;
//
//            if (sum - (talls[i] + talls[j]) == 100)
//            {
//                for (int k = 0; k < 9; k++)
//                {
//                    if (k != i && k != j)
//                        cout << talls[k] << '\n';
//                }
//                return 0;
//            }
//        }
//    }
//}

// 사탕 게임 : https://www.acmicpc.net/problem/3085

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n;
//int sum = 0;
//vector<vector<char>> board;
//
//void checkBomb(vector<vector<char>>& board)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int count = 0;
//		char prevBomb = board[i][0];
//		for (int j = 0; j < n; j++)
//		{
//			if (prevBomb == board[i][j])
//				++count;
//			else
//			{
//				sum = max(sum, count);
//				prevBomb = board[i][j];
//				count = 1;
//			}
//		}
//
//		sum = max(sum, count);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		int count = 0;
//		char prevBomb = board[i][0];
//		for (int j = 0; j < n; j++)
//		{
//			if (prevBomb == board[j][i])
//				++count;
//			else
//			{
//				sum = max(sum, count);
//				prevBomb = board[j][i];
//				count = 1;
//			}
//		}
//
//		sum = max(sum, count);
//	}
//}
//
//int main()
//{
//	cin >> n;
//	board.resize(n);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			char temp;
//			cin >> temp;
//			board[i].push_back(temp);
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (i < n - 1)
//			{
//
//				if (board[i][j] != board[i + 1][j])
//				{
//					swap(board[i][j], board[i + 1][j]);
//					checkBomb(board);
//					swap(board[i][j], board[i + 1][j]);
//				}
//			}
//
//			if (j < n - 1)
//			{
//				if (board[i][j] != board[i][j + 1])
//				{
//					swap(board[i][j], board[i][j + 1]);
//					checkBomb(board);
//					swap(board[i][j], board[i][j + 1]);
//				}
//			}
//		}
//	}
//
//	cout << sum;
//}

// 날짜 계산 : https://www.acmicpc.net/problem/1476

//#include <iostream>
//using namespace std;
//
//int  main()
//{
//    int e, s, m;
//    cin >> e >> s >> m;
//
//    int myE, myS, myM;
//    myE = myS = myM = 1;
//
//    int count = 1;
//    while (e != myE || s != myS || m != myM)
//    {
//        ++count;
//        ++myE;
//        ++myS;
//        ++myM;
//
//        if (myE == 16)
//            myE = 1;
//        if (myS == 29)
//            myS = 1;
//        if (myM == 20)
//            myM = 1;
//    }
//
//    cout << count;
//}

// 리모컨

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//vector<bool> isBroken(10, false);
//
//int main()
//{
//    int curChannel = 100;
//    int pressCount;
//    int target;
//    cin >> target;
//
//    int brokenCount;
//    cin >> brokenCount;
//
//    for (int i = 0; i < brokenCount; i++)
//    {
//        int temp;
//        cin >> temp;
//        isBroken[temp] = true;
//    }
//
//    int onlyUsePlusOrMinus = target > curChannel ? target - curChannel : curChannel - target;
//
//    int temp = target;
//    int curNum = temp;
//    while (curNum > 0)
//    {
//        if (isBroken[curNum % 10])
//        {
//            --temp;
//            curNum = temp;
//        }
//        else
//        {
//            curNum /= 10;
//
//            if(curNum == 0)
//                break;
//        }
//    }
//
//    if (curNum == 0)
//    {
//        if (!isBroken[0]) temp = 0;
//        else
//            temp = -1000000;
//    }
//
//	curNum = to_string(temp).size();
//	curNum += target - temp;
//
//	pressCount = min(curNum, onlyUsePlusOrMinus);
//
//	temp = target;
//    curNum = temp;
//    while (curNum >= 0 && curNum < 1000001)
//    {
//        if (isBroken[curNum % 10])
//        {
//            ++temp;
//            curNum = temp;
//        }
//        else
//        {
//            curNum /= 10;
//
//            if (curNum == 0)
//                break;
//        }
//    }
//
//    curNum = to_string(temp).size();
//    curNum += temp - target;
//
//    pressCount = min(curNum, pressCount);
//    cout << pressCount;
//}


// 테트로미노

// 카잉 달력

// 수 이어 쓰기1
// 1- 9 : 1
// 10 - 99 : 2
// 100 - 999 : 3

// 1, 2, 3 더하기 : https://www.acmicpc.net/problem/9095

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int tc;
//	cin >> tc;
//
//	vector<int> numbers(12, 0);
//
//	numbers[0] = 1;
//	numbers[1] = 1;
//	numbers[2] = 2;
//	numbers[3] = 4;
//
//	for (int i = 4; i < 12; i++)
//	{
//		numbers[i] = numbers[i - 3] + numbers[i - 2] + numbers[i - 1];
//	}
//
//	for (int i = 0; i < tc; i++)
//	{
//		int temp;
//		cin >> temp;
//
//		cout << numbers[temp] << '\n';
//	}
//}


// N과 M (1) : https://www.acmicpc.net/problem/15649

//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> number(10, 0);
//vector<bool> isUsed(10, false);
//
//void go(int index, int maxNum, int count)
//{
//    if (index == count)
//    {
//        for (int i = 0; i < index; i++)
//        {
//            cout << number[i] << ' ';
//        }
//
//        cout << '\n';
//        return;
//    }
//
//    for (int i = 1; i <= maxNum; i++)
//    {
//        if (isUsed[i]) continue;
//        number[index] = i;
//        isUsed[i] = true;
//        go(index + 1, maxNum, count);
//        isUsed[i] = false;
//    }
//}
//
//int main()
//{
//    int maxNum, count;
//    cin >> maxNum >> count;
//    go(0, maxNum, count);
//}

// N과 M (2) : https://www.acmicpc.net/problem/15650

// N과 M (2)
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> numbers(10, 0);
//vector<bool> isUsed(10, false);
//
//void go(int index, int start, int maxNum, int count)
//{
//    if (index == count)
//    {
//        for (int i = 0; i < index; i++)
//        {
//            cout << numbers[i] << ' ';
//        }
//
//        cout << '\n';
//        return;
//    }
//
//    for (int i = start; i <= maxNum; i++)
//    {
//        if (isUsed[i]) continue;
//
//        isUsed[i] = true;
//        numbers[index] = i;
//        go(index + 1, i + 1, maxNum, count);
//        isUsed[i] = false;
//    }
//}
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//
//    go(0, 1, n, m);
//}

// N과 M (3) : https://www.acmicpc.net/problem/15651

//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> numbers(10, 0);
//
//void go(int index, int maxNum, int count)
//{
//	if (index == count)
//	{
//		for (int i = 0; i < index; i++)
//		{
//			cout << numbers[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//
//	for (int i = 1; i <= maxNum; i++)
//	{
//		numbers[index] = i;
//		go(index + 1, maxNum, count);
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	go(0, n, m);
//}

// N과 M (4) : https://www.acmicpc.net/problem/15652

//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> numbers(10, 0);
//
//void go(int index, int start, int maxNum, int count)
//{
//	if (index == count)
//	{
//		for (int i = 0; i < index; i++)
//		{
//			cout << numbers[i] << ' ';
//		}
//
//		cout << '\n';
//		return;
//	}
//
//	for (int i = start; i <= maxNum; i++)
//	{
//		numbers[index] = i;
//		go(index + 1, i, maxNum, count);
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	go(0, 1, n, m);
//}

// N과 M (5) : https://www.acmicpc.net/problem/15654

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<bool> isused(10001, true);
//vector<int> numbers;
//vector<int> newnumbers(10, 0);
//
//void go(int index, int maxnum, int count)
//{
//	if (index == count)
//	{
//		for (int i = 0; i < index; i++)
//		{
//			cout << newnumbers[i] << ' ';
//		}
//
//		cout << '\n';
//		return;
//	}
//
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		if (isused[numbers[i]]) continue;
//
//		newnumbers[index] = numbers[i];
//		isused[numbers[i]] = true;
//		go(index + 1, maxnum, count);
//		isused[numbers[i]] = false;
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		numbers.push_back(temp);
//		isused[temp] = false;
//	}
//
//	sort(numbers.begin(), numbers.end());
//
//	go(0, n, m);
//}


// N과 M(6) : https://www.acmicpc.net/problem/15655

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> numbers;
//vector<int> newNumbers(10001, 0);
//vector<bool> isUsed(10001, true);
//
//void go(int index, int start, int count)
//{
//	if (index == count)
//	{
//		for (int i = 0; i < index; i++)
//		{
//			cout << newNumbers[i] << ' ';
//		}
//
//		cout << '\n';
//		return;
//	}
//
//	for (int i = start; i < numbers.size(); i++)
//	{
//		if (isUsed[numbers[i]]) continue;
//
//		isUsed[numbers[i]] = true;
//		newNumbers[index] = numbers[i];
//		go(index + 1, i +1 , count);
//		isUsed[numbers[i]] = false;
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		numbers.push_back(temp);
//		isUsed[temp] = false;
//	}
//
//	sort(numbers.begin(), numbers.end());
//
//	go(0, 0, m);
//}

// N과 M (7) : https://www.acmicpc.net/problem/15656

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> numbers;
//vector<int> newNumbers(10, 0);
//void go(int index, int count)
//{
//	if (index == count)
//	{
//		for (int i = 0; i < index; i++)
//		{
//			cout << newNumbers[i] << ' ';
//		}
//
//		cout << '\n';
//		return;
//	}
//
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		newNumbers[index] = numbers[i];
//		go(index + 1, count);
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		numbers.push_back(temp);
//	}
//
//	sort(numbers.begin(), numbers.end());
//
//	go(0, m);
//}

// N과 M (8) : https://www.acmicpc.net/problem/15657

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> numbers;
//vector<int> newNumbers(10, 0);
//
//void go(int index, int start, int count)
//{
//	if (index == count)
//	{
//		for (int i = 0; i < index; i++)
//		{
//			cout << newNumbers[i] << ' ';
//		}
//
//		cout << '\n';
//		return;
//	}
//
//	for (int i = start; i < numbers.size(); i++)
//	{
//		newNumbers[index] = numbers[i];
//		go(index + 1, i, count);
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		numbers.push_back(temp);
//	}
//
//	sort(numbers.begin(), numbers.end());
//
//	go(0, 0, m);
//}
