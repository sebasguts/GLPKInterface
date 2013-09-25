/***************************************************************************
**
**  polymake_main.cpp       Sebastian Gutsche       A file to provide Polymake
**                                                  to GAP.
**
*/

#include "loadgap.h"

static const char * Revision_glpk_main_c =
   "polymake_main.cpp, V0.1";

# define MORE_TESTS 1




#include <iostream>
#include <map>
#include <utility>
#include <glpk.h>

#include "GLPK_data.h"

#include "GLPK_tools.h"

using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::pair;

Obj TheTypeExternalGLPKObject;
Obj TheTypeExternalGLPKProblem;

Obj FuncGLPK_CREATE_PROBLEM( Obj self ) {
  
  Obj ret_val = NewGLPKProblem( T_GLPK_EXTERNAL_PROBLEM );
  
  GLPKOBJ_SET_PROBOBJ(ret_val, glp_create_prob() );
  
  return ret_val;

}

Obj FuncGLPK_ADD_ROWS( Obj self, Obj problem, Obj rows ){
    
    return real_GLPK_add_rows( problem, rows );
    
}

Obj FuncGLPK_ADD_COLUMNS( Obj self, Obj problem, Obj cols ){
    
    return real_GLPK_add_columns( problem, cols, true );
    
}

Obj FuncGLPK_ADD_COLUMNS_FLOAT( Obj self, Obj problem, Obj cols ){
    
    return real_GLPK_add_columns( problem, cols, false );
    
}

Obj FuncGLPK_SET_MAX_PROBLEM( Obj self, Obj problem ){
    
    return real_GLPK_set_max( problem );
    
}

Obj FuncGLPK_SET_MIN_PROBLEM( Obj self, Obj problem ){
    
    return real_GLPK_set_min( problem );
    
}

Obj FuncGLPK_SET_ROW_BOUNDS( Obj self, Obj problem, Obj row_number, Obj lower, Obj upper ){
    
    return real_GLPK_set_row_bounds( problem, row_number, lower, upper, GLP_DB );
    
}

Obj FuncGLPK_SET_UPPER_ROW_BOUND( Obj self, Obj problem, Obj row_number, Obj upper ){
    
    return real_GLPK_set_row_bounds( problem, row_number, upper, upper, GLP_UP);
    
}

Obj FuncGLPK_SET_LOWER_ROW_BOUND( Obj self, Obj problem, Obj row_number, Obj lower ){
    
    return real_GLPK_set_row_bounds( problem, row_number, lower, lower, GLP_LO );
    
}

Obj FuncGLPK_SET_FIXED_ROW_VALUE( Obj self, Obj problem, Obj row_number, Obj value ){
    
    return real_GLPK_set_row_bounds( problem, row_number, value, value, GLP_FX );
    
}

Obj FuncGLPK_SET_COLUMN_BOUNDS( Obj self, Obj problem, Obj col_number, Obj lower, Obj upper ){
    
    return real_GLPK_set_col_bounds( problem, col_number, lower, upper, GLP_DB );
    
}

Obj FuncGLPK_SET_UPPER_COLUMN_BOUND( Obj self, Obj problem, Obj col_number, Obj upper ){
    
    return real_GLPK_set_col_bounds( problem, col_number, upper, upper, GLP_UP);
    
}

Obj FuncGLPK_SET_LOWER_COLUMN_BOUND( Obj self, Obj problem, Obj col_number, Obj lower ){
    
    return real_GLPK_set_col_bounds( problem, col_number, lower, lower, GLP_LO );
    
}

Obj FuncGLPK_SET_FIXED_COLUMN_VALUE( Obj self, Obj problem, Obj col_number, Obj value ){
    
    return real_GLPK_set_col_bounds( problem, col_number, value, value, GLP_FX );
    
}

Obj FuncGLPK_SET_OBJECT_COEFF( Obj self, Obj problem, Obj col_number, Obj coeff ){
    
    return real_GLPK_set_obj_coeff( problem, col_number, coeff );
    
}

Obj FuncGLPK_SET_COEFF_MATRIX( Obj self, Obj problem, Obj matrix ){
    
    return real_GLPK_set_coeff_matrix( problem, matrix );
    
}

