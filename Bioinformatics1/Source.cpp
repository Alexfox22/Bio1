#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int PatternCount(string text, string pattern)
{
	int count = 0;
	int position = 0;

	while (text.find(pattern, position) != string::npos)
	{
		position = text.find(pattern, position) + 1;
		count++;
	}
	return count;
}
string FreqentWords(string text,int count)
{
	string result;
	string pattern;
	int n = text.size();
	int *mas = new int[n];
	int max=-10000;
	for (int i = 0;i < n - count + 1;i++)
	{
		pattern = text.substr(i, count);
		mas[i] = PatternCount(text, pattern);
		if (mas[i] > max) 
			max = mas[i];
	}
	for (int i = 0;i < n - count + 1;i++)
	{
		if (mas[i] == max)
		{
			
			if (PatternCount(result, text.substr(i, count)) == 0)
			{
				result = result + text.substr(i, count) + ' ';
			}

			else
			{
				int r = text.find(text.substr(i, count));
				result.erase(r, count + 1);
				result = result + text.substr(i, count) + ' ';

			}
		}
	}
	return result;
}
void main()
{
	int menu=-2;
	bool tried = false;
	ifstream imfile;
	imfile.open("input.txt");
	string text;
	string res;
	cout << "Press '0' to find pattern count " << endl;
	cout << "Press '1' to find freqen words " << endl;
	while ((menu != 0) && (menu != 1))
	{ 
		if (tried==true)
		{
			cout << "Wrong value. Please, press '0' or '1' " << endl;
		}
		cin >> menu;
		tried = true;
	}
	if (menu == 0)
	{
		string pattern;
		if (!imfile.is_open())
			cout << "Cannot open'input.txt'";
		else
		{
			getline(imfile, text);
			getline(imfile, pattern);
		}
		res = PatternCount(text, pattern);
		ofstream exfile;
		exfile.open("file2.txt");
		exfile << res;
	}
	if (menu == 1)
	{
		string count;

		if (!imfile.is_open())
			cout << "Cannot open'input.txt'";
		else
		{
			getline(imfile, text);
			getline(imfile, count);
		}
		res = FreqentWords(text, stoi(count));
	}
	ofstream exfile;
	exfile.open("output.txt");
	exfile << res;

	imfile.close();
	exfile.close();
}