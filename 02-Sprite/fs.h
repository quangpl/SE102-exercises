#pragma once

using namespace std;

/*
	File system
*/
class CFile
{

	string path;

public:
	CFile(string path);
	void read();
};