

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

Obj real_GLPK_set_row_bounds( Obj problem_obj, Obj row_number, Obj lower_bound, Obj upper_bound, int type ){
  
  if( ! IS_INTOBJ( lower_bound ) || ! IS_INTOBJ( upper_bound ) || ! IS_INTOBJ( row_number ) )
      ErrorMayQuit( "arguments must be integers", 0, 0 );
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  double lower = static_cast<double>( INT_INTOBJ( lower_bound ) );
  
  double upper = static_cast<double>( INT_INTOBJ( upper_bound ) );
  
  int row = INT_INTOBJ( row_number );
  
  glp_set_row_bnds( problem, row, type, lower, upper );
  
  return True;
  
}

Obj real_GLPK_set_col_bounds( Obj problem_obj, Obj col_number, Obj lower_bound, Obj upper_bound, int type ){
  
  if( ! IS_INTOBJ( lower_bound ) || ! IS_INTOBJ( upper_bound ) || ! IS_INTOBJ( col_number ) )
      ErrorMayQuit( "arguments must be integers", 0, 0 );
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  double lower = static_cast<double>( INT_INTOBJ( lower_bound ) );
  
  double upper = static_cast<double>( INT_INTOBJ( upper_bound ) );
  
  int col = INT_INTOBJ( col_number );
  
  glp_set_col_bnds( problem, col, type, lower, upper );
  
  return True;
  
}

Obj real_GLPK_set_obj_coeff( Obj problem_obj, Obj col_number_obj, Obj coeff_obj ){
  
  if( ! IS_INTOBJ( col_number_obj ) || ! IS_INTOBJ( coeff_obj ) )
      ErrorMayQuit( "arguments must be integers", 0, 0 );
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  double coeff = static_cast<double>( INT_INTOBJ( coeff_obj ) );
  
  int col_number = INT_INTOBJ( col_number_obj );
  
  glp_set_obj_coef( problem, col_number, coeff );
  
}

// Non-transvered tool functions

glp_prob* convert_and_check_probobj( Obj problem_obj ){
  
  if( ! IS_GLPK_PROBLEM( problem_obj ) )
      ErrorMayQuit( "incorrect input, expects problem object", 0, 0 );
  
  return PROBOBJ_GLPKOBJ( problem_obj );
}
