#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <amalgam/parsers/JSON/production.h>


namespace parser
{

//  ****************************************************************************
class Object
  : public production
{
protected:
  virtual
    bool OnProcess(char_type     token,
      parse_stack  &lexemes);
};


}

#endif
