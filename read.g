ReadPackage( "GLPKInterface", "gap/GLPKInterface.gi");

if (not IsBound(GLPK_CREATE_PROBLEM)) and
   (Filename(DirectoriesPackagePrograms("GLPKInterface"), "glpkinterface_main.so") <> fail) then
  LoadDynamicModule(Filename(DirectoriesPackagePrograms("GLPKInterface"), "glpkinterface_main.so"));
fi;

if (not IsBound(GLPK_CREATE_PROBLEM)) then
    Error( "Failed to load compiled dynamic module.\n" );
fi;

ReadPackage( "GLPKInterface", "gap/GLPKExtendedFunctions.gi" );