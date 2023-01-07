#ifndef IP_H
#define IP_H

#include <stddef.h>
#include <iostream>
#include "generic-field.h"

class IP : public GenericField {


public:

	bool match(String packet);
	bool set_value(String value);


};

















#endif