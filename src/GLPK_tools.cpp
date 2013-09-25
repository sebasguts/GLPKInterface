

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

Obj real_GLPK_add_columns( Obj problem_obj, Obj nr_cols, bool integer_cols ){
  
  if( ! IS_INTOBJ(nr_cols) ){
      ErrorMayQuit( "incorrect input", 0, 0 );
      return False;
  }
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  int nr_cols_int = INT_INTOBJ( nr_cols );
  
  int current_first_col = glp_add_cols( problem, nr_cols_int );
  
  if( integer_cols){
      
      for( int i = current_first_col; i < current_first_col + nr_cols_int; i++ )
          glp_set_col_kind( problem, i, GLP_IV );
      
  }
  
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
  
  if( ! IS_INTOBJ( row_number ) || ( ( ! IS_INTOBJ( lower_bound ) || ! IS_INTOBJ( upper_bound ) )
   && ( ! IS_MACFLOAT( lower_bound ) || ! IS_MACFLOAT( upper_bound ) ) ) )
      ErrorMayQuit( "arguments must be integers or floats", 0, 0 );
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  double lower;
  
  if( IS_INTOBJ( lower_bound ) ){
      
      lower = static_cast<double>( INT_INTOBJ( lower_bound ) );
      
  }else{
      
      lower = static_cast<double>( VAL_MACFLOAT( lower_bound ) );
      
  }
  
  double upper;
  
  if( IS_INTOBJ( upper_bound ) ){
      
      upper = static_cast<double>( INT_INTOBJ( upper_bound ) );
      
  }else{
      
      upper = static_cast<double>( VAL_MACFLOAT( upper_bound ) );
      
  }
  
  int row = INT_INTOBJ( row_number );
  
  glp_set_row_bnds( problem, row, type, lower, upper );
  
  return True;
  
}

Obj real_GLPK_set_col_bounds( Obj problem_obj, Obj col_number, Obj lower_bound, Obj upper_bound, int type ){
  
  if( ! IS_INTOBJ( col_number ) || ( ( ! IS_INTOBJ( lower_bound ) || ! IS_INTOBJ( upper_bound ) )
   && ( ! IS_MACFLOAT( lower_bound ) || ! IS_MACFLOAT( upper_bound ) ) ) )
      ErrorMayQuit( "arguments must be integers or floats", 0, 0 );
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  double lower;
  
  if( IS_INTOBJ( lower_bound ) ){
      
      lower = static_cast<double>( INT_INTOBJ( lower_bound ) );
      
  }else{
      
      lower = static_cast<double>( VAL_MACFLOAT( lower_bound ) );
      
  }
  
  double upper;
  
  if( IS_INTOBJ( upper_bound ) ){
      
      upper = static_cast<double>( INT_INTOBJ( upper_bound ) );
      
  }else{
      
      upper = static_cast<double>( VAL_MACFLOAT( upper_bound ) );
      
  }
  
  int col = INT_INTOBJ( col_number );
  
  glp_set_col_bnds( problem, col, type, lower, upper );
  
  return True;
  
}

Obj real_GLPK_set_obj_coeff( Obj problem_obj, Obj col_number_obj, Obj coeff_obj ){
  
  if( ! IS_INTOBJ( col_number_obj ) || ( ( ! IS_INTOBJ( coeff_obj ) )  && ( ! IS_MACFLOAT( coeff_obj ) ) ) )
      ErrorMayQuit( "arguments must be integers or floats", 0, 0 );
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  double coeff;
  
  if( IS_INTOBJ( coeff_obj ) ){
      
      coeff = static_cast<double>( INT_INTOBJ( coeff_obj ) );
      
  }else{
      
      coeff = static_cast<double>( VAL_MACFLOAT( coeff_obj ) );
      
  }
  
  int col_number = INT_INTOBJ( col_number_obj );
  
  glp_set_obj_coef( problem, col_number, coeff );
  
  return True;
  
}

