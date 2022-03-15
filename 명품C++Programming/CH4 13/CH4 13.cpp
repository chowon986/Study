#include <iostream>
#include <string>
using namespace std;

class Histogram
{
private:
	string text;
	char ch;

public:
	Histogram(string text)
	{
		this->text = text + '\n';
	}
	void put(string a)
	{
		text.append(a);
	}
	void putc(char b)
	{
		ch = b;
		text += b;
	}
	void print()
	{
		int num = 0;
		int c = (int)size(text);
		for (int i = 0; i < c; i++)
		{
			if (text[i] == ' ' ||
				text[i] == ch ||
				text[i] == ',' ||
				text[i] == '\'' ||
				text[i] == '\n')
			{
				continue;
			}
			++num;
		}
		cout << text << endl << endl;
		cout << "총 알파벳 수 " << num << endl << endl;
		
		num = 0;
		for (char i = 97; i <= 122; i++)
		{
			for (char j = 0; j < (int)size(text); j++)
			{
				if (text[j] == i||text[j] == i-32)
				{
					++num;
					continue;
				}
			}
			cout << i << " (" << num << ')' << '\t' << " : ";
			for (int k = 0; k < num; k++)
			{
				cout << "*";
			}
			cout << endl;
			num = 0;
		}
	}
};

int main()
{
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}
