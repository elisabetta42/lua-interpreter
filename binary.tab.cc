// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "binary.tab.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "binary.tab.hh"

// User implementation prologue.

#line 51 "binary.tab.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 21 "binary.yy" // lalr1.cc:408
 
unsigned int total = 0; 
Sequence *root;
unsigned int counter=0;
#include <string> 
#define YY_DECL yy::parser::symbol_type yylex() 
YY_DECL; 

#line 62 "binary.tab.cc" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 129 "binary.tab.cc" // lalr1.cc:474

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 75: // functioncall
        value.move< EFunction* > (that.value);
        break;

      case 68: // varlist
      case 69: // var
      case 71: // explist
      case 72: // oexplist
      case 73: // exp
      case 74: // prefixexp
      case 76: // args
        value.move< Expression* > (that.value);
        break;

      case 56: // program
      case 57: // chunk
      case 58: // stats
      case 60: // block
      case 65: // else_statement
        value.move< Sequence* > (that.value);
        break;

      case 62: // stat
        value.move< Statement* > (that.value);
        break;

      case 3: // SEMICOLON
      case 4: // NAME
      case 5: // BREAK
      case 6: // RETURN
      case 7: // EQUAL
      case 8: // COMMA
      case 9: // OSBRACKET
      case 10: // CSBRACKET
      case 11: // POINT
      case 12: // OPARENTHESIS
      case 13: // CPARENTHESIS
      case 14: // COLON
      case 15: // STRING
      case 16: // OBRACKET
      case 17: // CBRACKET
      case 18: // DO
      case 19: // END1
      case 20: // WHILE
      case 21: // REPEAT
      case 22: // UNTIL
      case 23: // IF
      case 24: // THEN
      case 25: // ELSEIF
      case 26: // ELSE
      case 27: // FOR
      case 28: // IN
      case 29: // FUNCTION
      case 30: // LOCAL
      case 31: // THREEPOINT
      case 32: // PLUS
      case 33: // MINUS
      case 34: // ASTERISK
      case 35: // FSLASH
      case 36: // HASH
      case 37: // ARCH
      case 38: // PERCENTAGE
      case 39: // LOWER
      case 40: // GREATER
      case 41: // NOT
      case 42: // AND
      case 43: // OR
      case 44: // ELOWER
      case 45: // EGREATER
      case 46: // ETILDA
      case 47: // DEQUAL
      case 48: // TWOPOINT
      case 49: // SDQUOTE
      case 50: // SQUOTE
      case 51: // NIL
      case 52: // FALSE
      case 53: // TRUE
      case 54: // NUMBER
      case 61: // laststatment
      case 63: // oexpcomma
      case 64: // elseif_statement
      case 66: // funcname
      case 67: // ofuncname
      case 70: // namelist
      case 77: // function
      case 78: // funcbody
      case 79: // parlist
      case 80: // oparlist
      case 81: // opt_parlist
      case 82: // tableconstructor
      case 83: // fieldlist
      case 84: // ofieldlist
      case 85: // field
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 75: // functioncall
        value.copy< EFunction* > (that.value);
        break;

      case 68: // varlist
      case 69: // var
      case 71: // explist
      case 72: // oexplist
      case 73: // exp
      case 74: // prefixexp
      case 76: // args
        value.copy< Expression* > (that.value);
        break;

      case 56: // program
      case 57: // chunk
      case 58: // stats
      case 60: // block
      case 65: // else_statement
        value.copy< Sequence* > (that.value);
        break;

      case 62: // stat
        value.copy< Statement* > (that.value);
        break;

      case 3: // SEMICOLON
      case 4: // NAME
      case 5: // BREAK
      case 6: // RETURN
      case 7: // EQUAL
      case 8: // COMMA
      case 9: // OSBRACKET
      case 10: // CSBRACKET
      case 11: // POINT
      case 12: // OPARENTHESIS
      case 13: // CPARENTHESIS
      case 14: // COLON
      case 15: // STRING
      case 16: // OBRACKET
      case 17: // CBRACKET
      case 18: // DO
      case 19: // END1
      case 20: // WHILE
      case 21: // REPEAT
      case 22: // UNTIL
      case 23: // IF
      case 24: // THEN
      case 25: // ELSEIF
      case 26: // ELSE
      case 27: // FOR
      case 28: // IN
      case 29: // FUNCTION
      case 30: // LOCAL
      case 31: // THREEPOINT
      case 32: // PLUS
      case 33: // MINUS
      case 34: // ASTERISK
      case 35: // FSLASH
      case 36: // HASH
      case 37: // ARCH
      case 38: // PERCENTAGE
      case 39: // LOWER
      case 40: // GREATER
      case 41: // NOT
      case 42: // AND
      case 43: // OR
      case 44: // ELOWER
      case 45: // EGREATER
      case 46: // ETILDA
      case 47: // DEQUAL
      case 48: // TWOPOINT
      case 49: // SDQUOTE
      case 50: // SQUOTE
      case 51: // NIL
      case 52: // FALSE
      case 53: // TRUE
      case 54: // NUMBER
      case 61: // laststatment
      case 63: // oexpcomma
      case 64: // elseif_statement
      case 66: // funcname
      case 67: // ofuncname
      case 70: // namelist
      case 77: // function
      case 78: // funcbody
      case 79: // parlist
      case 80: // oparlist
      case 81: // opt_parlist
      case 82: // tableconstructor
      case 83: // fieldlist
      case 84: // ofieldlist
      case 85: // field
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 75: // functioncall
        yylhs.value.build< EFunction* > ();
        break;

      case 68: // varlist
      case 69: // var
      case 71: // explist
      case 72: // oexplist
      case 73: // exp
      case 74: // prefixexp
      case 76: // args
        yylhs.value.build< Expression* > ();
        break;

      case 56: // program
      case 57: // chunk
      case 58: // stats
      case 60: // block
      case 65: // else_statement
        yylhs.value.build< Sequence* > ();
        break;

      case 62: // stat
        yylhs.value.build< Statement* > ();
        break;

      case 3: // SEMICOLON
      case 4: // NAME
      case 5: // BREAK
      case 6: // RETURN
      case 7: // EQUAL
      case 8: // COMMA
      case 9: // OSBRACKET
      case 10: // CSBRACKET
      case 11: // POINT
      case 12: // OPARENTHESIS
      case 13: // CPARENTHESIS
      case 14: // COLON
      case 15: // STRING
      case 16: // OBRACKET
      case 17: // CBRACKET
      case 18: // DO
      case 19: // END1
      case 20: // WHILE
      case 21: // REPEAT
      case 22: // UNTIL
      case 23: // IF
      case 24: // THEN
      case 25: // ELSEIF
      case 26: // ELSE
      case 27: // FOR
      case 28: // IN
      case 29: // FUNCTION
      case 30: // LOCAL
      case 31: // THREEPOINT
      case 32: // PLUS
      case 33: // MINUS
      case 34: // ASTERISK
      case 35: // FSLASH
      case 36: // HASH
      case 37: // ARCH
      case 38: // PERCENTAGE
      case 39: // LOWER
      case 40: // GREATER
      case 41: // NOT
      case 42: // AND
      case 43: // OR
      case 44: // ELOWER
      case 45: // EGREATER
      case 46: // ETILDA
      case 47: // DEQUAL
      case 48: // TWOPOINT
      case 49: // SDQUOTE
      case 50: // SQUOTE
      case 51: // NIL
      case 52: // FALSE
      case 53: // TRUE
      case 54: // NUMBER
      case 61: // laststatment
      case 63: // oexpcomma
      case 64: // elseif_statement
      case 66: // funcname
      case 67: // ofuncname
      case 70: // namelist
      case 77: // function
      case 78: // funcbody
      case 79: // parlist
      case 80: // oparlist
      case 81: // opt_parlist
      case 82: // tableconstructor
      case 83: // fieldlist
      case 84: // ofieldlist
      case 85: // field
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 146 "binary.yy" // lalr1.cc:847
    {root = yystack_[0].value.as< Sequence* > ();}