Obj FuncGLPK_SOLVE_PROBLEM( Obj self, Obj problem ){
    
    return real_GLPK_solve_integer_problem( problem, false );
    
}

Obj FuncGLPK_SOLVE_PROBLEM_WITH_PRESOLVE( Obj self, Obj problem ){
    
    return real_GLPK_solve_integer_problem( problem, true );
    
}

Obj FuncGLPK_SOLVE_PROBLEM_SIMPLEX( Obj self, Obj problem ){
    
    return real_GLPK_solve_problem_simplex( problem );
    
}

Obj FuncGLPK_OPTIMAL_VALUE( Obj self, Obj problem ){
    
    return real_GLPK_optimal_value( problem );
    
}

Obj FuncGLPK_OPTIMAL_SOLUTION( Obj self, Obj problem ){
    
    return real_GLPK_optimal_solution( problem );
    
}

Obj FuncGLPK_OPTIMAL_VALUE_FLOAT( Obj self, Obj problem ){
    
    return real_GLPK_optimal_value_float( problem );
    
}

Obj FuncGLPK_OPTIMAL_SOLUTION_FLOAT( Obj self, Obj problem ){
    
    return real_GLPK_optimal_solution_float( problem );
    
}

Obj FuncGLPK_GET_NUMBER_OF_COLUMNS( Obj self, Obj problem ){
    
    return real_GLPK_get_col_number( problem );
    
}


