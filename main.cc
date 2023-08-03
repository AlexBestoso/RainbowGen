#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>

char alphabet[27] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
	'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
	'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
	'y', 'z', ' '
};

char permAlphabet[84] = {
	'a', 'A', '@', '4', 			// 0 - 3
	'b', 'B', '8',				// 4 - 6
	'c', 'C', '(',				// 7 - 9
	'd', 'D', ')',				// 10 - 12
	'e', 'E', '3',				// 13 - 15
	'f', 'F',				// 16 - 17
	'g', 'G', '6', '9',			// 18 - 21
	'h', 'H',				// 22 - 23
	'i', 'I', '1', '!', 'l',		// 24 - 28
	'j', 'J', 'L',				// 29  - 31
	'k', 'K', 'c', 'C',			// 32 - 35
	'l', 'L', '1', '|',			// 36 - 39
	'm', 'M',				// 39 - 40
	'n', 'N',				// 41 - 42
	'o', 'O', '0', 'Q',			// 43 - 46
	'p', 'P', '9', 				// 47 - 49
	'q', 'Q', '9',				// 50 - 52
	'r', 'R', '7', 				// 53 - 55
	's', 'S', '$',				// 56 - 58
	't', 'T', '7', '1',			// 59 - 62
	'u', 'U', 'v', 'V',			// 63 - 66
	'v', 'V', 'u', 'U',			// 67 - 70
	'w', 'W',				// 71 - 72
	'x', 'X', '*',				// 73 - 75
	'y', 'Y',				// 76 - 77
	'z', 'Z',				// 78 - 79
	' ', '_', '\0'				// 81 - 83
};

char permMap[27][2] = {
        {0, 3}, // a
        {4, 6}, // b
        {7, 9}, // c
        {10, 12}, // d
        {13, 15}, // e
        {16, 17}, // f
        {18, 21}, // g
        {22, 23}, // h
        {24, 28}, // i 
        {29, 31}, // j
        {32, 35}, // k
        {36, 39}, // l
        {40, 41}, // m
        {42, 43}, // n
        {44, 47}, // o
        {48, 50}, // p
        {51, 53}, // q
        {54, 56}, // q
        {57, 59}, // s
        {60, 63}, // t
        {64, 67}, // u
        {68, 71}, // v
        {72, 73}, // w
        {74, 76}, // x
        {77, 78}, // y
	{79, 80}, // z
	{81, 83}  // {space}
};

int main(int argc, char *argv[]){
	std::string prefix = "";
	std::string postfix = "";
	std::string core = "";
	if(argc < 2 || argc > 4){
		fprintf(stderr, "Usage : %s <targetWord> [<prefix>] [<postfix>]\n\tWrite target word in lower case.\n", argv[0]);
		exit(EXIT_FAILURE);
	}else if(argc == 2){
		core = argv[1];
	}else if(argc == 3){
		core = argv[1];
		prefix = argv[2];
	}else{
		core = argv[1];
		prefix = argv[2];
		postfix = argv[3];
	}

	// Build tracker array.
	size_t max = core.length();
	int *tracker = new int[max];
	int *trackerPos = new int[max];

	// initalize tracker array
	for(int i=0; i<max; i++){
		int letterPos  = 0;
		for(int j=0; j<27; j++){
			if(core[i] == alphabet[j]){
				letterPos = j;
				break;
			}
		}
		tracker[i] = permMap[letterPos][0];
		trackerPos[i] = letterPos;
	}

	while(1){
		printf("%s%s%s\n", prefix.c_str(), core.c_str(), postfix.c_str());

		// check for end condition
		bool done = false;
		for(int i=0; i<max; i++){
			if(tracker[i] == permMap[trackerPos[i]][1]){
				done = true;
			}else{
				done = false;
				break;
			}
		}
		if(done)
			exit(EXIT_SUCCESS);

		// Increment
		for(int i=0; i<max; i++){
			tracker[i]++;
			if(tracker[i] > permMap[trackerPos[i]][1]){
				tracker[i] = permMap[trackerPos[i]][0];
			}else{
				break;
			}
		}

		// update string
		core = "";
		for(int i=0; i<max; i++){
			if(permAlphabet[tracker[i]] == '\0')
				continue;
			core += permAlphabet[tracker[i]];
		}
		
	}
}
