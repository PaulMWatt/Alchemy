/// @file JSON_Test.hpp
///
/// A collection of unit-tests to verify a JSON parser written for C++.
///
/// @author Paul M. Watt
/// @date   2015.12.21: Paul M. Watt    -- Initial release.
///
/// TODO: Update with an appropriate license copyright 2015
///
///  Verify data with these TEST ASSERTIONS:
///
///  TS_FAIL(message):                        Fail unconditionally
///  TS_ASSERT(expr):                         Verify (expr) is true
///  TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
///  TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
///  TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
///  TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
///  TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
///  TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
///  TS_ASSERT_PREDICATE(P, x):               Verify P(x)
///  TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
///  TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
///  TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
///  TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
///  TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
///  TS_WARN(message):                        Print message as a warning
///  TS_TRACE(message):                       Print message as an information message
///
///
#ifndef JSON_Test_H_INCLUDED
#define JSON_Test_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <amalgam/parsers/JSON/parser.h>
#include <amalgam/parsers/JSON/Number.h>


//  ***************************************************************************
/// JSON_Test
/// JSON_Test Test Suite class.
/// 
class JSON_Test : public CxxTest::TestSuite
{
public:

  JSON_Test()
  {
    // TODO: Construct Test Suite Object
  }

  //  Fixture Management ******************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {
    // TODO: Add common fixture setup code if any exists.
  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {
    // TODO: Add common fixture teardown code if any exists.
  }

protected:
  //  Test Suite Data *********************************************************

  //  Creator Methods *********************************************************
  // TODO: Use creator methods to reduce redundant setup code in test cases.

public:
  //  Test Cases **************************************************************
  // These are quick test entries to verify the basic types work
  void TestCase_WhiteSpace(void);
  void TestCase_String(void);
  void TestCase_Number(void);
  void TestCase_Array(void);
  void TestCase_Object(void);

  // This group also covers the literal terms.
  void TestCase_null(void);
  void TestCase_true(void);
  void TestCase_false(void);

  // Verify whitespace before and after value
  void TestCase_WhiteSpace_before_only(void);
  void TestCase_WhiteSpace_after_only(void);
  void TestCase_WhiteSpace_before_and_after(void);

  // Detailed tests for string parsing with ASCII encoding.
  void TestCase_String_empty(void);
  void TestCase_String_even_quotes(void);
  void TestCase_String_odd_quotes_fail(void);

  void TestCase_String_escaped_backslash(void);
  void TestCase_String_escaped_fwdslash(void);
  void TestCase_String_escaped_quote(void);
  void TestCase_String_escaped_back(void);
  void TestCase_String_escaped_formfeed(void);
  void TestCase_String_escaped_newline(void);
  void TestCase_String_escaped_return(void);
  void TestCase_String_escaped_tab(void);
  void TestCase_String_escaped_unicode(void);
  void TestCase_String_escaped_UNICODE(void);

  // Detailed tests for Number types
  void TestCase_Number_zero(void);
  void TestCase_Number_zero_neg(void);
  void TestCase_Number_int(void);
  void TestCase_Number_int_neg(void);
  void TestCase_Number_real(void);
  void TestCase_Number_real_neg(void);
  void TestCase_Number_scientific(void);
  void TestCase_Number_scientific_neg(void);
  void TestCase_Number_scientific_neg_exp(void);
  void TestCase_Number_scientific_pos_exp(void);

  void TestCase_Number_multiple_decimal_fail(void);
  void TestCase_Number_multiple_exp_fail(void);
  void TestCase_Number_non_digit_fail(void);
  void TestCase_Number_incorrect_sign_location_fail(void);
  void TestCase_Number_int_pos_fail(void);
  void TestCase_Number_real_pos_fail(void);
  void TestCase_Number_scientific_pos_fail(void);



};

//  ***************************************************************************
void JSON_Test::TestCase_WhiteSpace(void)
{
  parser::Parser p;
  std::string    input = "\r\t \b\n3";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}

//  ***************************************************************************
void JSON_Test::TestCase_String(void)
{
  parser::Parser p;
  std::string    input = "\"This is a String\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number(void)
{
  parser::Parser p;
  std::string    input = "30.4E34";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}

//  ***************************************************************************
void JSON_Test::TestCase_Array(void)
{
  parser::Parser p;
  std::string    input = "[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 ]";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}

//  ***************************************************************************
void JSON_Test::TestCase_Object(void)
{
  parser::Parser p;
  std::string    input = "{ \"Major\" : 12345, \"Minor\" : 7890 }";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}


//  ***************************************************************************
void JSON_Test::TestCase_null(void)
{
  parser::Parser p;

  std::string    input = "null";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}

//  ***************************************************************************
void JSON_Test::TestCase_true(void)
{
  parser::Parser p;
  std::string    input = "true";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}

//  ***************************************************************************
void JSON_Test::TestCase_false(void)
{
  parser::Parser p;
  std::string    input = "false";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}

//  ***************************************************************************
void JSON_Test::TestCase_WhiteSpace_before_only(void)
{
  parser::Parser p;
  std::string    input = "\r\n234";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}

//  ***************************************************************************
void JSON_Test::TestCase_WhiteSpace_after_only(void)
{
  parser::Parser p;
  std::string    input = "\"Hello\"\r\n";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}

//  ***************************************************************************
void JSON_Test::TestCase_WhiteSpace_before_and_after(void)
{
  parser::Parser p;
  std::string    input = "\r3";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);

}

