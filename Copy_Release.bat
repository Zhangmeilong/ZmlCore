@echo on
echo "copy Engine to HCTZPlatform"
xcopy D:\ZmlCodes\ZmlCore\Sdk\bin\Lanuch D:\ZmlCodes\ZmlCore\Output_Exe\Release /s /e
xcopy D:\ZmlCodes\ZmlCore\Sdk\bin\Utility D:\ZmlCodes\ZmlCore\Output_Exe\Release /s /e
xcopy D:\ZmlCodes\ZmlCore\Sdk\bin\Core D:\ZmlCodes\ZmlCore\Output_Exe\Release /s /e
pause