#line 735 "binary.tab.cc" // lalr1.cc:847
    break;

  case 3:
#line 149 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Sequence* > ()=yystack_[0].value.as< Sequence* > ();}
#line 741 "binary.tab.cc" // lalr1.cc:847
    break;

  case 4:
#line 150 "binary.yy" // lalr1.cc:847
    {}
#line 747 "binary.tab.cc" // lalr1.cc:847
    break;

  case 5:
#line 155 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Sequence* > ()=new Sequence();}
#line 753 "binary.tab.cc" // lalr1.cc:847
    break;

  case 6:
#line 156 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Sequence* > () = yystack_[2].value.as< Sequence* > ();yylhs.value.as< Sequence* > ()->addStatement(yystack_[1].value.as< Statement* > ()); }
#line 759 "binary.tab.cc" // lalr1.cc:847
    break;

  case 7:
#line 159 "binary.yy" // lalr1.cc:847
    {}
#line 765 "binary.tab.cc" // lalr1.cc:847
    break;

  case 9:
#line 163 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Sequence* > ()=yystack_[0].value.as< Sequence* > ();}
#line 771 "binary.tab.cc" // lalr1.cc:847
    break;

  case 10:
#line 166 "binary.yy" // lalr1.cc:847
    {}
#line 777 "binary.tab.cc" // lalr1.cc:847
    break;

  case 11:
#line 167 "binary.yy" // lalr1.cc:847
    {}
#line 783 "binary.tab.cc" // lalr1.cc:847
    break;

  case 12:
#line 170 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Statement* > ()=new Assign(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > ());}
#line 789 "binary.tab.cc" // lalr1.cc:847
    break;

  case 13:
#line 171 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Statement* > ()=new Call(yystack_[0].value.as< EFunction* > ());}
#line 795 "binary.tab.cc" // lalr1.cc:847
    break;

  case 14:
#line 172 "binary.yy" // lalr1.cc:847
    {}
#line 801 "binary.tab.cc" // lalr1.cc:847
    break;

  case 15:
#line 173 "binary.yy" // lalr1.cc:847
    {}
#line 807 "binary.tab.cc" // lalr1.cc:847
    break;

  case 16:
#line 175 "binary.yy" // lalr1.cc:847
    {}
#line 813 "binary.tab.cc" // lalr1.cc:847
    break;

  case 17:
#line 177 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Statement* > ()=new IfCnd(yystack_[5].value.as< Expression* > (),yystack_[3].value.as< Sequence* > (),yystack_[1].value.as< Sequence* > ());}
#line 819 "binary.tab.cc" // lalr1.cc:847
    break;

  case 18:
#line 179 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Statement* > ()=new ForNode(new Variable(yystack_[8].value.as< std::string > ()),yystack_[6].value.as< Expression* > (),yystack_[4].value.as< Expression* > (),yystack_[1].value.as< Sequence* > ());}
#line 825 "binary.tab.cc" // lalr1.cc:847
    break;

  case 19:
#line 181 "binary.yy" // lalr1.cc:847
    {}
#line 831 "binary.tab.cc" // lalr1.cc:847
    break;

  case 20:
#line 185 "binary.yy" // lalr1.cc:847
    {}
#line 837 "binary.tab.cc" // lalr1.cc:847
    break;

  case 21:
#line 188 "binary.yy" // lalr1.cc:847
    {}
#line 843 "binary.tab.cc" // lalr1.cc:847
    break;

  case 22:
#line 191 "binary.yy" // lalr1.cc:847
    {}
#line 849 "binary.tab.cc" // lalr1.cc:847
    break;

  case 23:
#line 193 "binary.yy" // lalr1.cc:847
    {}
#line 855 "binary.tab.cc" // lalr1.cc:847
    break;

  case 24:
#line 198 "binary.yy" // lalr1.cc:847
    {}
#line 861 "binary.tab.cc" // lalr1.cc:847
    break;

  case 26:
#line 202 "binary.yy" // lalr1.cc:847
    {}
#line 867 "binary.tab.cc" // lalr1.cc:847
    break;

  case 27:
#line 203 "binary.yy" // lalr1.cc:847
    {}
#line 873 "binary.tab.cc" // lalr1.cc:847
    break;

  case 28:
#line 206 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Sequence* > ()= NULL;}
#line 879 "binary.tab.cc" // lalr1.cc:847
    break;

  case 29:
#line 207 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Sequence* > ()=yystack_[0].value.as< Sequence* > ();}
#line 885 "binary.tab.cc" // lalr1.cc:847
    break;

  case 30:
#line 210 "binary.yy" // lalr1.cc:847
    {}
#line 891 "binary.tab.cc" // lalr1.cc:847
    break;

  case 31:
#line 211 "binary.yy" // lalr1.cc:847
    {}
#line 897 "binary.tab.cc" // lalr1.cc:847
    break;

  case 32:
#line 216 "binary.yy" // lalr1.cc:847
    {}
#line 903 "binary.tab.cc" // lalr1.cc:847
    break;

  case 33:
#line 217 "binary.yy" // lalr1.cc:847
    {}
#line 909 "binary.tab.cc" // lalr1.cc:847
    break;

  case 34:
