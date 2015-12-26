#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <amalgam/parsers/JSON/production.h>

namespace parser
{

//  ****************************************************************************
class Array
  : public production
{
protected:
  virtual
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes);
};

}

#endif
