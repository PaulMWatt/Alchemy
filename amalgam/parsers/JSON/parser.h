#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <amalgam/parsers/JSON/production.h>

#include <vector>

namespace parser
{


//  ****************************************************************************
class Parser
{
public:
	bool parse(const std::vector<char>& input);
	bool parse(char const* input, size_t length);

private:
	parse_stack    m_lexemes;
};




}

#endif
