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
	virtual void UselessFun() = 0; //��Ǹ����ò��������
};
class person: public User //��ͨ����
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
	}//���Ҳû����...
	bool CheckName(const char* s)
	{
		return !strcmp(username, s);
	}
	friend void readscore(std::vector<STU> &sc, const char* strPathName);
	virtual void UselessFun() {}
} ;

class Score
{
	char Term[20]; //ѧ��
	char subname[30]; //��Ŀ
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
	void Storetofile(std::ofstream &out);//���û�����������
	void StoreSc(std::ofstream &out);//��ѧ�ųɼ�����
	void SctoList(CListCtrl *List, const CString &Sem);
	void SctoList(CListCtrl *List);
	void EditScore(const char* t, const char* s, double score);
	void GetTerm(CComboBox &Term);//��ѧ���ɼ���ӵ�combobox����
	int DeleteScore(const char* t, const char* s);
	bool CheckName(const char* s)
	{
		return person::CheckName(s);
	}
	friend void readscore(std::vector<STU> &sc, const char* strPathName);
} ;