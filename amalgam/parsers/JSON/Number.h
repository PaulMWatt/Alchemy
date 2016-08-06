#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include <amalgam/parsers/JSON/production.h>


namespace parser
{

//  Forward Declarations *******************************************************
class Number;
class Prefix;
class Fractional;
class Sign;
class M;
class Zero;
class Digits;
class Exponent;
class ExpValue;


//  ****************************************************************************
class Zero
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    bool retVal = false;
    if (token == '0')
    {
      lexemes.push(new Literal('0'));        
      retVal = true;
    }
    
    return retVal;
  }
};


//  ****************************************************************************
class Digits
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch(token)
    {
    case '0':
      lexemes.push(new Zero());
      break;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      // Note: Non-zero production has been 
      //       reduced to this single operation.
      lexemes.push(new Literal(token));
      break;
    default:
      return false;
    }
    return true;
  }
};


//  ****************************************************************************
class M
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch(token)
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
      lexemes.push(new M());
      lexemes.push(new Digits());
      break;

    case '\0':
    case '.':
    default:
      lexemes.push(new Epsilon());
      break;
    }
    return true;
  }
};


//  ****************************************************************************
class ExpValue
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case '+':
      lexemes.push(new M());
      lexemes.push(new Literal('+'));
      break;
    case '-':
      lexemes.push(new M());
      lexemes.push(new Literal('-'));
      break;
    case '\0':
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
      lexemes.push(new M());
      break;
    default:
      return false;
    }

    return true;
  }
};


//  ****************************************************************************
class Exponent
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case 'e':
    case 'E':
      lexemes.push(new ExpValue());
      lexemes.push(new Literal(token));
      break;
    default:
      lexemes.push(new Epsilon());
    }

    return true;
  }
};


//  ****************************************************************************
class Fractional
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case '.':
      lexemes.push(new Exponent());
      lexemes.push(new M());
      lexemes.push(new Literal('.'));
      break;
    default:
      lexemes.push(new Epsilon());
    }

    return true;
  }

};

//  ****************************************************************************
class Sign
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case '-':
      lexemes.push(new M());
      lexemes.push(new Literal('-'));
      break;
    default:
      return false;
    }

    return true;
  }

};


//  ****************************************************************************
class Prefix
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case '-':
      lexemes.push(new Sign());
      break;
    case '0':
      lexemes.push(new Zero());
      break;
    default:
      return false;
    }

    return true;
  }
};


//  ****************************************************************************
class Number 
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    switch (token)
    {
    case '-':
      lexemes.push(new Fractional());
      lexemes.push(new Prefix());
      break;
    case '0':
      lexemes.push(new Fractional());
      lexemes.push(new Prefix());
      break;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      lexemes.push(new Fractional());
      lexemes.push(new M());
      break;
    default:
      return false;
    }

    return true;
  }
};


}

#endif