/******************************************************************************
*V  GVarFuncs . . . . . . . . . . . . . . . . . . list of functions to export
*/
static StructGVarFunc GVarFuncs [] = {

    { "GLPK_CREATE_PROBLEM", 0, "",
    (Obj(*)())FuncGLPK_CREATE_PROBLEM,
    "GLPKInterface_main.cpp:GLPK_CREATE_PROBLEM" },

    { "GLPK_ADD_ROWS", 2, "problem,rows",
    (Obj(*)())FuncGLPK_ADD_ROWS,
    "GLPKInterface_main.cpp:GLPK_ADD_ROWS" },
    
    { "GLPK_ADD_COLUMNS", 2, "problem,cols",
    (Obj(*)())FuncGLPK_ADD_COLUMNS,
    "GLPKInterface_main.cpp:GLPK_ADD_COLUMNS" },
    
    { "GLPK_ADD_COLUMNS_FLOAT", 2, "problem,cols",
    (Obj(*)())FuncGLPK_ADD_COLUMNS_FLOAT,
    "GLPKInterface_main.cpp:GLPK_ADD_COLUMNS_FLOAT" },
    
    { "GLPK_SET_MAX_PROBLEM", 1, "problem",
    (Obj(*)())FuncGLPK_SET_MAX_PROBLEM,
    "GLPKInterface_main.cpp:GLPK_SET_MAX_PROBLEM" },
    
    { "GLPK_SET_MIN_PROBLEM", 1, "problem",
    (Obj(*)())FuncGLPK_SET_MIN_PROBLEM,
    "GLPKInterface_main.cpp:GLPK_SET_MIN_PROBLEM" },
    
    { "GLPK_SET_ROW_BOUNDS", 4, "problem,row_number,lower,upper",
    (Obj(*)())FuncGLPK_SET_ROW_BOUNDS,
    "GLPKInterface_main.cpp:GLPK_SET_ROW_BOUNDS" },
    
    { "GLPK_SET_LOWER_ROW_BOUND", 3, "problem,row_number,lower",
    (Obj(*)())FuncGLPK_SET_LOWER_ROW_BOUND,
    "GLPKInterface_main.cpp:GLPK_SET_LOWER_ROW_BOUND" },
    
    { "GLPK_SET_UPPER_ROW_BOUND", 3, "problem,row_number,upper",
    (Obj(*)())FuncGLPK_SET_UPPER_ROW_BOUND,
    "GLPKInterface_main.cpp:GLPK_SET_UPPER_ROW_BOUND" },
    
    { "GLPK_SET_FIXED_ROW_VALUE", 3, "problem,row_number,value",
    (Obj(*)())FuncGLPK_SET_FIXED_ROW_VALUE,
    "GLPKInterface_main.cpp:GLPK_SET_FIXED_ROW_VALUE" },
    
    { "GLPK_SET_COLUMN_BOUNDS", 4, "problem,col_number,lower,upper",
    (Obj(*)())FuncGLPK_SET_COLUMN_BOUNDS,
    "GLPKInterface_main.cpp:GLPK_SET_COLUMN_BOUNDS" },
    
    { "GLPK_SET_LOWER_COLUMN_BOUND", 3, "problem,col_number,lower",
    (Obj(*)())FuncGLPK_SET_LOWER_COLUMN_BOUND,
    "GLPKInterface_main.cpp:GLPK_SET_LOWER_COLUMN_BOUND" },
    
    { "GLPK_SET_UPPER_COLUMN_BOUND", 3, "problem,col_number,upper",
    (Obj(*)())FuncGLPK_SET_UPPER_COLUMN_BOUND,
    "GLPKInterface_main.cpp:GLPK_SET_UPPER_COLUMN_BOUND" },
    
    { "GLPK_SET_FIXED_COLUMN_VALUE", 3, "problem,col_number,value",
    (Obj(*)())FuncGLPK_SET_FIXED_COLUMN_VALUE,
    "GLPKInterface_main.cpp:GLPK_SET_FIXED_COLUMN_VALUE" },
    
    { "GLPK_SET_OBJECT_COEFF", 3, "problem,col_number,coeff",
    (Obj(*)())FuncGLPK_SET_OBJECT_COEFF,
    "GLPKInterface_main.cpp:GLPK_SET_OBJECT_COEFF" },
    
    { "GLPK_SET_COEFF_MATRIX", 2, "problem,matrix",
    (Obj(*)())FuncGLPK_SET_COEFF_MATRIX,
    "GLPKInterface_main.cpp:GLPK_SET_COEFF_MATRIX" },
    
    { "GLPK_SOLVE_PROBLEM", 1, "problem",
    (Obj(*)())FuncGLPK_SOLVE_PROBLEM,
    "GLPKInterface_main.cpp:GLPK_SOLVE_PROBLEM" },
    
    { "GLPK_SOLVE_PROBLEM_WITH_PRESOLVE", 1, "problem",
    (Obj(*)())FuncGLPK_SOLVE_PROBLEM_WITH_PRESOLVE,
    "GLPKInterface_main.cpp:GLPK_SOLVE_PROBLEM_WITH_PRESOLVE" },
    
    { "GLPK_SOLVE_PROBLEM_SIMPLEX", 1, "problem",
    (Obj(*)())FuncGLPK_SOLVE_PROBLEM_SIMPLEX,
    "GLPKInterface_main.cpp:GLPK_SOLVE_PROBLEM_SIMPLEX" },
    
    { "GLPK_OPTIMAL_VALUE", 1, "problem",
    (Obj(*)())FuncGLPK_OPTIMAL_VALUE,
    "GLPKInterface_main.cpp:GLPK_OPTIMAL_VALUE" },
    
    { "GLPK_OPTIMAL_VALUE_FLOAT", 1, "problem",
    (Obj(*)())FuncGLPK_OPTIMAL_VALUE_FLOAT,
    "GLPKInterface_main.cpp:GLPK_OPTIMAL_VALUE_FLOAT" },
    
    { "GLPK_OPTIMAL_SOLUTION", 1, "problem",
    (Obj(*)())FuncGLPK_OPTIMAL_SOLUTION,
    "GLPKInterface_main.cpp:GLPK_OPTIMAL_SOLUTION" },
    
    { "GLPK_OPTIMAL_SOLUTION_FLOAT", 1, "problem",
    (Obj(*)())FuncGLPK_OPTIMAL_SOLUTION_FLOAT,
    "GLPKInterface_main.cpp:GLPK_OPTIMAL_SOLUTION_FLOAT" },
    
    { "GLPK_GET_NUMBER_OF_COLUMNS", 1, "problem",
    (Obj(*)())FuncGLPK_GET_NUMBER_OF_COLUMNS,
    "GLPKInterface_main.cpp:GLPK_GET_NUMBER_OF_COLUMNS" },
    
  { 0 }
};

