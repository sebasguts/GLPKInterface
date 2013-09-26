## This is a pure AutoDoc file. This is not expected to be read or to work.

#! @Chapter Introduction

#!  This package is an interface to GLPK, GNU Linear Programming Kit.
#!  The functions and objects are wrappers for corresponding
#!  GLPK functions, along with some convinience functions.
#!  To use this package, you need to have GLPK installed.

#! @Chapter Installation

#! @Chapter Functions

#!  This chapter contains all the transferred functions.

#! @Section Create Problem

#! @Description
#!  This function returns an empty GLP problem object,
#!  i.e. a wrapper for the function glp_create_prob
#! @Arguments
#! @Returns a problem object
DeclareGlobalFunction( "GLPK_CREATE_PROBLEM" )

#! @Section Setter functions

#! This section describes setter functions for the problem object.
#! All coefficients can be integers or floats.
#! Note that float bounds can cause problems when computing an integer solution.

#! @Description
#!  Adds <A>n</A> rows to the <A>problem</A>.
#! @Arguments problem,n
#! @Returns index of the first new row
DeclareGlobalFunction( "GLPK_ADD_ROWS" );

#! @BeginGroup
#! @Description
#!  Adds <A>n</A> columns to the <A>problem</A>. The columns
#!  have integer resp. continuus value.
#! @Arguments problem,n
#! @Returns index of the first new column
DeclareGlobalFunction( "GLPK_ADD_COLUMNS" );
#! @Arguments problem,n
DeclareGlobalFunction( "GLPK_ADD_COLUMNS_FLOAT" );
#! @EndGroup

#! @Description
#!  Sets the <A>problem</A> to maximization.
#! @Arguments problem
DeclareGlobalFunction( "GLPK_SET_MAX_PROBLEM" );

#! @Description
#!  Sets the <A>problem</A> to minimization.
#! @Arguments problem
DeclareGlobalFunction( "GLPK_SET_MIN_PROBLEM" );

#! @BeginGroup
#! @Description
#!  Sets the bounds of the <A>n</A>-th row or column of the <A>problem</A> to
#!  <A>lower</A> and <A>upper</A>.
#! @Arguments problem,n,lower,upper
DeclareGlobalFunction( "GLPK_SET_ROW_BOUNDS" );
#! @Arguments problem,n,lower,upper
DeclareGlobalFunction( "GLPK_SET_COLUMN_BOUNDS" );
#! @EndGroup

#! @BeginGroup
#! @Description
#!  Sets the lower bound of the <A>n</A>-th row or column of the <A>problem</A> to
#!  <A>lower</A>.
#! @Arguments problem,n,lower
DeclareGlobalFunction( "GLPK_SET_LOWER_ROW_BOUND" );
#! @Arguments problem,n,lower
DeclareGlobalFunction( "GLPK_SET_LOWER_COLUMN_BOUND" );
#! @EndGroup

#! @BeginGroup
#! @Description
#!  Sets the upper bound of the <A>n</A>-th row or column of the <A>problem</A> to
#!  <A>upper</A>.
#! @Arguments problem,n,upper
DeclareGlobalFunction( "GLPK_SET_UPPER_ROW_BOUND" );
#! @Arguments problem,n,upper
DeclareGlobalFunction( "GLPK_SET_UPPER_COLUMN_BOUND" );
#! @EndGroup

#! @BeginGroup
#! @Description
#!  Sets the value of the <A>n</A>-th row or column of the <A>problem</A> to
#!  <A>value</A>.
#! @Arguments problem,n,value
DeclareGlobalFunction( "GLPK_SET_FIXED_ROW_VALUE" );
#! @Arguments problem,n,value
DeclareGlobalFunction( "GLPK_SET_FIXED_COLUMN_VALUE" );
#! @EndGroup

#! @Description
#!  Sets the coefficient of the <A>n</A>-th column in the target function
#!  of the <A>problem</A> to <A>c</A>.
#!  Note that columns and rows must have been created before.
#! @Arguments problem,n,c
DeclareGlobalFunction( "GLPK_SET_OBJECT_COEFF" );

#! @Description
#!  Sets the coefficient matrix of the <A>problem</A> to <A>matrix</A>.
#!  Note that columns and rows must have been created before.
#! @Arguments problem,matrix
DeclareGlobalFunction( "GLPK_SET_COEFF_MATRIX" );

#! @Section Solving functions

#!  This section describes the functions to solve a problem.
#!  There are in general way to solve a MIP or LP.
#!  First is to solve it as a linear program, so all columns
#!  are treatened like continuus variables.
#!  Second way is to solve it as an MIP, with respect
#!  to the column type.

#! @BeginGroup
#! @Description
#!  Solves the <A>problem</A> as an MIP, without the
#!  presolver enabled or disabled. If the 
#!  presolver is disabled and the problem was not solved
#!  before, this might cause problems. Returns <C>true</C>
#!  if an optimal solution was found, <C>false otherwise</C>.
#! @Arguments problem
#! @Returns <C>true</C> or <C>false</C>
DeclareGlobalFunction( "GLPK_SOLVE_PROBLEM" );
#! @Arguments problem
DeclareGlobalFunction( "GLPK_SOLVE_PROBLEM_WITH_PRESOLVE" );
#! @EndGroup

#! @Description
#!  Solves the <A>problem</A> as an LP with the simplex algorithm, assuming
#!  every column as continous. Returns <C>true</C>
#!  if an optimal solution was found, <C>false otherwise</C>.
#! @Arguments problem
#! @Returns <C>true</C> or <C>false</C>
DeclareGlobalFunction( "GLPK_SOLVE_PROBLEM_SIMPLEX" );

#! @Section Getter functions

#! This section describes methods to read back the solutions to gap.

#! @BeginGroup
#! @Description
#!  If <A>problem</A> is solved, this method returns the optimal value
#!  or the optimal integer value of the target function.
#! @Arguments problem
#! @Returns optimal value
DeclareGlobalFunction( "GLPK_OPTIMAL_VALUE" );
#! @Arguments problem
DeclareGlobalFunction( "GLPK_OPTIMAL_VALUE_FLOAT" );
#! @EndGroup

#! @BeginGroup
#! @Description
#!  If <A>problem</A> is solved, this method returns the optimal solution
#!  or the optimal integer solution of the <A>problem</A> as a list.
#! @Arguments problem
#! @Returns optimal solution
DeclareGlobalFunction( "GLPK_OPTIMAL_SOLUTION" );
#! @Arguments problem
DeclareGlobalFunction( "GLPK_OPTIMAL_SOLUTION_FLOAT" );
#! @EndGroup
