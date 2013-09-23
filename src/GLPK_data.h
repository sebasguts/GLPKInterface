#ifndef GLPKDATA
#define GLPKDATA 1

#include "loadgap.h"

#include <glpk.h>

#include <iostream>
#include <map>
#include <utility>

using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::pair;

extern Obj TheTypeExternalGLPKProblem;

#define GLPKOBJ_SET_PROBOBJ(o, p) (ADDR_OBJ(o)[1] = reinterpret_cast<Obj>(p))
#define PROBOBJ_GLPKOBJ(o) (reinterpret_cast<glp_prob*>(ADDR_OBJ(o)[1]))

#define IS_GLPK_PROBLEM(o) ((UInt)(ADDR_OBJ(o)[0])==(UInt)TheTypeExternalGLPKProblem)


enum glpk_object_type {
  T_GLPK_EXTERNAL_PROBLEM
};
Obj NewGLPKProblem(enum glpk_object_type t);
void ExternalGLPKObjectFreeFunc(Obj o);
Obj ExternalGLPKObjectTypeFunc(Obj o);



#endif