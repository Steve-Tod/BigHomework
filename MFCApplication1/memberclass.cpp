#include "stdafx.h"
#include "memberclass.h"
#include <fstream>
#include <vector>
#include <cstring>
void person::Storetofile(std::ofstream &out)
{
	out << username << std::endl << password << std::endl;
}


void STU::Storetofile(std::ofstream &out)//用户名密码和Type存入文件
{
	person::Storetofile(out) ;
	out << Type << std::endl ;
}

void STU::StoreSc(std::ofstream &out)//学号和成绩存入文件
{
	person::Storetofile(out);
	for (std::vector<Score>::iterator iter = sc.begin(); iter != sc.end(); iter++)
	{
		out << iter->Term << ' ' << iter->subname << ' ' << iter->score << ' ';
	}
	out << "#" << std::endl;
}

void STU::SctoList(CListCtrl *List, const CString &Sem)
{
	CString SNumtemp;
	int i = 0;
	for(std::vector<Score>::iterator iter = sc.begin(); iter != sc.end(); iter++, i++)
	{
		if (Sem.Compare(CString(iter->Term)) == 0)
		{
			int nRow = List->InsertItem(i, CString(iter->subname));
			SNumtemp.Format(_T("%.1lf"), iter->score);
			List->SetItemText(nRow, 1, SNumtemp);
		}
	}
}
void STU::SctoList(CListCtrl *List)
{
	CString SNumtemp;
	int i = 0;
	for(std::vector<Score>::iterator iter = sc.begin(); iter != sc.end(); iter++, i++)
	{
		List->InsertItem(i, CString(iter->Term));
		List->SetItemText(i, 1, CString(iter->subname));
		SNumtemp.Format(_T("%.1lf"), iter->score);
		List->SetItemText(i, 2,SNumtemp);
	}
}

void STU::EditScore(const char *t, const char* s, double score) 
{
	std::vector<Score>::iterator iter = sc.begin();
	int flag = 1;
	while(1)
	{
		if (iter == sc.end())
		{
			flag = 0;
			break;
		}
		if (!strcmp(iter->subname, s) && !strcmp(iter->Term, t))
		{
			break;
		}
		iter++;
	}
	if (flag == 1)
	{
		iter->score = score ;
	}
	else
	{
		sc.push_back(Score(t, s, score));
	}
}
int STU::DeleteScore(const char* t, const char* s)
{
	std::vector<Score>::iterator iter = sc.begin();
	int flag = 1;
	while(1)
	{
		if (iter == sc.end())
		{
			return 0;
		}
		if (!strcmp(iter->subname, s) && !strcmp(iter->Term, t))
		{
			break;
		}
		iter++;
	}
	sc.erase(iter);
	return 1;
}

void STU::GetTerm(CComboBox &Term)
{
	int size = this->sc.size();
	std::vector<char*> AllTerm;
	for (int i = 0; i < size; i++)
	{
		int flag = 0;
		for (std::vector<char*>::iterator j = AllTerm.begin(); j != AllTerm.end(); j++)
		{
			if (strcmp(sc[i].Term, *j) == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			AllTerm.push_back(sc[i].Term);
		}
	}
	for (std::vector<char*>::iterator j = AllTerm.begin(); j != AllTerm.end(); j++)
	{
		Term.AddString(CString(*j));
	}
}

