#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

class Student {
public:
	string name;
	int korean;
	int english;
	int math;
	Student() {}
	Student(string name, int korean, int english, int math)
	{
		this->name = name;
		this->korean = korean;
		this->english = english;
		this->math = math;
	}
	void setStudent(string name, int korean, int english, int math)
	{
		this->name = name;
		this->korean = korean;
		this->english = english;
		this->math = math;
	}
};

bool compare(Student a, Student b)
{ 
	if (a.korean == b.korean)
	{
		if (a.english == b.english)
		{
			if (a.math != b.math)
			{
				return a.math > b.math;
				
			}
			else
			{
				return a.name < b.name;
			}
		}
		else
		{
			return a.english < b.english;
		}
	}
	else
	{
		return a.korean > b.korean;
	}
}

int main()
{
	int n;
	string name;
	int korean, english, math;
	Student students[1000001];
	

	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> korean >> english >> math;
		students[i].setStudent(name, korean, english, math);
	}
	sort(students, students + n, compare);

	for (int i = 0; i < n; i++)
		cout << students[i].name<< "\n";
	

return 0;
}
