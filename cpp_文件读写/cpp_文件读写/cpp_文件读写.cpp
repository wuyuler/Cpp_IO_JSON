// cpp_文件读写.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>

#include"cJSON.h"


using namespace std;


//cJSON的结构体
//typedef struct cJSON {
//	struct cJSON *next, *prev;
//	struct cJSON *child;
//	int type;
//	char *valuestring;
//	int valueint;
//	double valuedouble;
//	char *string;
//} cJSON;
int main()
{	


	////通过二进制方式写文件
	//ofstream out;
	//out.open("Hello.txt", ios::out|ios::binary);
	//if (out.is_open()) {
	//out << "This is a line.\n";
	//out << "This is another.\n";
	//out << "kkk";
	//out.close();
	//}
	//else cout << "未打开";

	//const char* filename = "Hello.txt";
	//int size;
	//char*buffer;
	//ifstream in(filename, ios::in | ios::binary | ios::ate);
	//size = in.tellg();
	//in.seekg(0, ios::beg);

	//buffer = new char[size + 1];

	//memset(buffer, 0, size + 1);
	//in.read(buffer, size);
	//in.close();
	//cout << buffer;


	//cJSON *user;
	//user = cJSON_CreateObject();//创建根数据对象
	//cJSON_AddStringToObject(user, "name", "tangyonjin");//加键值加字符串
	//cJSON_AddStringToObject(user, "passwd", "123");
	//cJSON_AddNumberToObject(user, "num", 1);//加整数
	//char*out = cJSON_Print(user);//将json形式打印成正常字符串格式
	//cout << out;
	//cJSON_Delete(user);
	
	//创建数组
	/*cJSON*root;
	root = cJSON_CreateArray();
	cJSON_AddItemToArray(root, cJSON_CreateString("HelloWorld"));
	cJSON_AddItemToArray(root, cJSON_CreateNumber(10));
	char *s = cJSON_Print(root);
	cout << s<<endl;*/

	//对象里包含一个数组,数组里包含对象,对象里在添加字符串和文字
	/*cJSON*root3, *js_body, *js_list;
	root3 = cJSON_CreateObject();
	cJSON_AddItemToObject(root3, "body", js_body = cJSON_CreateArray());
	cJSON_AddItemToArray(js_body, js_list = cJSON_CreateObject());
	cJSON_AddStringToObject(js_list, "name", "yjt");
	cJSON_AddNumberToObject(js_list, "status", 100);
	char*s3 = cJSON_Print(root3);
	cout << s3<<endl;*/

	/*ofstream fout;
	fout.open("myJson.txt", ios::out);
	if (fout.is_open()) {
		fout << s3;
		fout.close();
	}
	else
	{
		cout << "未打开文件";
	}*/
	ifstream fin;
	char* myJson;
	fin.open("myJson.txt", ios::in | ios::ate);
	long size = fin.tellg();
	fin.seekg(ios::beg);
	myJson = new char[size + 1];
	memset(myJson, 0, size + 1);
	fin.read(myJson, size);
	//cout << myJson<<endl;

	cJSON *json, *json_body, *json_list,*json_name, *json_status;
	json = cJSON_Parse(myJson);
	json_body = cJSON_GetObjectItem(json,"body");
	json_list = cJSON_GetArrayItem(json_body, 0);
	json_name = cJSON_GetObjectItem(json_list,"name");
	json_status = cJSON_GetObjectItem(json_list, "status");

	cout << json_name->valuestring << json_status->valueint;
















    return 0;
}

