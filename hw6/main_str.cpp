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
	String str5("   Yallla Hapoell!!  ");
	//const char* delimiters = "aHl";
	String *output;
	size_t size;
	str5.split("aHl",&output,&size);
	delete[] output;
	//String str6 = str5.trim();
	int bool1 = str5.equals("   fuck maccabi");
	cout << bool1;

	return 0;
}
