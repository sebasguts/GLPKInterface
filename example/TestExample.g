#! @Title First GLPK example
#! @Author Sebastian Gutsche

#! @Chapter First example

#! Taken from the first example
#! in the GLPK manual.
#! Tests if all functions work, and
#! it is produces correct output.

#! @Example
LoadPackage("GLPKInterface");
#! true
prob := GLPK_CREATE_PROBLEM();
#! <an external GLPK problem>
GLPK_ADD_COLUMNS(prob,3);
#! 1
GLPK_ADD_ROWS(prob,3);
#! 1
GLPK_SET_MAX_PROBLEM(prob);
#! true
GLPK_SET_COEFF_MATRIX(prob,[[1,1,1],[10,4,5],[2,2,6]]);
#! true
GLPK_SET_UPPER_ROW_BOUND(prob,1,100);
#! true
GLPK_SET_UPPER_ROW_BOUND(prob,2,600);
#! true
GLPK_SET_UPPER_ROW_BOUND(prob,3,300);
#! true
GLPK_SET_LOWER_COLUMN_BOUND(prob,1,0);
#! true
GLPK_SET_LOWER_COLUMN_BOUND(prob,2,0);
#! true
GLPK_SET_LOWER_COLUMN_BOUND(prob,3,0);
#! true
GLPK_SET_OBJECT_COEFF(prob,1,10);
#! true
GLPK_SET_OBJECT_COEFF(prob,2,6);
#! true
GLPK_SET_OBJECT_COEFF(prob,3,4);
#! true
GLPK_SOLVE_PROBLEM(prob);
#! true
GLPK_OPTIMAL_VALUE(prob);
#! 732
GLPK_OPTIMAL_SOLUTION(prob);
#! [ 33, 67, 0 ]
#! @EndExample
