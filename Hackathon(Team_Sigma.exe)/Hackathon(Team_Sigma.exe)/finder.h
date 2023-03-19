#pragma once
#include<stdlib.h>
#include "third_page.h"
void findData(generalinfo geninfo, socialinfo socinfo, jobinfo businfo, educationinfo eduinfo, adlinfo addInfo, string finalname) {
	string temp, name;
	FILE* fptr;
	fopen_s(&fptr,"SaveData.txt", "r, ccs=UNICODE");
	do {
		fscanf_s(fptr, "%s", name);
	} while (name != finalname);
	fscanf_s(fptr, "%s", temp);
	fscanf_s(fptr, "%s", geninfo.firstname);
	fscanf_s(fptr, "%s", geninfo.lastname);
	fscanf_s(fptr, "%s", geninfo.nationality);
	fscanf_s(fptr, "%s", geninfo.dateofbirth);
	fscanf_s(fptr, "%s", geninfo.gender);

	fscanf_s(fptr, "%s", socinfo.phone);
	fscanf_s(fptr, "%s", socinfo.email);
	fscanf_s(fptr, "%s", socinfo.postalcode);
	fscanf_s(fptr, "%s", socinfo.linkedinIDlink);

	fscanf_s(fptr, "%s", businfo.jobtitle);
	fscanf_s(fptr, "%s", businfo.employer);
	fscanf_s(fptr, "%s", businfo.city);
	fscanf_s(fptr, "%s", businfo.country);
	fscanf_s(fptr, "%s", businfo.startdate);
	fscanf_s(fptr, "%s", businfo.enddate);

	fscanf_s(fptr, "%s", eduinfo.instname);
	fscanf_s(fptr, "%s", eduinfo.instlocation);
	fscanf_s(fptr, "%s", eduinfo.graduationyear);
	fscanf_s(fptr, "%s", eduinfo.fieldofstudy);
	fscanf_s(fptr, "%s", eduinfo.qualification);

	fscanf_s(fptr, "%s", addInfo.language);
	fscanf_s(fptr, "%s", addInfo.accomplishment);
	fscanf_s(fptr, "%s", addInfo.certification);
	fscanf_s(fptr, "%s", addInfo.hobbies);
	fscanf_s(fptr, "%s", addInfo.sports);
	fscanf_s(fptr, "%s", addInfo.extra);

	fclose(fptr);

}
