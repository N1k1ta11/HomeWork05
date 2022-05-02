#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <deque>
using namespace std;

template<class T>
void task1(T begin, T end)
{
	set<string>s;
	copy(begin, end, inserter(s, s.end()));
	copy(s.begin(), s.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
}


class Text
{
private:
	string str;
public:
	Text(const string s) : str(s) {};
	bool operator < (const Text& t) const
	{
		return str.size() < t.str.size();
	}
	friend ostream& operator << (ostream& out,const Text& t)
	{
		out << t.str << " "<<t.str.size()<<endl;
		return out;
	}
	
};

void Task2()
{
	set<Text>text;
	string word;
	string sentence = "";
	getline(cin, word);
	for (int i = 0; i <= word.size(); i++)
	{
		sentence += word[i];
		if (word[i] == '.')
		{
			text.insert(Text(sentence));
			sentence = "";
		}
	}
	copy(text.begin(), text.end(), ostream_iterator<Text>{cout, "\n"});
}

int main()
{
	vector<string>t{ "book", "pen", "clock", "clock", "T-shirt", "T-shirt" };
	deque<string>d{ "book", "pen", "clock", "clock", "T-shirt", "T-shirt" };
	task1(t.begin(), t.end());
	task1(d.begin(), d.end());

	Task2();
}