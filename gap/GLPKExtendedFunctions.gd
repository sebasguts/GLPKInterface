#############################################################################
##
##                                           GLPKInterface package
##
##  Copyright 2013, Sebastian Gutscche, TU Kaiserslautern
##
#############################################################################

#! @Description
#!  Sets the coefficients of the target function of <A>problem</A>
#!  to the elements of <A>list</A>. Note that the columns must have
#!  been created before, or the method gives an error.
#! @Arguments problem,list
#! @ChapterInfo Functions, Convinience functions
DeclareGlobalFunction( "GLPK_SET_OBJECT_COEFFS_AS_LIST" );
