

##
InstallMethod( ViewObj, 
               "for an external GLPK object",
               [ IsExternalGLPKObject ],
  function( r )
    
    Print( "<an external GLPK object>" );
    
end );

##
InstallMethod( Display, 
               "for an external GLPK object",
               [ IsExternalGLPKObject ],
  function( r )
    
    Print( "An external GLPK object.\n" );
    
end );

##
InstallMethod( ViewObj, 
               "for an external GLPK object",
               [ IsExternalGLPKProblem ],
  function( r )
    
    Print( "<an external GLPK problem>" );
    
end );

##
InstallMethod( Display, 
               "for an external GLPK object",
               [ IsExternalGLPKProblem ],
  function( r )
    
    Print( "An external GLPK problem.\n" );
    
end );
