#include "stdafx.h"
#include <cstring>
#include <vector>
#include <fstream>

#pragma warning(disable:4996) 
class STU;
class User
{
public:
	char username[40] ;
	char password[40] ;
	int UselessVal;
	User(const char *u, const char *p)
	{
		strcpy (username, u) ;
		strcpy (password, p) ;
	}
	User(CString &u, CString &p)
	{
		USES_CONVERSION ;
		char *u1, *p1 ;
		u1 = T2A(u) ;
		p1 = T2A(p) ;
		strcpy (username, u1) ;
		strcpy (password, p1) ;
	}
	~User() {}
	virtual void UselessFun() = 0; //抱歉真的用不到虚基类
};
class person: public User //普通人类
{
	int Type;
public:
	person(const char *u, const char *p): User(u, p)
	{
		strcpy (username, u) ;
		strcpy (password, p) ;
		Type = 0;
	}
	person(CString &u, CString &p): User(u, p)
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
	}//这个也没用上...
	bool CheckName(const char* s)
	{
		return !strcmp(username, s);
	}
	friend void readscore(std::vector<STU> &sc, const char* strPathName);
	virtual void UselessFun() {}
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
} ;