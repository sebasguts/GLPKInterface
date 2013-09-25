

#include "GLPK_data.h"

Obj real_GLPK_add_rows( Obj, Obj );

Obj real_GLPK_add_columns( Obj, Obj, bool );

Obj real_GLPK_set_max( Obj );

Obj real_GLPK_set_min( Obj );

Obj real_GLPK_set_row_bounds( Obj, Obj, Obj, Obj, int );

Obj real_GLPK_set_row_bounds_float( Obj, Obj, Obj, Obj, int );

Obj real_GLPK_set_col_bounds( Obj, Obj, Obj, Obj, int );

Obj real_GLPK_set_col_bounds_float( Obj, Obj, Obj, Obj, int );

Obj real_GLPK_set_obj_coeff( Obj, Obj, Obj );

Obj real_GLPK_set_obj_coeff_float( Obj, Obj, Obj );

Obj real_GLPK_set_coeff_matrix( Obj, Obj );

Obj real_GLPK_solve_problem_simplex( Obj );

Obj real_GLPK_solve_integer_problem( Obj, bool );

Obj real_GLPK_optimal_value( Obj );

Obj real_GLPK_optimal_solution( Obj );

Obj real_GLPK_optimal_value_float( Obj );

Obj real_GLPK_optimal_solution_float( Obj );

Obj real_GLPK_get_col_number( Obj );

//non-transvered tool functions

glp_prob* convert_and_check_probobj( Obj );
