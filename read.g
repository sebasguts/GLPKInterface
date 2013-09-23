ReadPackage( "GLPKInterface", "gap/GLPKInterface.gi");

if (not IsBound(DummyFunc)) and
   (Filename(DirectoriesPackagePrograms("GLPKInterface"), "glpkinterface_main.so") <> fail) then
  LoadDynamicModule(Filename(DirectoriesPackagePrograms("GLPKInterface"), "glpkinterface_main.so"));
fi;

if (not IsBound(DummyFunc)) then
    Error( "Failed to load compiled dynamic module.\n" );
fi;
