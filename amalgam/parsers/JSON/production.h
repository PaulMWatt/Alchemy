#ifndef PRODUCTION_H_INCLUDED
#define PRODUCTION_H_INCLUDED

#include <stack>

namespace parser
{

// Forward Declarations ********************************************************
class production;

typedef char                    char_type;
typedef std::stack<production*> parse_stack; 

//  ****************************************************************************
class production
{
public:
  production()
    : m_token('\0')
    , m_terminator(false)
  { }

  production(bool is_terminator)
    : m_token('\0')
    , m_terminator(is_terminator)
  { }

  production(char_type token)
    : m_token(token)
    , m_terminator(false)
  { }

  bool process( char_type     token,
                parse_stack  &lexemes)
  {
    return OnProcess(token, lexemes);
  }

  char_type Token()
  {
    return m_token;
  }

  bool is_terminator()
  {
    return m_terminator;
  }

  bool is_advance()
  {
    return Token() != '\0';
  }

protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &lexemes)
  {
    return true;
  }

private:
  const char_type m_token;

  bool  m_terminator;
};


//  ****************************************************************************
class Literal
  : public production
{
public:
  Literal(char_type token)
    : production(token)
  { }

protected:
  virtual 
    bool OnProcess( char_type     token,
                    parse_stack  &/*lexemes*/)
  {
    return token == Token();
  }
};

//  ****************************************************************************
class Epsilon
  : public production
{
protected:
  virtual 
    bool OnProcess( char_type     /*token  */,
                    parse_stack  &/*lexemes*/)
  {
    return true;
  }
};



} // namespace parser

#endif
