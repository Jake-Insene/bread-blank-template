@echo on

:: %1 Workspace Folder

:: Copy assets
cmake -E copy_directory %1/bread/assets/ %1/assets/


:: Compiling shaders
python tools/compile_shaders.py %1