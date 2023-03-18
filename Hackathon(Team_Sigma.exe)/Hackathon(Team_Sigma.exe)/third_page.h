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
	string linkedinIDlink;
	string postalcode;
	string phone;
	string email;
}sclinfo;
typedef struct jobinfo
{
	string jobtitle;
	string employer;
	string city;
	string country;
	string startdate;
	string enddate;
}jbinfo;
typedef struct educationinfo
{
	string instname;
	string instlocation;
	string graduationyear;
	string fieldofstudy;
	string qualification;
}eduinfo;
typedef struct additionalinfo
{
	string language;
	string accomplishment;
	string certification;
	string hobbies;
	string sports;
	string extra;
}adlinfo;

