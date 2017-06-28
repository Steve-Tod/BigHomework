#include "stdafx.h"
#include <fstream>
#include <vector>
#include "memberclass.h"
using namespace std ;

void writechar(CString &s, const char* strPathName)
{
	ofstream out(strPathName, ios::app) ;
	USES_CONVERSION;

	char *s1 = T2A(s) ;
	out << s1 << endl ;
	out.close() ;
}

void ScoretoFile(std::vector<STU> &stu, const char* strPathName)//ˢ������
{
	std::vector<STU>::iterator iter = stu.begin();
	ofstream out(strPathName, ios::trunc) ;
	for (; iter != stu.end(); iter++)
	{
		iter->StoreSc(out);
	}
	out.close();
}

void readscore(std::vector<STU> &stu, const char* strPathName)
{
	ifstream in(strPathName, ios::in);
	char TermTemp[20], SubTemp[30];
	double ScoreTemp;
	stu.push_back(STU());
	for(int i = 0; ; i++)
	{
		in.getline(stu[i].username, 40);
		if (in.fail())
		{
			stu.pop_back();
			break;
		}
		in.getline(stu[i].password, 40);
		in >> TermTemp;
		while(TermTemp[0] != '#')
		{
			in >> SubTemp;
			in >> ScoreTemp;
			stu[i].sc.push_back(Score(TermTemp, SubTemp, ScoreTemp));
			in >> TermTemp;
		}
		in.get();
		stu.push_back(STU());
	}
	in.close();
}

int logincheck(CString &usernamein, CString &passwordin)//��½���
{
	CString temp[2] ;
	ifstream in("userdata.txt", ios::in) ;
	char Type[3];
	while(1)
	{
		if (in.eof())
			break ;
		char s1[40], s2[40];
		in.getline(s1, 40) ;
		in.getline(s2, 40) ;
		in.getline(Type, 3);
		CString temp1(s1), temp2(s2) ;
		if(!usernamein.Compare(temp1) && !passwordin.Compare(temp2))
			return Type[0] - '0' ;
	}
	in.close();
	return 0 ;
}

int FindStu(const char*s, std::vector<STU> &stu)//����ѧ���������е����
{
	int i = 0;
	std::vector<STU>::iterator iter = stu.begin();
	for (; iter != stu.end(); iter++, i++)
	{
		if (iter->CheckName(s))
			break;
	}
	if (iter == stu.end())
		return -1;
	return i;
}

void EditScore(CString &n, CString &t, CString &s, double score, std::vector<STU> &stu)
{
	USES_CONVERSION;
	const char* name = T2A(n);
	const char* term = T2A(t);
	const char* sub = T2A(s);
	int i = FindStu(name, stu);
	if (i >= 0)
	{
		stu[i].EditScore(term, sub, score); 
	}
	else
	{
		stu.push_back(STU(name, "123456"));
		vector<STU>::iterator iter = stu.end();
		iter--;
		iter->EditScore(term, sub, score); 
	}
}
int DeleteScore(CString &n, CString &t, CString &s, std::vector<STU> &stu)
{
	USES_CONVERSION;
	const char* name = T2A(n);
	const char* term = T2A(t);
	const char* sub = T2A(s);
	int i = FindStu(name, stu);
	if (i >= 0)
	{
		if(stu[i].DeleteScore(term, sub))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
