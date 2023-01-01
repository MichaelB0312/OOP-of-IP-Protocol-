#include "string.h"
#include <iostream>
using namespace std;
#include <string.h>

String::String() {
	data = '\0';
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
	if (this->length == strlen(rhs) {
		cond2 = 1;
	}
	return cond1 && cond2;

}


void String::split(const char* delimiters, String** output, size_t* size) const {
	
	// Make a copy of the delimiter string
	size_t delimiters_length = strlen(delimiters);
	char delimiters_copy[delimiters_length + 1];
	strcpy(delimiters_copy, delimiters);

	// Replace the first delimiter character with a null character
	delimiters_copy[0] = '\0';

	// Count the number of substrings
	char* token = std::strtok(data, delimiters_copy);
	*size = 0;
	while (token != nullptr) {
		++(*size);
		token = std::strtok(nullptr, delimiters_copy);
	}

	// Allocate memory for the output array if requested
	if (output != nullptr) {
		*output = new String[*size];
	}

	// Populate the output array with the substrings
	token = std::strtok(data, delimiters_copy);
	size_t i = 0;
	while (token != nullptr) {
		if (output != nullptr) {
			(*output)[i] = String(token);
		}
		++i;
		token = std::strtok(nullptr, delimiters_copy);
	}

	
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