
#include <amalgam/parsers/JSON/Object.h>
#include <amalgam/parsers/JSON/Value.h>

namespace parser
{

//  ****************************************************************************
class Pair
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
    case '\"':
      lexemes.push(new WhiteSpace());
      lexemes.push(new Value());
      lexemes.push(new WhiteSpace());
      lexemes.push(new Literal(':'));
      lexemes.push(new WhiteSpace());
      lexemes.push(new j_String());
      break;
    default:
      return false;
    }

    return true;
  }
};


//  ****************************************************************************
class NextPair
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
    case ',':
      lexemes.push(new WhiteSpace());
      lexemes.push(new NextPair());
      lexemes.push(new WhiteSpace());
      lexemes.push(new Literal(','));
      break;

    case '}':
      lexemes.push(new Epsilon());
      break;
    default:
      lexemes.push(new WhiteSpace());
      lexemes.push(new Pair());
    }

    return true;
  }
};


//  ****************************************************************************
class FirstPair
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
    case '}':
      lexemes.push(new Epsilon());
      break;
    default:
      lexemes.push(new WhiteSpace());
      lexemes.push(new NextPair());
      lexemes.push(new WhiteSpace());
      lexemes.push(new Pair());
    }

    return true;
  }
};


//  ****************************************************************************
bool Object::OnProcess( char_type     token,
                        parse_stack  &lexemes)
{
  switch (token)
  {
  case '{':
    lexemes.push(new WhiteSpace());
    lexemes.push(new Literal('}'));
    lexemes.push(new WhiteSpace());
    lexemes.push(new FirstPair());
    lexemes.push(new WhiteSpace());
    lexemes.push(new Literal('{'));
    break;
  default:
    return false;
  }

  return true;
}


}


