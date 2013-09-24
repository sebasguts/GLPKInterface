

#include "GLPK_tools.h"

Obj real_GLPK_add_rows( Obj problem_obj, Obj nr_rows ){
  
  if( ! IS_INTOBJ(nr_rows) ){
      ErrorMayQuit( "incorrect input", 0, 0 );
      return False;
  }
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  int nr_rows_int = INT_INTOBJ( nr_rows );
  
  int current_first_row = glp_add_rows( problem, nr_rows_int );
  
  return INTOBJ_INT( current_first_row );
  
}

Obj real_GLPK_add_columns( Obj problem_obj, Obj nr_cols ){
  
  if( ! IS_INTOBJ(nr_cols) ){
      ErrorMayQuit( "incorrect input", 0, 0 );
      return False;
  }
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  int nr_cols_int = INT_INTOBJ( nr_cols );
  
  int current_first_col = glp_add_cols( problem, nr_cols_int );
  
  return INTOBJ_INT( current_first_col );
  
}

Obj real_GLPK_set_max( Obj problem_obj ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  glp_set_obj_dir( problem, GLP_MAX );
  
  return True;
  
}

Obj real_GLPK_set_min( Obj problem_obj ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  glp_set_obj_dir( problem, GLP_MIN );
  
  return True;
  
}



// Non-transvered tool functions

glp_prob* convert_and_check_probobj( Obj problem_obj ){
  
  if( ! IS_GLPK_PROBLEM( problem_obj ) )
      ErrorMayQuit( "incorrect input, expects problem object", 0, 0 );
  
  return PROBOBJ_GLPKOBJ( problem_obj );
}
