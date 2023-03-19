#pragma once
#include<stdlib.h>
#include "third_page.h"
void generateEduCV(generalinfo geninfo, socialinfo socinfo, jobinfo businfo, educationinfo eduinfo, adlinfo addInfo, string finalname) {
	FILE* fptr;
	fptr=fopen("CVnew", "w");
	fprintf(fptr, "Name: %s %s\n", geninfo.firstname, geninfo.lastname);
	fprintf(fptr, "Date of Birth: %s\n", geninfo.dateofbirth);
	fprintf(fptr, "Nationality: %s\n", geninfo.nationality);
	fprintf(fptr, "Phone: %s\n", socinfo.phone);
	fprintf(fptr, "Email: %s\n\n\n", socinfo.email);

	fprintf(fptr, "EDUCATION\n");
	fprintf(fptr, "----------------\n");
	fprintf(fptr, "Institution: %s\n", eduinfo.instname);
	fprintf(fptr, "Location of Institute: %s\n", eduinfo.instlocation);
	fprintf(fptr, "Graduation Year: %s\n", eduinfo.graduationyear);
	fprintf(fptr, "Field of Study: %s\n", eduinfo.fieldofstudy);
	fprintf(fptr, "Qualification: %s\n\n\n", eduinfo.qualification);

	fprintf(fptr, "WORK EXPERIENCE\n");
	fprintf(fptr, "----------------\n");
	fprintf(fptr, "Name of Company: %s\n", businfo.employer);
	fprintf(fptr, "Designation: %s\n", businfo.jobtitle);
	fprintf(fptr, "Year: %s\n", businfo.enddate);

	fprintf(fptr, "ACTIVITIES AND INTERESTS\n");
	fprintf(fptr, "----------------\n");
	fprintf(fptr, "1) Proficient at languages %s\n", addInfo.language);
	fprintf(fptr, "2) My accomplishments include %s\n", addInfo.accomplishment);
	fprintf(fptr, "3) I have the following certifications : %s\n", addInfo.certification);
	fprintf(fptr, "4) I like to play %s\n", addInfo.sports);
	fprintf(fptr, "5) My hobbies and interests are %s\n", addInfo.hobbies);
	fprintf(fptr, "6) Other things I am interested in %s\n", addInfo.extra);

}