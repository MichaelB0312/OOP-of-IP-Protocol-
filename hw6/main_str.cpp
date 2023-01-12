#include "string.h"
#include <iostream>
using namespace std;
#include <string.h>
#include <bitset>

int main(){
	
	//int n;
	//cin >> n;
	//const char* c = new char[20];
	//c = "  I Love Hapoel   ";
	//String str(c);
	//str = c;
	String lawwww = "src-ip=96.48.24.8/8";
	size_t size;
	String* equ_out;
	lawwww.split("=",&equ_out,&size);
	//const char* delimiters = ".";
	//String *output;
	//size_t size;
	/*packet.split(".", &output,&size);
	unsigned int arr[size];
	for(size_t i=0; i<size ; i++){
		arr[i] = output[i].to_integer();
		bitset<8> point(arr[i]);
	
	}

	unsigned int ip_to_int = 0;
	ip_to_int = arr[0] << 24 | arr[1] << 16 | arr[2] << 8 | arr[3];
	bitset<32> bits(ip_to_int);
	//cout << bits;
	delete[] output;
	*/
	String packet("   dst-ip  =253.145.84.201  ,  src-ip =189.112.138.228,  src-port=53,  dst-port=24607");

	String *out_src;
	size_t size_src;
	packet = packet.trim();
	packet.split(",", &out_src, &size_src);
	for(size_t i = 0; i<size_src; i++){
		out_src[i] = out_src[i].trim();
		String *tmp_out;
		size_t tmp_size;
		out_src[i].split("=",&tmp_out,&tmp_size);
		String s("src-ip");
		if(tmp_out[0].trim().equals(s)){
			tmp_out[1] = tmp_out[1].trim();
			String ip  = tmp_out[1];
			delete[] tmp_out;
			break;
			//now we have situation of: =  19.189.54..
			//String *ip_out;
			//size_t ip_size;
			//tmp_out[0].split("=",&ip_out,&ip_size);
			//cout << ip_out[0].trim();
			//delete[] ip_out;
		}
		delete[] tmp_out;


	}	


	String law("dst-ip    =  189.112.138.228/8");
	law = law.trim();
	//cout << law << endl
	size_t size_law;
	String *out_law;
	law.split("dst-ip", &out_law, &size_law);
	String *intern_out;
	size_t size_intern;
	out_law[0].split(",", &intern_out, &size_intern);
	if(intern_out == NULL){
		cout  << "error";
	}
	unsigned int m = out_law[1].to_integer();
	delete[] out_law;
	
	unsigned int output_law = 0;
	output_law = -1;
	output_law = output_law  << (32-m);
	bitset<32> sbits(output_law);
	cout << sbits;
	//String str6 = str5.trim();
	//int bool1 = str5.equals("   fuck maccabi");

	//String str4("   Hapoel    ");
	//str4 =  str4.trim();
	//cout << bool1;

	return 0;
}
