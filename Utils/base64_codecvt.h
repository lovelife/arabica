#ifndef base64_codecvtH
#define base64_codecvtH
///////////////////////////////////////////
//
// $Id$
//
///////////////////////////////////////////

#include <locale>

class base64_codecvt : public std::codecvt<char, char, std::char_traits<char>::state_type>
{
public:
  typedef std::char_traits<char>::state_type state_t;

protected:
  virtual ~base64_codecvt();

  virtual result do_out(state_t& state,
                        const char* from,
                        const char* from_end,
                        const char*& from_next,
                        char* to,
                        char* to_limit,
                        char*& to_next) const;

  virtual result do_in(state_t& state,
                       const char* from,
                       const char* from_end,
                       const char*& from_next,
                       char* to,
                       char* to_limit,
                       char*& to_next) const;

  virtual result do_unshift(state_t&  state,
                       char* to,
                       char* to_limit,
                       char*& to_next) const;

  virtual int do_encoding() const throw();

  virtual bool do_always_noconv() const throw();

  virtual int do_length(const state_t&,
                        const char* from,
                        const char* end,
                        size_t max) const;

  virtual int do_max_length() const throw();

private:
  // state here is a little tricky - we need the previous char and
  // the state counter, and in some case we need to "pad" the input
  // strings.  I use these helper functions to mungle them
  // together and keep the details neater (or try to anyway)
  mutable state_t* state_;
  mutable const char** from_next_;
  mutable const char** from_end_;
  void grabState(state_t& state) const { state_ = &state; }
  void grabFromNext(const char*& from_next) const { from_next_ = &from_next; }
  void grabFromEnd(const char*& from_end) const { from_end_ = &from_end; }

  int getState() const;
  void nextState() const;
  int getCurrentOutChar() const;
  void consumeOutChar() const;
  char getPreviousChar() const;
  void setPreviousChar(char c) const;
}; // class base64_codecvt

#endif
