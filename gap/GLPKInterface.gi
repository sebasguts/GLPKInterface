InstallGlobalFunction( GLPKInterface_Example,
function()
	Print( "This is a placeholder function, replace it with your own code.\n" );
end );

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