/******************************************************************************
*F  InitKernel( <module> )  . . . . . . . . initialise kernel data structures
*/
static Int InitKernel ( StructInitInfo *module )
{
    /* init filters and functions                                          */
    InitHdlrFuncsFromTable( GVarFuncs );
    

//     InitCopyGVar( "TheTypeExternalPolymakeCone", &TheTypeExternalPolymakeCone );
//     InitCopyGVar( "TheTypeExternalPolymakeFan", &TheTypeExternalPolymakeFan );
//     InitCopyGVar( "TheTypeExternalPolymakePolytope", &TheTypeExternalPolymakePolytope );
//     InitCopyGVar( "TheTypeExternalPolymakeTropicalHypersurface", &TheTypeExternalPolymakeTropicalHypersurface );
//     InitCopyGVar( "TheTypeExternalPolymakeTropicalPolytope", &TheTypeExternalPolymakeTropicalPolytope );
// 
//     InfoBags[T_POLYMAKE].name = "ExternalPolymakeObject";
//     InitMarkFuncBags(T_POLYMAKE, &MarkOneSubBags);
//     InitFreeFuncBag(T_POLYMAKE, &ExternalPolymakeObjectFreeFunc);
//     TypeObjFuncs[T_POLYMAKE] = &ExternalPolymakeObjectTypeFunc;

    InitCopyGVar( "TheTypeExternalGLPKObject", &TheTypeExternalGLPKObject );
    InitCopyGVar( "TheTypeExternalGLPKProblem", &TheTypeExternalGLPKProblem );
    
    InfoBags[T_SPARE1].name = "ExternalGLPKObject";
    InitMarkFuncBags(T_SPARE1, &MarkOneSubBags);
    InitFreeFuncBag(T_SPARE1, &ExternalGLPKObjectFreeFunc);
    TypeObjFuncs[T_SPARE1] = &ExternalGLPKObjectTypeFunc;
    
    InitGVarFuncsFromTable(GVarFuncs);
    
    /* return success                                                      */
    return 0;
}

/******************************************************************************
*F  InitLibrary( <module> ) . . . . . . .  initialise library data structures
*/
static Int InitLibrary ( StructInitInfo *module )
{
//     Int i, gvar;
//     
//     // We start with initialising the polymake classes.
//     akt_data.initialized = false;
// //     akt_data.main_polymake_session = new polymake::Main;
// //     akt_data.main_polymake_scope = new polymake::perl::Scope(akt_data.main_polymake_session->newScope());
// //     akt_data.main_polymake_session->set_application("polytope");
// //     akt_data.main_polymake_session->set_custom("$Verbose::scheduler",1);
//     //This is pretty slow.
//     //akt_data.polymake_objects = new map<int, pm::perl::Object*>;
//     //akt_data.new_polymake_object_number=0;
//     // We now have everything to handle polymake, lets do the gapthings
// 
//     /* init filters and functions
//        we assign the functions to components of a record "IO"         */
//     for ( i = 0; GVarFuncs[i].name != 0;  i++ ) {
//       gvar = GVarName(GVarFuncs[i].name);
//       AssGVar(gvar,NewFunctionC( GVarFuncs[i].name, GVarFuncs[i].nargs,
//                                  GVarFuncs[i].args, GVarFuncs[i].handler ));
//       MakeReadOnlyGVar(gvar);
//     }

    
    /* return success                                                      */
    return 0;
}

/******************************************************************************
*F  InitInfopl()  . . . . . . . . . . . . . . . . . table of init functions
*/
static StructInitInfo module = {
 /* type        = */ MODULE_DYNAMIC,
 /* name        = */ "glpk_main",
 /* revision_c  = */ 0,
 /* revision_h  = */ 0,
 /* version     = */ 0,
 /* crc         = */ 0,
 /* initKernel  = */ InitKernel,
 /* initLibrary = */ InitLibrary,
 /* checkInit   = */ 0,
 /* preSave     = */ 0,
 /* postSave    = */ 0,
 /* postRestore = */ 0
};

extern "C" {

StructInitInfo * Init__Dynamic ( void )
{
  module.revision_c = Revision_glpk_main_c;
  return &module;
}

}


/*
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
