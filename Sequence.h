#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>

class Sequence
{
public:
	Sequence(std::string);
	int length();
	int numberOf(char);
	std::string longestConsecutive();
	std::string longestRepeated();
private:
	std::string line;
};

#endif
