#include "string.h"
#include <iostream>
using namespace std;
#include <string.h>

String::String() {
	data = new char[1];
	data[0] = '\0';
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


/*void String::split(const char* delimiters, String** output, size_t* size) const {
	
	// Make a copy of the delimiter string
	size_t delimiters_length = strlen(delimiters);
	char delimiters_copy[delimiters_length + 1];
	strcpy(delimiters_copy, delimiters);

	// Replace the first delimiter character with a null character
	delimiters_copy[0] = '\0';

	// Count the number of substrings
	char* token = strtok(data, delimiters_copy);
	*size = 0;
	while (token != nullptr) {
		++(*size);
		token = strtok(nullptr, delimiters_copy);
	}

	// Allocate memory for the output array if requested
	if (output != nullptr) {
		*output = new String[*size];
	}

	// Populate the output array with the substrings
	token = strtok(data, delimiters_copy);
	size_t i = 0;
	while (token != nullptr) {
		if (output != nullptr) {
			(*output)[i] = String(token);
		}
		++i;
		token = strtok(nullptr, delimiters_copy);
	}

	
}*/

/*void String::split(const char* delimiters, String** output, size_t* size) const {
	// Initialize the output array and size variable
	*size = 0;
	////output = NULL;

	// Check if the input string is empty
	if (length == 0) {
		return;
	}

	// Calculate the length of the delimiters string
	size_t delimiters_length = strlen(delimiters);

	// Start and end indices for the current substring
	size_t start = 0, end = 0;

	// Allocate initial memory for the output array
	*size = delimiters_length;
	*output = new String[*size + 1 ]; //+1 for the last delimiter till the end
	size_t i = 0;

	// Iterate through the delimiters
	for (size_t j = 0; j < delimiters_length; j++) {
		// Check if the current character is a delimiter
		bool is_delimiter = false;

		while (i < length) {
			if (data[i] == delimiters[j]) {
				is_delimiter = true;
				break;
			}
			i++;
		}

		// If the current character is a delimiter, split the string
		if (is_delimiter) {
			end = i;
			char* substring = new char[(end - start) + 1];
			strncpy(substring, data + start,end-start);
			output[j] = new String(substring);
			start = i + 1;
			i = i + 1;
			delete[] substring;
			
		}
	}

	// Add the final substring to the list
	end = length;
	char* substring = new char[(end - start) + 1];
	strncpy(substring, data + start, end - start);
	output[delimiters_length] = new String(substring);
	delete[] substring;
	

}*/

/*void String::split(const char* delimiters, String** output, size_t* size) const {
  // Make a copy of the string and a copy of the delimiters
  char *str = strdup(data);
  char *delims = strdup(delimiters);

  // Initialize the output array and the size
  *size = 0;
  *output = new String[strlen(delimiters) + 1];

  // Tokenize the string
  char *token = strtok(str, delims);
  while (token != NULL) {
    // Initialize the new token
    (*output)[*size] = token;
    (*size)++;

    // Get the next token
    token = strtok(NULL, delims);
  }

  // Free the copies of the string and delimiters
  free(str);
  free(delims);
}*/

void String::split(const char* delimiters, String** output, size_t* size) const {
  // Make a copy of the string and a copy of the delimiters
  char *str = strdup(data);
  char *delims = strdup(delimiters);

  // Initialize the output array and the size
  *size = 0;
  *output = NULL;

  // Tokenize the string
  char *token = strtok(str, delims);
  while (token != NULL) {
    // Allocate memory for the new token
    if (*output == NULL) {
      *output = new String[1];
	}
	else {
		String* new_output = new String[*size + 1];

		// reallocating:
		for (size_t i = 0; i < *size; i++) {
			new_output[i] = (*output)[i];
		}

		// delete the old array and update new
		delete[] * output;
		*output = new_output;
	}

    // Initialize the new token
    (*output)[*size] = token;
    (*size)++;

    // Get the next token
    token = strtok(NULL, delims);
  }

  // Free the copies of the string and delimiters
  free(str);
  free(delims);
}


int String::to_integer() const {

	return atoi(this->data);
}


/*String String::trim() const {

	String copy_str;
	strcpy(copy_str.data,this->data);
	char *tmp = copy_str.data;
	//remove the prefix whitespace
	int flag = 1;
	int curr_len = 0;
	do {
		while (*tmp == ' ' && flag) {
			++tmp;
		}
		flag = 0;
		curr_len++;
		//printf("%c\n",*s);
	} while ((*copy_str.data++ = *tmp++));

	//remove the suffix whitespace/
	copy_str.length = curr_len - 1;
	tmp = copy_str.data + copy_str.length - 1;
	int end_loc = copy_str.length - 1;
	//printf("%c\n",*(d-7));
	while (*tmp == ' ') {
		--tmp;
		--end_loc;

	}

	copy_str.data[end_loc + 1] = '\0';
	copy_str.length = end_loc;

	return copy_str;
}*/

String String::trim() const {
  // Find the first non-whitespace character
  size_t start = 0;
  //String cpy_str;
  //strcpy(cpy_str.data,this->data);
  //char *copy_str = cpy_str.data;
	 
  while (start < length && data[start] == ' ') {
    start++;
  }

  // Find the last non-whitespace character
  size_t end = length - 1;
  while (end > start && data[end] == ' ') {
    end--;
  }

  //delete[] cpy_str;

  // Create a new string and copy the relevant part of the original string to it
  char *cpy_str = new char[end - start + 2];
  memcpy(cpy_str, data + start, end - start + 1);
  cpy_str[end - start + 1] = '\0';
  String result(cpy_str);
  delete[] cpy_str;
  return result;
}

