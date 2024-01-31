#include <stdio.h>
#include <stdint.h>

const char ASCII_TABLE[] = {
	'\0', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\a',
	'\b', '\t', '\n', '\x0B', '\f', '\r', '\x0E', '\x0F',
	'\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
	'\x18', '\x19', '\x1A', '\x1B', '\x1C', '\x1D', '\x1E', '\x1F',
	' ', '!', '"', '#', '$', '%', '&', '\'',
	'(', ')', '*', '+', ',', '-', '.', '/',
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', ':', ';', '<', '=', '>', '?',
	'@', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
	'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
	'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
	'`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
	'x', 'y', 'z', '{', '|', '}', '~', '\x7F',
	'\x80', '\x81', '\x82', '\x83', '\x84', '\x85', '\x86', '\x87',
	'\x88', '\x89', '\x8A', '\x8B', '\x8C', '\x8D', '\x8E', '\x8F',
	'\x90', '\x91', '\x92', '\x93', '\x94', '\x95', '\x96', '\x97',
	'\x98', '\x99', '\x9A', '\x9B', '\x9C', '\x9D', '\x9E', '\x9F',
	'\xA0', '\xA1', '\xA2', '\xA3', '\xA4', '\xA5', '\xA6', '\xA7',
	'\xA8', '\xA9', '\xAA', '\xAB', '\xAC', '\xAD', '\xAE', '\xAF',
	'\xB0', '\xB1', '\xB2', '\xB3', '\xB4', '\xB5', '\xB6', '\xB7',
	'\xB8', '\xB9', '\xBA', '\xBB', '\xBC', '\xBD', '\xBE', '\xBF',
	'\xC0', '\xC1', '\xC2', '\xC3', '\xC4', '\xC5', '\xC6', '\xC7',
	'\xC8', '\xC9', '\xCA', '\xCB', '\xCC', '\xCD', '\xCE', '\xCF',
	'\xD0', '\xD1', '\xD2', '\xD3', '\xD4', '\xD5', '\xD6', '\xD7',
	'\xD8', '\xD9', '\xDA', '\xDB', '\xDC', '\xDD', '\xDE', '\xDF',
	'\xE0', '\xE1', '\xE2', '\xE3', '\xE4', '\xE5', '\xE6', '\xE7',
	'\xE8', '\xE9', '\xEA', '\xEB', '\xEC', '\xED', '\xEE', '\xEF',
	'\xF0', '\xF1', '\xF2', '\xF3', '\xF4', '\xF5', '\xF6', '\xF7',
	'\xF8', '\xF9', '\xFA', '\xFB', '\xFC', '\xFD', '\xFE', '\xFF'
};

char secret_array[] = { 'y', 'o', 'u', 'r', '.', 's', 'e', 'c', 'r', 'e', 't', '\0' };

const char *SECRET_POINTER = "YOUR.SECRET";

int main()
{
	//uint8_t your_secret_index_array[] = { 89, 111, 117, 114, 46, 83, 101, 99, 114, 101, 116 }; // Your.Secret
	int your_secret_index_array[] = { 89, 111, 117, 114, 46, 83, 101, 99, 114, 101, 116 };
	/* Do not use uint8_t to declare your_secret_index_array[], as it is equivalent to char[],
	   and the members (index) inside can be referenced to obtain strings through ASCII_TABLE[].

	   Intelligent GCC compilers may directly replace it at compile time 
	   (test results show that GCC under arm64 will replace it, while on Ubuntu it will not).
	   This allows extracting 'secret keywords' from binaries using the 'strings' command in the arm64 environment.
	 */

	size_t array_length = sizeof(your_secret_index_array) / sizeof(your_secret_index_array[0]);
	char buf[array_length + 1];

	snprintf(buf, sizeof(buf), "%c%c%c%c%c%c%c%c%c%c%c%c",
			 ASCII_TABLE[your_secret_index_array[0]],
			 ASCII_TABLE[your_secret_index_array[1]],
			 ASCII_TABLE[your_secret_index_array[2]],
			 ASCII_TABLE[your_secret_index_array[3]],
			 ASCII_TABLE[your_secret_index_array[4]],
			 ASCII_TABLE[your_secret_index_array[5]],
			 ASCII_TABLE[your_secret_index_array[6]],
			 ASCII_TABLE[your_secret_index_array[7]],
			 ASCII_TABLE[your_secret_index_array[8]],
			 ASCII_TABLE[your_secret_index_array[9]],
			 ASCII_TABLE[your_secret_index_array[10]], 
			 ASCII_TABLE[your_secret_index_array[11]]
		);

	printf("Decoded string: %s\n", buf);

	printf("secret_array: %s\n", secret_array);
	printf("SECRET_POINTER: %s\n", SECRET_POINTER);
	return 0;
}
