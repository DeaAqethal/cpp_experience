#include <iostream>
using namespace std;
/*
	参考 more effective c++条款8
	new operator 分为 三步：
	1.通过operator new(malloc)分配内存
	2.通过placement new构造对象
	3.将原始内存指针转换为相应类型的指针


	delete operator相反
*/
int main() {
	void* rawMemory = operator new(sizeof("hello world!"));//operator new分配内存
	rawMemory = new(rawMemory)string("hello world!");//placement new构造对象
	string* ps = static_cast<string*>(rawMemory);//将原始内存指针转换为字符串指针

	ps->~basic_string();//字符串析构
	ps = NULL;//防止野指针
	delete rawMemory;//防止内存泄漏
}