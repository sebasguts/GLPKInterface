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

using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::pair;

Obj TheTypeExternalGLPKObject;
Obj TheTypeExternalGLPKProblem;

Obj FuncDummyFunc( Obj self ) {
  
  glp_prob * test = glp_create_prob();
  
  Obj ret_val = NewGLPKProblem( T_GLPK_EXTERNAL_PROBLEM );
  
  GLPKOBJ_SET_PROBOBJ(ret_val, test);
  
  return ret_val;

}


/******************************************************************************
*V  GVarFuncs . . . . . . . . . . . . . . . . . . list of functions to export
*/
static StructGVarFunc GVarFuncs [] = {

    { "DummyFunc", 0, "",
    (Obj(*)())FuncDummyFunc,
    "GLPKInterface_main.cpp:DummyFunc" },
    
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
