#include "stdafx.h"
#include <cstring>
#include <vector>
#include <fstream>

#pragma warning(disable:4996) 
class STU;
class Length
{
public:
	int l;
	Length(int L = 0): l(L) {}
	int GetLenth()
	{
		return l;
	}
	virtual void ChangeLength(int L) = 0;
};
class Name: virtual public Length
{
public:
	char username[40];
	Name(const char* u)
	{
		strcpy (username, u);
		ChangeLength(strlen(u));
	}
	Name(const CString &u)
	{
		USES_CONVERSION;
		char *us = T2A(u);
		strcpy(username, us);
		ChangeLength(strlen(us));
	}
	virtual void ChangeLength(int L)
	{
		Length::l = L;
	}
	BOOL operator == (Name &n)
	{
		return !strcmp(username, n.username);
	}
};
class Password: virtual public Length
{
public:
	char password[40];
	Password(const char* p)
	{
		strcpy(password, p);
		ChangeLength(strlen(p));
	}
	Password(const CString &p)
	{
		USES_CONVERSION;
		char *ps = T2A(p);
		strcpy(password, ps);
		ChangeLength(strlen(ps));
	}
	BOOL operator == (Password &p)
	{
		return !strcmp(password, p.password);
	}
	virtual void ChangeLength(int L)
	{
		Length::l = L;
	}
};
class person: public Name, public Password //普通人类
{
	int Type;
public:
	person(const char *u, const char *p): Name(u), Password(p)
	{
		strcpy (username, u) ;
		strcpy (password, p) ;
		Type = 0;
	}
	person(CString &u, CString &p): Name(u), Password(p)
	{
		Type = 0;
	}
	void Storetofile(std::ofstream &out);
	bool ReadtoObj(std::ifstream &in);
	int ChangePassword(const char* po, const char* pn);
	bool operator == (person &p)
	{
		if (!strcmp(username, p.username) && !strcmp(password, p.password))
			return TRUE;
		else
			return FALSE;
	}
	bool CheckName(const char* s)
	{
		return !strcmp(username, s);
	}
	friend void readscore(std::vector<STU> &sc, const char* strPathName);
	virtual void ChangeLength(int L)
	{
		Length::l = L;
	}
} ;

class Score
{
	char Term[20]; //学期
	char subname[30]; //科目
	double score ;
public:
	Score(const char* term, const char* sub, double sc): score(sc)
	{
		strcpy(Term, term);
		strcpy(subname, sub);
	}
	BOOL operator > (Score &s)//对学期进行排序
	{
		if (strcmp(Term, s.Term) > 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	BOOL operator < (Score &s)//对学期进行排序
	{
		if (strcmp(Term, s.Term) < 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	friend class STU ;
};
class STU: public person
{
public:
	std::vector<Score> sc ;
	STU(const char *u = "", const char *p = ""): person(u, p) {}
	STU(CString &u, CString &p): person(u, p) {}
	void Storetofile(std::ofstream &out);//存用户名密码数据
	void StoreSc(std::ofstream &out);//存学号成绩数据
	void SctoList(CListCtrl *List, const CString &Sem);
	void SctoList(CListCtrl *List);
	void EditScore(const char* t, const char* s, double score);
	void GetTerm(CComboBox &Term);//把学生成绩添加到combobox里面
	int DeleteScore(const char* t, const char* s);
	bool CheckName(const char* s)
	{
		return person::CheckName(s);
	}
	
	friend void readscore(std::vector<STU> &sc, const char* strPathName);
};