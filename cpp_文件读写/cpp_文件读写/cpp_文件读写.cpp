// cpp_文件读写.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>


using namespace std;


int main()
{	


	//通过二进制方式写文件
	ofstream out;
	out.open("Hello.txt", ios::out|ios::binary);
	if (out.is_open()) {
	out << "This is a line.\n";
	out << "This is another.\n";
	out << "kkk";
	out.close();
	}
	else cout << "未打开";

	const char* filename = "Hello.txt";
	int size;
	char*buffer;
	ifstream in(filename, ios::in | ios::binary | ios::ate);
	size = in.tellg();
	in.seekg(0, ios::beg);

	buffer = new char[size + 1];

	memset(buffer, 0, size + 1);
	in.read(buffer, size);
	in.close();
	cout << buffer;
    return 0;
}

