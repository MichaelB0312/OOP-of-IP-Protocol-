#include "string.h"
#include <iostream>
using namespace std;
#include <string.h>

int main(){
	
	//int n;
	//cin >> n;
	//const char* c = new char[20];
	//c = "  I Love Hapoel   ";
	//String str(c);
	//str = c;
	String str5("245.197.45.445.78 ");
	//const char* delimiters = ".";
	String *output;
	size_t size;
	str5.split(".", &output,&size);
	delete[] output;
	//String str6 = str5.trim();
	int bool1 = str5.equals("   fuck maccabi");

	String str4("   Hapoel    ");
	str4 =  str4.trim();
	cout << bool1;

	return 0;
}
