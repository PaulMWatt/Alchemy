#ifndef LITERALS_H_INCLUDED
#define LITERALS_H_INCLUDED

#include <amalgam/parsers/JSON/production.h>


namespace parser
{

//  ****************************************************************************
class NullValue
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case 'n':
      lexemes.push(new Literal('l'));
      lexemes.push(new Literal('l'));
      lexemes.push(new Literal('u'));
      lexemes.push(new Literal('n'));
      break;
    default:
      return false;
    }

    return true;
  }
};


//  ****************************************************************************
class TrueValue
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case 't':
      lexemes.push(new Literal('e'));
      lexemes.push(new Literal('u'));
      lexemes.push(new Literal('r'));
      lexemes.push(new Literal('t'));
      break;
    default:
      return false;
    }

    return true;
  }
};


//  ****************************************************************************
class FalseValue
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case 'f':
      lexemes.push(new Literal('e'));
      lexemes.push(new Literal('s'));
      lexemes.push(new Literal('l'));
      lexemes.push(new Literal('a'));
      lexemes.push(new Literal('f'));
      break;
    default:
      return false;
    }

    return true;
  }
};

} // namespace parser

#endif
