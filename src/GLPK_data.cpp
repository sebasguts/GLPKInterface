#include "GLPK_data.h"

extern Obj TheTypeExternalGLPKProblem;


Obj NewGLPKProblem(enum glpk_object_type t) {
  Obj o;
  o = NewBag(T_SPARE1, 2*sizeof(Obj));

  switch(t) {
    case T_GLPK_EXTERNAL_PROBLEM:
      ADDR_OBJ(o)[0] = TheTypeExternalGLPKProblem;
      break;
  }
  ADDR_OBJ(o)[1] = NULL;
  return o;
}

/* Free function */
void ExternalGLPKObjectFreeFunc(Obj o) {
  glp_prob* p = PROBOBJ_GLPKOBJ(o);
  if(p != NULL)
    glp_delete_prob(p);
}

/* Type object function for the object */
Obj ExternalGLPKObjectTypeFunc(Obj o) {
  return ADDR_OBJ(o)[0];
}
