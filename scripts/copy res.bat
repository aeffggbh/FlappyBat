@echo off
echo %1 SolutionDir
echo %2 OutDir

del "%~2FlappyBird.pdb"

xcopy "%~1res" "%~2res" /i/y/s