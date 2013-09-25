#############################################################################
##
##                                           GLPKInterface package
##
##  Copyright 2013, Sebastian Gutscche, TU Kaiserslautern
##
#############################################################################

##
InstallGlobalFunction( GLPK_SET_OBJECT_COEFFS_AS_LIST,
                       
  function( problem, coeff_list )
    local i;
    
    if not IsExternalGLPKProblem( problem ) or not IsList( coeff_list ) then
        
        Error( "wrong input" );
        
        return false;
        
    fi;
    
    if not Length( coeff_list ) = GLPK_GET_NUMBER_OF_COLUMNS( problem ) then
        
        Error( "wrong number of coeffs" );
        
        return false;
        
    fi;
    
    for i in [ 1 .. Length( coeff_list ) ] do
        
        GLPK_SET_OBJECT_COEFF( problem, i, coeff_list[ i ] );
        
    od;
    
    return true;
    
end );