#line 220 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=yystack_[0].value.as< Expression* > ();}
#line 915 "binary.tab.cc" // lalr1.cc:847
    break;

  case 36:
#line 224 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()= new Variable(yystack_[0].value.as< std::string > ());}
#line 921 "binary.tab.cc" // lalr1.cc:847
    break;

  case 37:
#line 225 "binary.yy" // lalr1.cc:847
    {}
#line 927 "binary.tab.cc" // lalr1.cc:847
    break;

  case 38:
#line 226 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()= new Variable("io."+yystack_[0].value.as< std::string > ());}
#line 933 "binary.tab.cc" // lalr1.cc:847
    break;

  case 39:
#line 229 "binary.yy" // lalr1.cc:847
    {}
#line 939 "binary.tab.cc" // lalr1.cc:847
    break;

  case 40:
#line 231 "binary.yy" // lalr1.cc:847
    {}
#line 945 "binary.tab.cc" // lalr1.cc:847
    break;

  case 41:
#line 235 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=yystack_[0].value.as< Expression* > ();}
#line 951 "binary.tab.cc" // lalr1.cc:847
    break;

  case 42:
#line 236 "binary.yy" // lalr1.cc:847
    {}
#line 957 "binary.tab.cc" // lalr1.cc:847
    break;

  case 43:
#line 240 "binary.yy" // lalr1.cc:847
    {}
#line 963 "binary.tab.cc" // lalr1.cc:847
    break;

  case 44:
#line 241 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=yystack_[0].value.as< Expression* > ();}
#line 969 "binary.tab.cc" // lalr1.cc:847
    break;

  case 45:
#line 244 "binary.yy" // lalr1.cc:847
    {}
#line 975 "binary.tab.cc" // lalr1.cc:847
    break;

  case 46:
#line 245 "binary.yy" // lalr1.cc:847
    {}
#line 981 "binary.tab.cc" // lalr1.cc:847
    break;

  case 47:
#line 246 "binary.yy" // lalr1.cc:847
    {}
#line 987 "binary.tab.cc" // lalr1.cc:847
    break;

  case 48:
#line 247 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new Constant(yystack_[0].value.as< std::string > ());}
#line 993 "binary.tab.cc" // lalr1.cc:847
    break;

  case 49:
#line 248 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new MyString(yystack_[0].value.as< std::string > ());}
#line 999 "binary.tab.cc" // lalr1.cc:847
    break;

  case 50:
#line 249 "binary.yy" // lalr1.cc:847
    {}
#line 1005 "binary.tab.cc" // lalr1.cc:847
    break;

  case 51:
#line 250 "binary.yy" // lalr1.cc:847
    {}
#line 1011 "binary.tab.cc" // lalr1.cc:847
    break;

  case 52:
#line 251 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=yystack_[0].value.as< Expression* > ();}
#line 1017 "binary.tab.cc" // lalr1.cc:847
    break;

  case 53:
#line 252 "binary.yy" // lalr1.cc:847
    {}
#line 1023 "binary.tab.cc" // lalr1.cc:847
    break;

  case 54:
#line 253 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new BinOp(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1029 "binary.tab.cc" // lalr1.cc:847
    break;

  case 55:
#line 254 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new BinOp(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1035 "binary.tab.cc" // lalr1.cc:847
    break;

  case 56:
#line 255 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new BinOp(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1041 "binary.tab.cc" // lalr1.cc:847
    break;

  case 57:
#line 256 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new BinOp(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1047 "binary.tab.cc" // lalr1.cc:847
    break;

  case 58:
#line 257 "binary.yy" // lalr1.cc:847
    {}
#line 1053 "binary.tab.cc" // lalr1.cc:847
    break;

  case 59:
#line 259 "binary.yy" // lalr1.cc:847
    {}
#line 1059 "binary.tab.cc" // lalr1.cc:847
    break;

  case 60:
#line 261 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new BinOp(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1065 "binary.tab.cc" // lalr1.cc:847
    break;

  case 61:
#line 263 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new Comparitor(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1071 "binary.tab.cc" // lalr1.cc:847
    break;

  case 62:
#line 264 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new Comparitor(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1077 "binary.tab.cc" // lalr1.cc:847
    break;

  case 63:
#line 265 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new Comparitor(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1083 "binary.tab.cc" // lalr1.cc:847
    break;

  case 64:
#line 266 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new Comparitor(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1089 "binary.tab.cc" // lalr1.cc:847
    break;

  case 65:
