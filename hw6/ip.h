#ifndef IP_H
#define IP_H

#include <stddef.h>
#include <iostream>
#include "generic-field.h"

class IP : public GenericField {

	String ip;
	String law;
	String field; //src or dst

public:


	bool match(String packet);

	/**
	 * @brief Get a single law -> extract the set of valid values
	 * @param[value] Its a single law
	 */
	bool set_value(String value);

	/**
	 * @brief Initiates a IP from a given packet and required-law
	 */
	IP(String packet, String law);

	/**
	 * @brief find the required field dst or src
	 */
	String find_field(String law);
	
	/**
	* @brief split the packet according to bytes and convert the packet to unsigned int
	*/
	unsigned int ip_to_int(String ip);

	/**
	* @brief create a mask according to a given law
	*/
	unsigned int get_mask(String law);

};

















#endif