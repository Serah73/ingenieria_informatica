#pragma once

#include "vector_t.hpp"
#include "stack_v_t.hpp"

using namespace AED;

int RBS(const vector t<int>& v, int i, int d, int x)
{
  int pos = -1;

  if(i <= d){
    const int c = (i + d)/2;
    if(x == v[c]) pos = c;
    else{
      if(x < v[c]) pos = RBS(v,i,c - 1, x);
      else pos = RBS(v, c + 1, d, x);
    }
  }

int buscal(const vector_t)
{
  return 
}



  return pos;
}
