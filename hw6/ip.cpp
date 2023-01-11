#include <iostream>
using namespace std;
#include <string.h>
#include "ip.h"


IP::IP(String packet, String law) {
	
	law = law.trim();
	//find type of field from the law
	field = find_field(law);
	
	/*extract the IP from the packet:*/
	//1. divide to fields
	String* out_fields;
	size_t size_fields;
	packet.split(",", &out_fields, &size_fields);

	//2. divide each field according to '='
	for (size_t i = 0; i < size_fields; i++) {

		out_fields[i] = out_fields[i].trim();
		String* tmp_out; size_t tmp_size;
		out_fields[i].split("=", &tmp_out, &tmp_size);
		
		//3.identify the corret ip according to field
		if (tmp_out[0].trim().equals(field)) {
			//4.then the second sub-field is the ip!
			tmp_out[1] = tmp_out[1].trim();
			ip = tmp_out[1];
			delete[] tmp_out;
			break;
		}
		delete[] tmp_out;
	}
	
	delete[] out_fields;


}

String IP::find_field(String law) {

	String* src_out;
	size_t src_size;
	law.split("src-ip", &src_out, &src_size);
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

bool IP::set_value(String value) {

	//find the required values using split with delimiters "/". use to_integer() for getting the value

	//now we'll use get_mask from the sadna

	//if(this->ip_to_int(char a,b,c,d)

}


bool IP::match(String packet) {

	//first, split the packet according to "," 


	if (this->set_value(String value)) {

	}
}


unsigned int IP::ip_to_int(String ip) {

	String* out;
	size_t size;
	ip.split(".", out, size);
	unsigned int arr[size];
	for (size_t i = 0; i < size; i++) {
		arr[i] = out[i].to_integer();
	}

	unsigned int ip_int;
	ip_int = arr[0] << 24 | arr[1] << 16 | arr[2] << 8 | arr[3];
	delete[] out;

	return ip_int;
}


unsigned int IP::get_mask(String law) {

	//extarct the length of mask
	size_t size;
	String* out_str;
	law.split("/", &out_str, size);
	int m = out_str[1].to_integer();
	delete[] out_str;

	// create the mask
	unsigned int out = 0;
	out = -1;
	out = out << (32 - m);

	return out;
}
