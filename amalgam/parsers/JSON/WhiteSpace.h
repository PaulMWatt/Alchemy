#ifndef WHITESPACE_H_INCLUDED
#define WHITESPACE_H_INCLUDED

#include <amalgam/parsers/JSON/production.h>


namespace parser
{

//  ****************************************************************************
class WhiteSpace
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case '\r':
    case '\n':
    case '\b':
    case '\t':
    case ' ':
      lexemes.push(new WhiteSpace());
      lexemes.push(new Literal(token));
      break;
    }

    return true;
  }
};


}

#endif
