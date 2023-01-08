#include <iostream>
using namespace std;
#include <string.h>
#include "port.h"


Port::Port(string law) {
	field = find_field(string law);
	port = 0;
	upper_bound = 0;
	lower_bound = 0;
}

port::~port(){}


String Port::find_field(String law) {

	String* src_out;
	size_t src_size;
	string tmp_law
	law.split("src-port", &src_out, &src_size);
	if (src_out[0].trim().data[0] == '=') {
		delete[] src_out;
		return String("src");
	}
	else
	{
		delete[] src_out;
		return String("dst");
	}
}

bool Port::set_value(string range) {
	
	string *splitted_range;
	size_t size;
	//splitting range string "prt-prt"
	range.split("-",&splitted_range, &size)
	if (size != 2) {
		delete[] splitted_range;
		return false;
	}

	lower_bound = splitted_rang[0].trim().to_integer();
	upper_bound = splitted_rang[1].trim().to_integer();

	delete[] splitted_range;
	return true;
}

bool Port::match(string packet) {

	/*extract port from the packet:*/
	//1. divide to fields
	String* out_fields;
	size_t size_fields;
	string tmp_packet = packet.trim();
	tmp_packet.split(",", &out_fields, &size_fields);

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
			port = tmp_out[1].to_intager;
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

