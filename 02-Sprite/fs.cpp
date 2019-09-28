#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#pragma warning (disable : 4996)

#include <fstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class CFile {

	string path;
	string data;

public:

	CFile(string p) {
		path = p;
	}

	void read()
	{
		ifstream fin(this->path);
		string content{ std::istreambuf_iterator<char>{fin}, {} }; 
		this->data = content;
	}

	string getData() {
		return this->data;
	}

	vector<string> split() {
		vector<string> arr;
		std::istringstream ss(this->data);
		std::string token;

		while (std::getline(ss, token, ',')) {
			std::cout << token << '\n';
			arr.push_back(token);
		}
		return arr;
	}

};

