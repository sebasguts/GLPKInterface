


GLPKExternalObjectFamily := NewFamily( "ExternalGLPKObjectFamily" );

## Maybe this is the wrong place, but I need this category.
## If there is time, there need to be a new package created.

DeclareCategory( "IsExternalObject", IsObject );

DeclareCategory( "IsExternalGLPKObject", IsExternalObject );
DeclareCategory( "IsExternalGLPKProblem", IsExternalObject );

TheTypeExternalGLPKObject := NewType( GLPKExternalObjectFamily, IsExternalGLPKObject );
TheTypeExternalGLPKProblem := NewType( GLPKExternalObjectFamily, IsExternalGLPKProblem );
