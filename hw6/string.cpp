#include "string.h"
#include <iostream>
using namespace std;
#include <string.h>

String::String() {
	strcpy(data,"");
	length = 0;
}


String::String(const String& str) {
	length = str.length;
	data = strcpy(new char[length + 1], str.data);
}


String::String(const char* str) {
	length = strlen(str);
	data = strcpy(new char[length + 1], str);
}

String::~String() {
	delete[] data;
}

String& String::operator=(const String& rhs) {
	if (this == &rhs) {
		return *this;
	}
	delete[] data;

	data = strcpy(new char[rhs.length + 1], rhs.data);
	length = rhs.length;
	return *this;
}

String& String::operator=(const char* str) {
	if (this->data == str) {
		return *this;
	}
	delete[] data;

	length = strlen(str);
	data = strcpy(new char[length + 1], str);
	return *this;
}

bool String::equals(const String& rhs) const {
	int cond1=0;
	int cond2=0;
	if (!strcmp(this->data, rhs.data)) {
		cond1 = 1;
	}
	if (this->length == rhs.length) {
		cond2 = 1;
	}

	return cond1 && cond2;
}

bool String::equals(const char *rhs) const {
	int cond1 = 0;
	int cond2 = 0;
	if (!strcmp(this->data, rhs)) {
		cond1 = 1;
	}
	if (this->length == strlen(rhs)) {
		cond2 = 1;
	}
	return cond1 && cond2;

}


void String::split(const char* delimiters, String** output, size_t* size) const {
	
	*size = 0;

	char* original_str = this->data;
	char* partial_str = new char[this->length];
	output = new String*[strlen(delimiters)+1];//+1 for the last delimiter till the end
	int j = 0;
	for (int i = 0; i < strlen(delimiters); i++) {

		while ((j < this->length) && (strcmp(delimiters[i], original_str[j]) != 0)) {
			char ch = original_str[j];
			strncat(partial_str, &ch, 1);
			j++;
		}
		output[i] = partial_str;
		delete partial_str;
		/*missmatch, output is set to NULL, release memory*/
		if (i == 0 && j == this->length) {
			delete[] output;
			exit(1);
		}
		*size = (*size) + 1;
		partial_str = new char[(this->length) - j];
		
	}

	delete partial_str;
	partial_str = new char[(this->length) - j];
	//allocate last sub-string:
	while (j < this->length) {
		char ch = original_str[j];
		strncat(partial_str, &ch, 1);
		j++;
	}
	output[strlen(delimiters) + 1] = partial_str;
	*size = (*size) + 1;
	delete partial_str;

	
}


int String::to_integer() const {

	return atoi(this->data);
}


String String::trim() const {

	String copy_str = this;
	char *tmp = copy_str.data;
	/*remove the prefix whitespace*/
	int flag = 1;
	int curr_len = 0;
	do {
		while (*tmp == ' ' && flag) {
			++tmp;
		}
		flag = 0;
		curr_len++;
		//printf("%c\n",*s);
	} while (*copy_str.data++ = *tmp++);

	/*remove the suffix whitespace*/
	copy_str.length = curr_len - 1;
	char *tmp = copy_str.data + copy_str.length - 1;
	int end_loc = copy_str.length - 1;
	//printf("%c\n",*(d-7));
	while (*tmp == ' ') {
		--tmp;
		--end_loc;

	}

	copy_str.data[end_loc + 1] = '\0';

	return copy_str;
}
