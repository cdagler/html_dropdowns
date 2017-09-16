// FIle Name: html_dropdown.cpp
//
// Author: Clay Dagler (cdagler@egusd.net)

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
const int MAX_NUM_LINES = 10000;

class HTML_Dropdown
{
public:
	HTML_Dropdown();
	void readInLines(void);
	void outputToHtml(void);

private:
	static const bool debug = true;
	int numOfTabs[MAX_NUM_LINES];
	string content[MAX_NUM_LINES];
	int numOfLines;
};

HTML_Dropdown::HTML_Dropdown()
{
	if(debug)
		cout << "Let's get it started." << endl << endl;

	numOfLines = 0;
}

void HTML_Dropdown::readInLines(void)
{
	if(debug)
		cout << "Reading in the lines from cin." << endl << endl;

	string currentLine;
	int i=0;

	while(getline(cin, currentLine))
	{
		for(i=0; currentLine[i]==','; i++)
			;
		numOfTabs[numOfLines]=i;
		content[numOfLines]=currentLine.substr(i,currentLine.size()-i);
		numOfLines++;
		if(numOfLines >=MAX_NUM_LINES)
		{
			cout << "\aI can not handle more then 10000 lines." << endl;
			exit(EXIT_FAILURE);
		}
	}
}

void HTML_Dropdown::outputToHtml(void)
{
	if(debug)
		cout << "Writting out the html to cout." << endl << endl;

	for(int i=0; i<numOfLines; i++)
		cout << numOfTabs[i] << ": " << content[i] << endl;
}

int main()
{
	HTML_Dropdown html_dropdown;
	html_dropdown.readInLines();
	html_dropdown.outputToHtml();

	return 0;
}
