ReadPackage( "GLPKInterface", "gap/GLPKInterface.gi");

if (not IsBound(CreateGLPKProblem)) and
   (Filename(DirectoriesPackagePrograms("GLPKInterface"), "glpkinterface_main.so") <> fail) then
  LoadDynamicModule(Filename(DirectoriesPackagePrograms("GLPKInterface"), "glpkinterface_main.so"));
fi;

if (not IsBound(CreateGLPKProblem)) then
    Error( "Failed to load compiled dynamic module.\n" );
fi;