#line 267 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new Comparitor(yystack_[2].value.as< Expression* > (),yystack_[0].value.as< Expression* > (),yystack_[1].value.as< std::string > ());}
#line 1095 "binary.tab.cc" // lalr1.cc:847
    break;

  case 66:
#line 268 "binary.yy" // lalr1.cc:847
    {}
#line 1101 "binary.tab.cc" // lalr1.cc:847
    break;

  case 67:
#line 270 "binary.yy" // lalr1.cc:847
    {}
#line 1107 "binary.tab.cc" // lalr1.cc:847
    break;

  case 68:
#line 272 "binary.yy" // lalr1.cc:847
    {}
#line 1113 "binary.tab.cc" // lalr1.cc:847
    break;

  case 69:
#line 274 "binary.yy" // lalr1.cc:847
    {}
#line 1119 "binary.tab.cc" // lalr1.cc:847
    break;

  case 70:
#line 275 "binary.yy" // lalr1.cc:847
    {}
#line 1125 "binary.tab.cc" // lalr1.cc:847
    break;

  case 71:
#line 276 "binary.yy" // lalr1.cc:847
    {}
#line 1131 "binary.tab.cc" // lalr1.cc:847
    break;

  case 72:
#line 281 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=yystack_[0].value.as< Expression* > ();}
#line 1137 "binary.tab.cc" // lalr1.cc:847
    break;

  case 73:
#line 282 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=yystack_[0].value.as< EFunction* > ();}
#line 1143 "binary.tab.cc" // lalr1.cc:847
    break;

  case 74:
#line 283 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=yystack_[1].value.as< Expression* > ();}
#line 1149 "binary.tab.cc" // lalr1.cc:847
    break;

  case 75:
#line 286 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< EFunction* > ()=new EFunction(yystack_[1].value.as< Expression* > ()->name,yystack_[0].value.as< Expression* > ());}
#line 1155 "binary.tab.cc" // lalr1.cc:847
    break;

  case 76:
#line 287 "binary.yy" // lalr1.cc:847
    {}
#line 1161 "binary.tab.cc" // lalr1.cc:847
    break;

  case 77:
#line 290 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=yystack_[1].value.as< Expression* > ();}
#line 1167 "binary.tab.cc" // lalr1.cc:847
    break;

  case 78:
#line 292 "binary.yy" // lalr1.cc:847
    {}
#line 1173 "binary.tab.cc" // lalr1.cc:847
    break;

  case 79:
#line 293 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Expression* > ()=new MyString(yystack_[0].value.as< std::string > ());}
#line 1179 "binary.tab.cc" // lalr1.cc:847
    break;

  case 80:
#line 296 "binary.yy" // lalr1.cc:847
    {std::cout<<"FUNCTION: ";}
#line 1185 "binary.tab.cc" // lalr1.cc:847
    break;

  case 81:
#line 298 "binary.yy" // lalr1.cc:847
    {}
#line 1191 "binary.tab.cc" // lalr1.cc:847
    break;

  case 82:
#line 303 "binary.yy" // lalr1.cc:847
    {}
#line 1197 "binary.tab.cc" // lalr1.cc:847
    break;

  case 83:
#line 305 "binary.yy" // lalr1.cc:847
    {}
#line 1203 "binary.tab.cc" // lalr1.cc:847
    break;

  case 84:
#line 308 "binary.yy" // lalr1.cc:847
    {}
#line 1209 "binary.tab.cc" // lalr1.cc:847
    break;

  case 85:
#line 309 "binary.yy" // lalr1.cc:847
    {}
#line 1215 "binary.tab.cc" // lalr1.cc:847
    break;

  case 86:
#line 312 "binary.yy" // lalr1.cc:847
    {}
#line 1221 "binary.tab.cc" // lalr1.cc:847
    break;

  case 87:
#line 313 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< std::string > ()=yystack_[0].value.as< std::string > ();}
#line 1227 "binary.tab.cc" // lalr1.cc:847
    break;

  case 88:
#line 316 "binary.yy" // lalr1.cc:847
    {}
#line 1233 "binary.tab.cc" // lalr1.cc:847
    break;

  case 89:
#line 319 "binary.yy" // lalr1.cc:847
    {}
#line 1239 "binary.tab.cc" // lalr1.cc:847
    break;

  case 90:
#line 320 "binary.yy" // lalr1.cc:847
    {}
