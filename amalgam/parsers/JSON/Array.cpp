#include <amalgam/parsers/JSON/Array.h>
#include <amalgam/parsers/JSON/Value.h>

namespace parser
{

//  ****************************************************************************
class ArrayValue
  : public production
{
protected:
  //  **************************************************************************
  virtual
    bool OnProcess(char_type     token,
      parse_stack  &lexemes);
};



//  ****************************************************************************
class NextValue
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
      lexemes.push(new ArrayValue());
      lexemes.push(new WhiteSpace());
      lexemes.push(new Literal(','));
      break;

    case ']':
      lexemes.push(new Epsilon());
      break;
    default:
      return false;
    }

    return true;
  }
};


//  **************************************************************************
bool ArrayValue::OnProcess( char_type     token,
                            parse_stack  &lexemes)
{
  switch (token)
  {
  case ']':
    lexemes.push(new Epsilon());
    break;
  default:
    lexemes.push(new WhiteSpace());
    lexemes.push(new NextValue());
    lexemes.push(new WhiteSpace());
    lexemes.push(new Value());
  }

  return true;
}


//  ****************************************************************************
bool Array::OnProcess(char_type     token,
                      parse_stack  &lexemes)
{
  switch (token)
  {
  case '[':
    lexemes.push(new WhiteSpace());
    lexemes.push(new Literal(']'));
    lexemes.push(new WhiteSpace());
    lexemes.push(new ArrayValue());
    lexemes.push(new WhiteSpace());
    lexemes.push(new Literal('['));
    break;
  default:
    return false;
  }

  return true;
}

}


