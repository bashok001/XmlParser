echo off
cls
echo "Building XMLParser App"
echo ----------------------------------------------
devenv XMLParser.sln /rebuild debug
copy Debug\Executive.exe .