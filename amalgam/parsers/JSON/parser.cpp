

#include <array>
#include <string>
#include <vector>

#include <amalgam/parsers/JSON/Value.h>
#include <amalgam/parsers/JSON/parser.h>

using namespace std;

namespace parser
{

//  ****************************************************************************
bool Parser::parse(const vector<char>& input)
{
  return parse(&input[0], input.size());
}

//  ****************************************************************************
bool Parser::parse(char const* p_input, size_t length)
{
  if (!p_input
    || 0 == length)
  {
    return false;
  }

  char const* p_token = p_input;
  char const* p_cur   = p_input;
  char const* p_end   = p_input + length;

  m_lexemes.push(new production(true));
  m_lexemes.push(new Value());


  production *p_last = nullptr;
  while ( p_cur <= p_end
       && !m_lexemes.empty())
  {
    p_last = m_lexemes.top();
    m_lexemes.pop();

    if (p_last->process(*p_cur, m_lexemes))
    {
      if (p_last->is_advance())
      {
        p_cur++;
      }
    }
    else
    {
      return false;
    }
  }

  if ( m_lexemes.empty()
    && p_cur == p_end)
  {
    // If this is the terminator, 
    // then the parse was valid.

    if (p_last)
      return p_last->is_terminator();
  }

  return false;
}

} // namespace parser

