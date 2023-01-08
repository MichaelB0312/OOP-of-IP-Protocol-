#ifndef PORT_H
#define PORT_H

#include <stddef.h>
#include <iostream>
#include "generic-field.h"

class Port : public GenericField {

	string field; //src or dest
	int port;
	int upper_bound;
	int lower_bound;


public:

	Port(string law); //construct a Port object with default values
	~Port(); // destructor
	String find_field(String law); //find the required field dst or src
	bool set_value(String range); // set the legal values of the range
	bool match(string packet); // checks if the correct field matches the given law

};
