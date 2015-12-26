#ifndef VALUE_H_INCLUDED
#define VALUE_H_INCLUDED

#include <amalgam/parsers/JSON/production.h>
#include <amalgam/parsers/JSON/WhiteSpace.h>
#include <amalgam/parsers/JSON/Value.h>
#include <amalgam/parsers/JSON/Object.h>
#include <amalgam/parsers/JSON/Array.h>
#include <amalgam/parsers/JSON/j_String.h>
#include <amalgam/parsers/JSON/Number.h>
#include <amalgam/parsers/JSON/Literals.h>

namespace parser
{

//  ****************************************************************************
class Value 
  : public production
{
protected:
  //  **************************************************************************
  virtual
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case '{':
      lexemes.push(new WhiteSpace());
      lexemes.push(new Object());
      lexemes.push(new WhiteSpace());
      break;
    case '[':
      lexemes.push(new WhiteSpace());
      lexemes.push(new Array());
      lexemes.push(new WhiteSpace());
      break;
    case '\"':
      lexemes.push(new WhiteSpace());
      lexemes.push(new j_String());
      lexemes.push(new WhiteSpace());
      break;
    case 'f':
      lexemes.push(new WhiteSpace());
      lexemes.push(new FalseValue());
      lexemes.push(new WhiteSpace());
      break;
    case 'n':
      lexemes.push(new WhiteSpace());
      lexemes.push(new NullValue());
      lexemes.push(new WhiteSpace());
      break;
    case 't':
      lexemes.push(new WhiteSpace());
      lexemes.push(new TrueValue());
      lexemes.push(new WhiteSpace());
      break;
    default:
      lexemes.push(new WhiteSpace());
      lexemes.push(new Number());
      lexemes.push(new WhiteSpace());
    }

    return true;
  }

};


} // namespace parser

#endif
