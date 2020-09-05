#include <bits/stdc++.h>
using namespace std;
#define siz(x) x.size()
#define pb push_back
/*
	Created By: Ranjeet Walia
*/
int Get_Days(int month, int year) 
{
	// cout << month << " " << year << " ";
	if(month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12)
		return 31;
	else if(month == 4 or month == 6 or month == 9 or month == 11)
		return 30;
	else if(year % 4 == 0 or (year % 100 == 0 and year % 400 == 0))
		return 29;
	else
		return 28;
}


class Calculator
{
private:
	int date, month, year;
	int YearGap, MonthGap, DateGap;
public:
	int Bd, Bm, By, Cd, Cm, Cy;
	string DateOfBirth, CurrentDate;
	
	// Input
	Calculator()
	{
		cout << "Enter the Date of Birth (dd-mm-yyyy): ";
		cin >> DateOfBirth;

		cout << "Enter the Current Date (dd-mm-yyyy): ";
		cin >> CurrentDate;
	}
	// Get Date
	vector<int> Date_Split(string str)
	{
		int len = siz(str), ind = 0;
		int flag = 0, store = 0;
		while(ind < len)
		{
			if(str[ind] == '-' and flag == 0){
				date = store;
				store = 0;
				flag = 1;
			}
			else if(str[ind] == '-' and flag == 1){
				month = store;
				store = 0;
				flag = 2;
			}
			else
			{
				int val = str[ind]-48;
				store = (store*10 + val);
			}
			ind += 1;
		}
		year = store;

		vector <int> return_date;
		return_date.pb(date);
		return_date.pb(month);
		return_date.pb(year);
		
		return return_date;	
	}
	// Assign Date of Birth
	void Assign_DOB(vector<int> &DOB)
	{
		Bd = DOB[0];
		Bm = DOB[1];
		By = DOB[2];
		// cout << Bd << " " << Bm << " " << By << "\n";
	}
	// Assign Current Date
	void Assign_CD(vector<int> &CD)
	{
		Cd = CD[0];
		Cm = CD[1];
		Cy = CD[2];
		// cout << Cd << " " << Cm << " " << Cy << "\n";
	}
	void Year_Calculation()
	{
		YearGap = Cy-By;
		if(Bm > Cm or (Bm == Cm and Bd > Cd))
			YearGap--;
		
		if(Cm > Bm)
		{
			MonthGap = Cm - Bm;
			if(Bd > Cd){
				MonthGap--;
				int days_pre_month = Get_Days(int(Cm-1) ? int(Cm-1) != 0 : 12, int(Cy));
				DateGap = days_pre_month - Bd + Cd;
			}
			else
				DateGap = Cd - Bd;

		}
		else if(Bm > Cm)
		{
			MonthGap = Cm + 12 - Bm;
			if(Bd > Cd){
				MonthGap--;
				int days_pre_month = Get_Days(int(Cm-1) ? int(Cm-1) != 0 : 12, int(Cy));
				DateGap = days_pre_month - Bd + Cd;
			}
			else
				DateGap = Cd - Bd;
		}
		else if(Bm == Cm)
		{
			if(Bd <= Cd)
				MonthGap = 0, DateGap = Cd - Bd;
			else if(Bd > Cd){
				MonthGap = 11;
				int days_pre_month = Get_Days(int(Cm-1) ? int(Cm-1) != 0 : 12, int(Cy));
				DateGap = days_pre_month - Bd + Cd;
			}
		}

		cout <<"You have lived " << YearGap << " years, " << MonthGap << " month and " << DateGap << " days.\n";
	}
};


int32_t main()
{
	Calculator cal;	

	// Date-Split Date of Birth
	vector<int> DOB = cal.Date_Split(cal.DateOfBirth);
	// Date-Split Current Date
	vector<int> CD = cal.Date_Split(cal.CurrentDate);
	// Assign Date of Birth
	cal.Assign_DOB(DOB);
	// Assign Current Date
	cal.Assign_CD(CD);
	// Calculate Age
	cal.Year_Calculation();
	return 0;
}

