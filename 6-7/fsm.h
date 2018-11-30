#ifndef FSM_H
#define FSM_H
#include <vector>
#include <map>
#include <set>
#include <algorithm>


class tFSM {

public:
  //type override
  typedef char tSymbol;

  typedef unsigned char tState;
  typedef std::set< tState > tStateSet;

  /*create empty  machine*/
  tFSM() {}; 
  
  /* add one command (from,c)->to */
  void add(tState from, tSymbol c, tState to);
  
  /*includes one state*/
  void final(tState st); 

  /*in many closing applies the machine to the input chain*/
  int  apply(const tSymbol* input);

  /*clear machine*/
  void clear();
  
  /*size machine(many state)*/
//  size_t size() ;

  /*check correct machine*/
  friend class tFSMcheck;

private:

  /*representation of a deterministic finite machine*/
  typedef std::map< tSymbol, tState > tTransMap;
  
  typedef std::vector< tTransMap > tStateTable;

  /*table state*/
  tStateTable table;
  
  /*set finite state*/
  tStateSet finals; 

};



/*function helpers*/
void addstr(tFSM& fsm, tFSM::tState from, const tFSM::tSymbol *str, tFSM::tState to);
  
void addrange(tFSM& fsm, tFSM::tState from, tFSM::tSymbol first, tFSM::tSymbol last, tFSM::tState to);


/*------------------------------------------------------*/


                    /*Realization*/


/*-----------------------------------------------------*/

//std::size_t tFSM::size() {
//    return table.size();
//}


inline void tFSM::add(tState from, tSymbol c, tState to){
  std::size_t currentSize = 1 + std::max(from, to);
  if (currentSize > table.size())
      table.resize(currentSize);

  table[from][c] = to; 
}

inline void tFSM::final(tState state) {
  finals.insert(state);
}

inline void tFSM::clear() {
  finals.clear(); 
  table.clear();
}

inline int tFSM::apply(const tSymbol* input){
  
  if(table.empty()) 
      return 0; /* empty table state */
  
  tState state = 0; /* begin state */
  
  int accepted = 0;

  /* ���� ������� �� ������� ������� */
  while (*input){
    tTransMap::iterator iter;

    /*link on table of transitions from state*/
    tTransMap &trans = table[state];

    if ((iter = trans.find(*input)) == trans.end()) 
      break; /*no transitions*/

    state = iter->second; /* new state */
    ++accepted;
    ++input;
  }
  /*state of not the final?*/
  return (finals.count(state) == 0) ? 0 : accepted;
}

  inline void addstr(tFSM& fsm, tFSM::tState from, const tFSM::tSymbol *str,
              tFSM::tState to){
   for (; *str; ++str) 
    fsm.add(from, *str, to);
  }

  inline void addrange(tFSM& fsm, tFSM::tState from, tFSM::tSymbol first,
                tFSM::tSymbol last, tFSM::tState to){
   for (tFSM::tSymbol i = first; i <= last; ++i) 
      fsm.add(from, i, to);
  }

#endif
