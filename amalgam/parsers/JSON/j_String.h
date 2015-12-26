#ifndef J_STRING_H_INCLUDED
#define J_STRING_H_INCLUDED

#include <amalgam/parsers/JSON/production.h>

namespace parser
{

//  ****************************************************************************
class HexDigits
  : public production
{
protected:
  virtual
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'a':
    case 'A':
    case 'b':
    case 'B':
    case 'c':
    case 'C':
    case 'd':
    case 'D':
    case 'e':
    case 'E':
    case 'f':
    case 'F':
      lexemes.push(new Literal(token));
      break;
    default:
      return false;
    }
    return true;
  }
};


//  ****************************************************************************
class Escaped
  : public production
{
protected:
  virtual
    bool OnProcess(char_type     token,
      parse_stack  &lexemes)
  {
    switch (token)
    {
    case '\\':
    case '/':
    case '"':
    case 'b':
    case 'f':
    case 'n':
    case 'r':
    case 't':
      lexemes.push(new Literal(token));
      break;

    case 'u':
      lexemes.push(new HexDigits());
      lexemes.push(new HexDigits());
      lexemes.push(new HexDigits());
      lexemes.push(new HexDigits());
      lexemes.push(new Literal('u'));
      break;

    default:
      return false;
    }

    return true;
  }
};

//  ****************************************************************************
class Characters
  : public production
{
protected:
  virtual
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    if (token == '\\')
    {
      lexemes.push(new Characters());
      lexemes.push(new Escaped());
      lexemes.push(new Literal('\\'));
    }
    else if (token == '\"')
    {
      lexemes.push(new Epsilon());
    }
    else if (token >= ' '
      && token <= 255)
    {
      lexemes.push(new Characters());
      lexemes.push(new Literal(token));
    }
    else
    {
      return false;
    }

    return true;
  }
};

//  ****************************************************************************
class j_String
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    // TODO: This string parsing production will require much work to deal with character encoding.
    //       For now it simply supports the lower range of ASCII values without escape characters.

    switch (token)
    {
    case '\"':
      lexemes.push(new Literal('\"'));
      lexemes.push(new Characters());
      lexemes.push(new Literal('\"'));
      break;
    default:
      return false;
    }
    
    return true;
  }
};


}

#endif
