@SET CURRENT_PATH=%~dp0
@SET MAKE_CURRENT_PATH=%CURRENT_PATH:\=/%
@SET MAKE_CURRENT_PATH=%MAKE_CURRENT_PATH:~0,-1%
%CURRENT_PATH%..\..\gnumake CURDIR=%MAKE_CURRENT_PATH% -f %CURRENT_PATH%workspace\gmake\Keypad4in4out.gmak -r -R %1

pause