Obj real_GLPK_set_coeff_matrix( Obj problem_obj, Obj matrix ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  if( ! IS_PLIST( matrix ) )
      ErrorMayQuit( "argument must be a plain list", 0, 0 );
  
  int row_number = static_cast<int>( LEN_PLIST( matrix ) );
  
  if( row_number == 0 )
      return True;
  
  Obj row = ELM_PLIST( matrix, 1 );
  
  if( ! IS_PLIST( row ) )
      ErrorMayQuit( "argument must be a matrix", 0, 0 );
  
  int col_number = static_cast<int>( LEN_PLIST( row ) );
  
  double entries[row_number*col_number + 1];
  
  int row_index[row_number*col_number + 1];
  
  int col_index[row_number*col_number + 1];
  
  int index;
  
  Obj entry;
  
  for( int i = 1; i <= row_number; i++ ){
      
      row = ELM_PLIST( matrix, i );
      
      if( ! IS_PLIST( row ) ){
          ErrorMayQuit( "argument must be a matrix", 0, 0 );
      }
      
      if( ! static_cast<int>( LEN_PLIST( row ) ) == col_number ){
          ErrorMayQuit( "argument must be a matrix", 0, 0 );
      }
      
      for( int j = 1; j <= col_number; j++){
          
          entry = ELM_PLIST( row, j );
          
          if( ( ! IS_INTOBJ( entry ) ) && ( ! IS_MACFLOAT( entry ) ) )
              ErrorMayQuit( "argument must be an integer or float matrix", 0, 0 );
          
          index = ((i-1)*col_number) + ((j-1)) + 1;
          
          if( IS_INTOBJ( entry ) ){
              
              entries[ index ] = static_cast<double>( INT_INTOBJ( entry ) );
              
          }else{
              
              entries[ index ] = static_cast<double>( VAL_MACFLOAT( entry ) );
              
          }
          
          row_index[ index ] = i;
          
          col_index[ index ] = j;
          
      }
      
  }
  
  glp_load_matrix( problem, row_number*col_number, row_index, col_index, entries );
  
  return True;
  
}

Obj real_GLPK_solve_problem( Obj problem_obj ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  glp_simplex( problem, NULL );
  
  int return_value = glp_intopt( problem, NULL );
  
  if( return_value == 0 )
      return True;
  
  return False;
  
}

Obj real_GLPK_solve_integer_problem( Obj problem_obj, bool presolver ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  glp_iocp options;
  
  glp_init_iocp( &options );
  
  if( presolver ){
      
      options.presolve = GLP_ON;
      
  }
  
  int return_value = glp_intopt( problem, &options );
  
  if( return_value == 0 )
      return True;
  
  return False;
  
}

Obj real_GLPK_solve_problem_simplex( Obj problem_obj, bool presolver ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  int return_value = glp_simplex( problem, NULL );
  
  if( return_value == 0 )
      return True;
  
  return False;
  
}

Obj real_GLPK_optimal_value( Obj problem_obj ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  double val = glp_mip_obj_val( problem );
  
  return INTOBJ_INT( static_cast<int>( val ) );
  
}

Obj real_GLPK_optimal_value_float( Obj problem_obj ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  double val = glp_get_obj_val( problem );
  
  return NEW_MACFLOAT( val );
  
}

Obj real_GLPK_optimal_solution( Obj problem_obj ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  int nr_cols = glp_get_num_cols( problem );
  
  Obj solution_list = NEW_PLIST( T_PLIST , nr_cols );
  
  SET_LEN_PLIST( solution_list, static_cast<UInt>( nr_cols ) );
  
  for( int i = 1; i <= nr_cols; i++ ){
      
      SET_ELM_PLIST( solution_list, i, INTOBJ_INT( static_cast<int>( glp_mip_col_val( problem, i ) ) ) );
      
      CHANGED_BAG( solution_list );
      
  }
  
  return solution_list;
  
}

Obj real_GLPK_optimal_solution_float( Obj problem_obj ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  int nr_cols = glp_get_num_cols( problem );
  
  Obj solution_list = NEW_PLIST( T_PLIST , nr_cols );
  
  SET_LEN_PLIST( solution_list, static_cast<UInt>( nr_cols ) );
  
  for( int i = 1; i <= nr_cols; i++ ){
      
      SET_ELM_PLIST( solution_list, i, NEW_MACFLOAT( glp_get_col_prim( problem, i ) ) );
      
      CHANGED_BAG( solution_list );
      
  }
  
  return solution_list;
  
}

Obj real_GLPK_get_col_number( Obj problem_obj ){
  
  glp_prob* problem = convert_and_check_probobj( problem_obj );
  
  int nr_cols = glp_get_num_cols( problem );
  
  return INTOBJ_INT( nr_cols );
  
}


// Non-transvered tool functions

glp_prob* convert_and_check_probobj( Obj problem_obj ){
  
  if( ! IS_GLPK_PROBLEM( problem_obj ) )
      ErrorMayQuit( "incorrect input, expects problem object", 0, 0 );
  
  return PROBOBJ_GLPKOBJ( problem_obj );
}
