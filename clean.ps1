Write-Host "Cleaning build files"
Remove-Item -Recurse -Force "build"
Remove-Item -Recurse -Force "CMakeFiles"
Remove-Item -Force "CMakeCache.txt"