#line 1245 "binary.tab.cc" // lalr1.cc:847
    break;

  case 91:
#line 323 "binary.yy" // lalr1.cc:847
    {}
#line 1251 "binary.tab.cc" // lalr1.cc:847
    break;

  case 92:
#line 324 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< std::string > ()=yystack_[1].value.as< std::string > ();}
#line 1257 "binary.tab.cc" // lalr1.cc:847
    break;

  case 93:
#line 328 "binary.yy" // lalr1.cc:847
    {}
#line 1263 "binary.tab.cc" // lalr1.cc:847
    break;

  case 94:
#line 331 "binary.yy" // lalr1.cc:847
    {}
#line 1269 "binary.tab.cc" // lalr1.cc:847
    break;

  case 95:
#line 334 "binary.yy" // lalr1.cc:847
    {}
#line 1275 "binary.tab.cc" // lalr1.cc:847
    break;

  case 98:
#line 341 "binary.yy" // lalr1.cc:847
    {}
#line 1281 "binary.tab.cc" // lalr1.cc:847
    break;

  case 99:
#line 342 "binary.yy" // lalr1.cc:847
    {}
#line 1287 "binary.tab.cc" // lalr1.cc:847
    break;


#line 1291 "binary.tab.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -53;

  const signed char parser::yytable_ninf_ = -74;

  const short int
  parser::yypact_[] =
  {
     -53,    15,   -53,   292,   -53,   -53,   -53,   109,   109,   -53,
     109,   -53,   109,     7,    20,     3,    38,    38,    19,    43,
      60,   101,   -53,    13,    31,   -53,   109,   109,   109,   -53,
     -53,   -53,   -53,   -53,    39,   -53,   327,    60,   -53,   -53,
     -53,   229,   -53,    34,   247,    33,   293,    61,     8,   -53,
      49,   -53,    69,    55,   -53,   -53,   -53,   109,     6,   109,
      73,   109,    79,   -53,   -53,   -53,    78,   109,   327,    37,
      70,   -53,     2,   -53,   342,   -53,   -53,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   -53,   -53,   -53,   109,   -53,   109,   102,
     109,   104,   -53,    31,   109,    39,    72,   189,   -53,    92,
      -3,   109,   206,   -53,   -53,    13,   -53,   -53,   -53,   103,
     -53,   105,   327,   342,   342,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,    95,   327,
     -53,   146,   -53,    12,   106,   -53,    39,   -53,   -53,   -53,
     327,   112,   -53,     4,   -53,   -53,   -53,    56,   109,   -53,
     119,   -53,   109,   -53,   108,   109,   -53,   110,   163,   111,
     -53,   327,   -53,   310,   -53,   -53,   109,   113,   -53,   -53,
     327,   -53,   -53,   114,   -53
  };

  const unsigned char
  parser::yydefact_[] =
  {
       5,     0,     2,     3,     1,    36,    11,    43,     0,     5,
       0,     5,     0,     0,     0,     0,     7,     7,     0,    72,
       0,    13,    49,    91,     0,    50,     0,     0,     0,    45,
      46,    47,    48,    72,    44,    10,    41,    52,    73,    51,
      53,     0,     9,     0,     0,     0,     0,    39,     0,    30,
       0,    39,     0,    22,     8,     4,     6,     0,     0,     0,
       0,    43,     0,    79,    75,    78,    36,     0,    95,    98,
       0,    89,    86,    80,    69,    71,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    14,     5,     0,     5,     0,     0,
       0,     0,    20,     0,     0,    12,    72,     0,    38,     0,
       0,     0,     0,    97,    96,    99,    92,    88,    83,    84,
      87,     0,    42,    55,    54,    56,    57,    58,    60,    61,
      63,    67,    68,    62,    64,    66,    65,    59,     0,    16,
      26,     0,    40,     0,    32,    21,    23,    37,    77,    76,
      94,     0,    90,     0,    82,     5,    15,    28,     0,     5,
       0,    31,     0,    85,     0,     0,     5,     0,    24,     0,
      33,    93,    81,     0,    29,    17,     0,     0,    19,     5,
      25,     5,    27,     0,    18
  };

  const short int
  parser::yypgoto_[] =
  {
     -53,   -53,   128,   -53,   115,   -11,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,    -1,   -14,   -52,    74,    11,     1,
     131,    26,   -53,   -47,   -53,   -53,   -53,    -6,   -53,   -53,
      22,   -53,   -53
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,    42,     3,    55,    43,    16,    17,   177,   157,
     167,    50,   161,    18,    33,    48,    34,    35,    36,    37,
      38,    64,    39,    73,   120,   154,   121,    40,    69,    70,
      71,   115,   116
  };

  const short int
  parser::yytable_[] =
  {
      45,    53,    19,   102,    20,   105,    51,    51,   142,    61,
       5,    47,    63,    23,    65,     4,    99,    66,     8,    41,
      77,    44,    67,    46,    49,     8,    57,    58,    22,    23,
     159,    65,    52,   118,    68,   163,   100,    74,    75,    76,
     113,    54,    24,    72,    25,   114,    26,    77,   143,    27,
     -34,   -34,   146,    94,    28,    96,   145,   106,   119,    20,
     101,    72,   104,    99,    29,    30,    31,    32,    98,    59,
     107,    60,    61,   103,    62,    63,    23,   108,   112,   -35,
     -35,   165,   166,   110,   138,   111,   140,   117,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    65,   148,   142,   139,   144,   141,
     -73,   153,   -73,     5,   156,   -73,   -73,   -73,   155,   162,
     160,     8,   150,   170,    22,    23,    68,   172,     2,   175,
     178,   181,    56,   184,    21,   109,   149,   152,    24,     0,
      25,     0,    26,     0,   164,    27,     0,     0,   169,     0,
      28,     0,     0,     0,   158,   174,     0,     0,     0,     0,
      29,    30,    31,    32,     0,     0,     0,     0,   182,   168,
     183,   176,     0,   171,     0,     0,   173,     0,    78,    79,
      80,    81,     0,    82,    83,    84,    85,   180,    86,    87,
      88,    89,    90,    91,    92,    78,    79,    80,    81,   147,
      82,    83,    84,    85,     0,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,     0,   151,     0,     0,     0,
       0,    78,    79,    80,    81,     0,    82,    83,    84,    85,
       0,    86,    87,    88,    89,    90,    91,    92,    78,    79,
      80,    81,    93,    82,    83,    84,    85,     0,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     0,     0,
       0,    78,    79,    80,    81,    95,    82,    83,    84,    85,
       0,    86,    87,    88,    89,    90,    91,    92,     0,    78,
      79,    80,    81,     0,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,    92,     5,     6,     7,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       9,     0,    10,    11,     0,    12,     0,    97,     0,    13,
       0,    14,    15,     0,     0,    78,    79,    80,    81,     0,
      82,    83,    84,    85,   179,    86,    87,    88,    89,    90,
      91,    92,    78,    79,    80,    81,     0,    82,    83,    84,
      85,     0,    86,    87,    88,    89,    90,    91,    92,    78,
      79,    80,    81,     0,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,    92,    80,    81,     0,    82,
      83,    84,    85,     0,    86,    87,    88,    89,    90,    91,
      92
  };

  const short int
  parser::yycheck_[] =
  {
      11,    15,     3,    50,     3,    57,     4,     4,     4,    12,
       4,     4,    15,    16,    20,     0,     8,     4,    12,     8,
       8,    10,     9,    12,     4,    12,     7,     8,    15,    16,
      18,    37,    29,    31,    23,    31,    28,    26,    27,    28,
       3,     3,    29,    12,    31,     8,    33,     8,   100,    36,
       7,     8,   104,    19,    41,    22,   103,    58,    72,    58,
      11,    12,     7,     8,    51,    52,    53,    54,     7,     9,
      59,    11,    12,     4,    14,    15,    16,     4,    67,     7,
       8,    25,    26,     4,    95,     7,    97,    17,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   110,    13,     4,    96,     4,    98,
       9,     8,    11,     4,    19,    14,    15,    16,    13,     7,
      14,    12,   111,     4,    15,    16,   115,    19,     0,    19,
      19,    18,    17,    19,     3,    61,   110,   115,    29,    -1,
      31,    -1,    33,    -1,   155,    36,    -1,    -1,   159,    -1,
      41,    -1,    -1,    -1,     8,   166,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,   179,   158,
     181,     8,    -1,   162,    -1,    -1,   165,    -1,    32,    33,
      34,    35,    -1,    37,    38,    39,    40,   176,    42,    43,
      44,    45,    46,    47,    48,    32,    33,    34,    35,    10,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      -1,    42,    43,    44,    45,    46,    47,    48,    32,    33,
      34,    35,    13,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    18,    37,    38,    39,    40,
      -1,    42,    43,    44,    45,    46,    47,    48,    -1,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    23,    -1,    24,    -1,    27,
      -1,    29,    30,    -1,    -1,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    24,    42,    43,    44,    45,    46,
      47,    48,    32,    33,    34,    35,    -1,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    34,    35,    -1,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      48
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    56,    57,    58,     0,     4,     5,     6,    12,    18,
      20,    21,    23,    27,    29,    30,    61,    62,    68,    69,
      74,    75,    15,    16,    29,    31,    33,    36,    41,    51,
      52,    53,    54,    69,    71,    72,    73,    74,    75,    77,
      82,    73,    57,    60,    73,    60,    73,     4,    70,     4,
      66,     4,    29,    70,     3,    59,    59,     7,     8,     9,
      11,    12,    14,    15,    76,    82,     4,     9,    73,    83,
      84,    85,    12,    78,    73,    73,    73,     8,    32,    33,
      34,    35,    37,    38,    39,    40,    42,    43,    44,    45,
      46,    47,    48,    13,    19,    18,    22,    24,     7,     8,
      28,    11,    78,     4,     7,    71,    69,    73,     4,    72,
       4,     7,    73,     3,     8,    86,    87,    17,    31,    70,
      79,    81,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    60,    73,
      60,    73,     4,    71,     4,    78,    71,    10,    13,    76,
      73,    10,    85,     8,    80,    13,    19,    64,     8,    18,
      14,    67,     7,    31,    60,    25,    26,    65,    73,    60,
       4,    73,    19,    73,    60,    19,     8,    63,    19,    24,
      73,    18,    60,    60,    19
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    55,    56,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    76,    76,    76,
      77,    78,    79,    79,    80,    80,    81,    81,    82,    83,
      83,    84,    84,    85,    85,    85,    86,    86,    87,    87
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     3,     0,     3,     0,     1,     1,
       2,     1,     3,     1,     3,     5,     4,     7,    10,     7,
       3,     4,     2,     4,     0,     2,     0,     5,     0,     2,
       1,     4,     0,     2,     1,     3,     1,     4,     3,     1,
       3,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     1,     1,     3,     2,     4,     3,     1,     1,
       2,     5,     2,     1,     0,     2,     0,     1,     3,     1,
       3,     0,     2,     5,     3,     1,     1,     1,     0,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "SEMICOLON", "NAME", "BREAK",
  "RETURN", "EQUAL", "COMMA", "OSBRACKET", "CSBRACKET", "POINT",
  "OPARENTHESIS", "CPARENTHESIS", "COLON", "STRING", "OBRACKET",
  "CBRACKET", "DO", "END1", "WHILE", "REPEAT", "UNTIL", "IF", "THEN",
  "ELSEIF", "ELSE", "FOR", "IN", "FUNCTION", "LOCAL", "THREEPOINT", "PLUS",
  "MINUS", "ASTERISK", "FSLASH", "HASH", "ARCH", "PERCENTAGE", "LOWER",
  "GREATER", "NOT", "AND", "OR", "ELOWER", "EGREATER", "ETILDA", "DEQUAL",
  "TWOPOINT", "SDQUOTE", "SQUOTE", "NIL", "FALSE", "TRUE", "NUMBER",
  "$accept", "program", "chunk", "stats", "optional_semicolon", "block",
  "laststatment", "stat", "oexpcomma", "elseif_statement",
  "else_statement", "funcname", "ofuncname", "varlist", "var", "namelist",
  "explist", "oexplist", "exp", "prefixexp", "functioncall", "args",
  "function", "funcbody", "parlist", "oparlist", "opt_parlist",
  "tableconstructor", "fieldlist", "ofieldlist", "field", "fieldsep",
  "ofieldsep", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   146,   146,   149,   150,   155,   156,   159,   160,   163,
     166,   167,   170,   171,   172,   173,   175,   177,   178,   181,
     185,   188,   191,   193,   198,   199,   202,   203,   206,   207,
     210,   211,   216,   217,   220,   221,   224,   225,   226,   229,
     231,   235,   236,   240,   241,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   259,
     261,   263,   264,   265,   266,   267,   268,   270,   272,   274,
     275,   276,   281,   282,   283,   286,   287,   290,   292,   293,
     296,   298,   303,   305,   308,   309,   312,   313,   316,   319,
     320,   323,   324,   328,   331,   334,   338,   339,   341,   342
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1739 "binary.tab.cc" // lalr1.cc:1155
