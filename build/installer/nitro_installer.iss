[Setup]
AppName=NITRO
AppVersion=1.5-RC5
AppVerName=NITRO 1.5-RC5
AppPublisherURL=http://nitro-nitf.sourceforge.net/
AppSupportURL=http://nitro-nitf.sourceforge.net/
AppUpdatesURL=http://sourceforge.net/projects/nitro-nitf/
DefaultDirName={pf}\nitro-nitf\
DefaultGroupName=NITRO
AllowNoIcons=yes
LicenseFile=..\..\COPYING.LESSER
Compression=lzma
SolidCompression=yes
ChangesEnvironment=yes
OutputBaseFilename=nitro-1.5-rc5-setup
UninstallDisplayName=NITRO 1.5-RC5
SetupIconFile=NITRO.ico
WizardSmallImageFile=NITRO_small.bmp
WizardImageFile=NITRO.bmp
WizardImageStretch=no

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Types]
Name: "full"; Description: "Full Installation"
Name: "compact"; Description: "Compact Installation"
Name: "custom"; Description: "Custom Installation"; Flags: iscustom

[Components]
Name: "core"; Description: "Core Library and Header Files"; Types: full compact custom; Flags: fixed
Name: "java"; Description: "Java Bindings"; Types: full compact
Name: "plugins"; Description: "Plugins"; Types: full compact
Name: "plugins\tres"; Description: "TREs"; Types: full compact
Name: "plugins\jpeg"; Description: "JPEG"; Types: full compact
Name: "plugins\jasper"; Description: "JasPer JPEG 2000"; Types: full compact
Name: "samples"; Description: "Code Samples"; Types: full
Name: "samples\c"; Description: "C"; Types: full
Name: "samples\java"; Description: "Java"; Types: full
Name: "tests"; Description: "Test Applications"; Types: full

[Files]
Source: "..\..\COPYING.LESSER"; DestDir: "{app}"; Flags: ignoreversion; Components: core;
Source: "..\..\c\nitf\lib\win32\nitf-c.lib"; DestDir: "{app}\lib"; Flags: ignoreversion; Components: core;
Source: "..\..\c\nitf\include\*"; DestDir: "{app}\include"; Flags: ignoreversion recursesubdirs createallsubdirs; Components: core;
Source: "..\..\c\nitf\shared\*.dll"; DestDir: "{app}\plugins"; Flags: ignoreversion recursesubdirs; Components: plugins\tres;
Source: "..\..\external\libjpeg-plugins\lib\win32\*.dll"; DestDir: "{app}\plugins"; Flags: ignoreversion recursesubdirs skipifsourcedoesntexist; Components: plugins\jpeg;
Source: "..\..\external\jasper-plugins\lib\win32\*.dll"; DestDir: "{app}\plugins"; Flags: ignoreversion recursesubdirs skipifsourcedoesntexist; Components: plugins\jasper;
Source: "..\..\c\nitf\tests\*.c"; DestDir: "{app}\samples\c"; Flags: ignoreversion recursesubdirs; Components: samples\c;
Source: "..\..\c\nitf\tests\*.exe"; DestDir: "{app}\tests"; Flags: ignoreversion recursesubdirs; Components: tests;
Source: "..\..\c\nitf.jni\lib\win32\nitf.jni-c.dll"; DestDir: "{app}\bin"; Flags: ignoreversion; Components: java;
Source: "..\..\java\nitf\target\*.jar"; DestDir: "{app}\bin"; Flags: ignoreversion; Components: java;
Source: "..\..\java\nitf\src\test\java\Test*.java"; DestDir: "{app}\samples\java"; Flags: ignoreversion skipifsourcedoesntexist; Components: samples\java;

[Registry]
Root: HKCU; Subkey: "Environment"; ValueType: string; ValueName: "NITF_PLUGIN_PATH"; ValueData: "{app}\plugins"; Flags: uninsdeletekeyifempty; Components: plugins;

[Icons]
Name: "{group}\{cm:UninstallProgram,NITRO}"; Filename: "{uninstallexe}"

