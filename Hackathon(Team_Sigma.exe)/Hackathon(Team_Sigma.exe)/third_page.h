#pragma once
#include <string>
using namespace std;
typedef struct generalinfo
{
	string firstname;
	string lastname;
	string nationality;
	string dateofbirth;
	string gender;
}gnrlinfo;
typedef struct socialinfo
{
	string linkedinlink;
	string postalcode;
	string phone;
	string email;
}sclinfo;
typedef struct businessinfo
{
	string jobtitle;
	string employer;
	string city;
	string country;
	string startdate;
	string enddate;
}bsinfo;
typedef struct educationinfo
{
	string instname;
	string instlocation;
	string graduationyear;
	string fieldofstudy;
	string qualification;
}eduinfo;
string skillinfo;

