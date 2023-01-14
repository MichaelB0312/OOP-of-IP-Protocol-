#include <iostream>
using namespace std;
#include <string.h>
#include "port.h"
#define CORRECT_SIZE 2

Port::Port(String law) {
	field = find_field(law);
	port = 0;
	upper_bound = 0;
	lower_bound = 0;
}

Port::~Port(){}


String Port::find_field(String law) {

	String* src_out;
	size_t src_size;
	law.split("src-port", &src_out, &src_size);
	if (src_out[0].trim().equals("=")) {
		delete[] src_out;
		return String("src");
	}
	else
	{
		delete[] src_out;
		return String("dst");
	}
}

bool Port::set_value(String range) {
	
	String *splitted_range;
	size_t size;
	//splitting range string "prt-prt"
	range.split("-",&splitted_range, &size);
	if (size != CORRECT_SIZE) {
		delete[] splitted_range;
		return false;
	}

	lower_bound = splitted_range[0].trim().to_integer();
	upper_bound = splitted_range[1].trim().to_integer();

	delete[] splitted_range;
	return true;
}

bool Port::match(String packet) {

	/*extract port from the packet:*/
	//1. divide to fields
	String* out_fields;
	size_t size_fields;
	String tmp_packet = packet.trim();
	tmp_packet.split(",", &out_fields, &size_fields);
	
	if (size_fields != 0) { //i.e. we have more than one field
	//2. divide each field according to '='
	for (size_t i = 0; i < size_fields; i++) {

		out_fields[i] = out_fields[i].trim();
		String* tmp_out;
		size_t tmp_size;
		out_fields[i].split("=", &tmp_out, &tmp_size);

		//3.identify the corret port according to field
		if (tmp_out[0].trim().equals(field)) {
			//4.then the second sub-field is the port!
			tmp_out[1] = tmp_out[1].trim();
			port = tmp_out[1].to_integer();
			delete[] tmp_out;
			break;
		}
		delete[] tmp_out;
	}

	delete[] out_fields;

	//match check
	if (port < lower_bound || port > upper_bound) {
		return false;
	}
	return true;
}


int Port::equ_sep(String single_field) {
	String* single_out;
	size_t single_size;
	int port_extern;
	single_field.split("=", &single_out, &single_size);
	//field is left to "="
	if (single_out[0].trim().equals(field)) {
		//then the second sub-field is the port!
		single_out[1] = single_out[1].trim();
		port_extern = single_out[1].to_integer();
		delete[] single_out;
	}
	else
	{
		port_extern = 0;
	}

	return port_extern;
}

