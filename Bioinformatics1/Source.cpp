#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
	ifstream imfile;
	imfile.open("file.txt");
	string text;
	string pattern;
	if (!imfile.is_open())
	cout << "Cannot open'file.txt'";
	
	else
	{

			getline(imfile, text);
			cout << text << endl;
			getline(imfile, pattern);
			cout << pattern << endl;

	}

	int count=0;
	int position = 0;
	
	while (text.find(pattern,position) != string::npos)
	{
		position = text.find(pattern, position)+1;
		cout << "Include position: " << position << endl;
		count++;
	}
	cout << "Count: "<< count << endl;



	ofstream exfile;
	exfile.open("file2.txt");
	exfile << text;


	imfile.close();
	exfile.close();
}