//  ***************************************************************************
void JSON_Test::TestCase_String_empty(void)
{
  parser::Parser p;
  std::string    input = "\"\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_even_quotes(void)
{
  parser::Parser p;
  std::string    input = "\"\\\"\\\"\\\"\\\"\\\"\\\"\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_odd_quotes_fail(void)
{
  parser::Parser p;

  // This string contains a starting quote,
  // then an escaped quote, but no valid closing quote.
  std::string    input = "\"\\\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(!isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_backslash(void)
{
  parser::Parser p;
  std::string    input = "\"backslash \\\\ backslash\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_fwdslash(void)
{
  parser::Parser p;
  std::string    input = "\"fwdslash \\/ fwdslash\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_quote(void)
{
  parser::Parser p;
  std::string    input = "\"quote \\\" quote\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_back(void)
{
  parser::Parser p;
  std::string    input = "\"back \\b back\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_formfeed(void)
{
  parser::Parser p;
  std::string    input = "\"formfeed \\f formfeed\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_newline(void)
{
  parser::Parser p;
  std::string    input = "\"newline \\n newline\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_return(void)
{
  parser::Parser p;
  std::string    input = "\"return \\r return\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_tab(void)
{
  parser::Parser p;
  std::string    input = "\"tab \\t tab\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_unicode(void)
{
  parser::Parser p;
  std::string    input = "\"unicode \\u1234 \\u5678 \\u90ab \\ucdef unicode\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_String_escaped_UNICODE(void)
{
  parser::Parser p;
  std::string    input = "\"UNICODE \\u1234 \\u5678 \\u90AB \\uCDEF UNICODE\"";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_zero(void)
{
  parser::Parser p;
  std::string    input = "0";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_zero_neg(void)
{
  parser::Parser p;
  std::string    input = "-0";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_int(void)
{
  parser::Parser p;
  std::string    input = "742";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_int_neg(void)
{
  parser::Parser p;
  std::string    input = "-2568";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_real(void)
{
  parser::Parser p;
  std::string    input = "135.79";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_real_neg(void)
{
  parser::Parser p;
  std::string    input = "-24.680";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_scientific(void)
{
  parser::Parser p;
  std::string    input = "1.0003e100";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_scientific_neg(void)
{
  parser::Parser p;
  std::string    input = "-3.975E12";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_scientific_neg_exp(void)
{
  parser::Parser p;
  std::string    input = "2.334E-2";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_scientific_pos_exp(void)
{
  parser::Parser p;
  std::string    input = "2.334e+2";

  bool isValid = p.parse(input.c_str(), input.length());
  TS_ASSERT(isValid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_multiple_decimal_fail(void)
{
  parser::Parser p;
  std::string    input = "4.5.0";

  bool isInvalid = !p.parse(input.c_str(), input.length());
  TS_ASSERT(isInvalid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_multiple_exp_fail(void)
{
  parser::Parser p;
  std::string    input = "3.0e4e4";

  bool isInvalid = !p.parse(input.c_str(), input.length());
  TS_ASSERT(isInvalid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_non_digit_fail(void)
{
  parser::Parser p;
  std::string    input = "45f.04";

  bool isInvalid = !p.parse(input.c_str(), input.length());
  TS_ASSERT(isInvalid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_incorrect_sign_location_fail(void)
{
  parser::Parser p;
  std::string    input = "45.-04";

  bool isInvalid = !p.parse(input.c_str(), input.length());
  TS_ASSERT(isInvalid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_int_pos_fail(void)
{
  parser::Parser p;
  std::string    input = "+11110033";

  bool isInvalid = !p.parse(input.c_str(), input.length());
  TS_ASSERT(isInvalid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_real_pos_fail(void)
{
  parser::Parser p;
  std::string    input = "+34443.680";

  bool isInvalid = !p.parse(input.c_str(), input.length());
  TS_ASSERT(isInvalid);
}

//  ***************************************************************************
void JSON_Test::TestCase_Number_scientific_pos_fail(void)
{
  parser::Parser p;
  std::string    input = "+3.9e9898912";

  bool isInvalid = !p.parse(input.c_str(), input.length());
  TS_ASSERT(isInvalid);
}


#endif