#pragma once
#include<stdlib.h>
#include "third_page.h"
void storeData(string geninfo[5], string socinfo[4], string businfo[6], string eduinfo[5], string addInfo[6], std::string finalname)
{
	FILE* fptr;
	fptr=fopen("SaveData.txt", "w");
	fprintf(fptr, "\n\n%s\n", finalname);
	fprintf(fptr, "********************************\n");
	fprintf(fptr, "%s\n", geninfo[0]);
	fprintf(fptr, "%s\n", geninfo[1]);
	fprintf(fptr, "%s\n", geninfo[2]);
	fprintf(fptr, "%s\n", geninfo[3]);
	fprintf(fptr, "%s\n\n", geninfo[4]);

	fprintf(fptr, "%s\n", socinfo[0]);
	fprintf(fptr, "%s\n", socinfo[1]);
	fprintf(fptr, "%s\n", socinfo[2]);
	fprintf(fptr, "%s\n\n", socinfo[3]);

	fprintf(fptr, "%s\n", businfo[0]);
	fprintf(fptr, "%s\n", businfo[1]);
	fprintf(fptr, "%s\n", businfo[2]);
	fprintf(fptr, "%s\n", businfo[3]);
	fprintf(fptr, "%s\n", businfo[4]);
	fprintf(fptr, "%s\n\n", businfo[5]);

	fprintf(fptr, "%s\n", eduinfo[0]);
	fprintf(fptr, "%s\n", eduinfo[1]);
	fprintf(fptr, "%s\n", eduinfo[2]);
	fprintf(fptr, "%s\n", eduinfo[3]);
	fprintf(fptr, "%s", eduinfo[4]);

	fprintf(fptr, "%s\n", addInfo[0]);
	fprintf(fptr, "%s\n", addInfo[1]);
	fprintf(fptr, "%s\n", addInfo[2]);
	fprintf(fptr, "%s\n", addInfo[3]);
	fprintf(fptr, "%s\n", addInfo[4]);
	fprintf(fptr, "%s\n", addInfo[5]);

	fprintf(fptr, "********************************\n");
	fclose(fptr);
}
