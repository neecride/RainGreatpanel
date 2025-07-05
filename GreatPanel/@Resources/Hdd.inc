[Variables]
@IncludeVariables=#@#variables.inc

; --- Système ---
[MeasureCPU]
Measure=CPU

; ---------- MESURES ADDITIONNELLES ----------
[MeasureTotalDiskC]
Measure=FreeDiskSpace
Drive=C:
Total=1

[MeasureUsedDiskC]
Measure=FreeDiskSpace
Drive=C:
InvertMeasure=1

[MeasureFreeDiskC]
Measure=FreeDiskSpace
Drive=C:

[MeasureTotalDiskD]
Measure=FreeDiskSpace
Drive=D:
Total=1

[MeasureUsedDiskD]
Measure=FreeDiskSpace
Drive=D:
InvertMeasure=1

[MeasureFreeDiskD]
Measure=FreeDiskSpace
Drive=D:

; ---------- BARRE CIRCULAIRE (DISQUE DUR) C: ----------
[MeterDiskOutlineC]
Meter=Roundline
MeasureName=MeasureTotalDiskC
X=174
Y=19
W=60
H=60
StartAngle=4.712
RotationAngle=6.283
LineLength=37
LineStart=30
LineColor=179,179,179,100
Solid=1
AntiAlias=1

[MeterDiskFillC]
Meter=Roundline
MeasureName=MeasureUsedDiskC
X=0r
Y=0r
W=60
H=60
StartAngle=4.712
RotationAngle=6.283
LineLength=37
LineStart=30
LineColor=46,50,97,255
Solid=1
AntiAlias=1

[MeterDiskTextC]
Meter=String
MeasureName=MeasureFreeDiskC
Text="%1B"
FontFace=#font#
FontSize=12
FontColor=0,0,0,255
X=205
Y=35
AntiAlias=1
NumOfDecimals=1
AutoScale=1
StringAlign=Center

[MeterDiskLabelC]
Meter=String
Text="DISK C:"
FontFace=#font#
FontSize=10
FontColor=0,0,0,255
X=205
Y=1R
AntiAlias=1
StringAlign=Center

; ---------- BARRE CIRCULAIRE (DISQUE DUR) D: ----------
[MeterDiskOutlineD]
Meter=Roundline
MeasureName=MeasureTotalDiskD
X=256
Y=19
W=60
H=60
StartAngle=4.712
RotationAngle=6.283
LineLength=37
LineStart=30
LineColor=179,179,179,100
Solid=1
AntiAlias=1

[MeterDiskFillD]
Meter=Roundline
MeasureName=MeasureUsedDiskD
X=0r
Y=0r
W=60
H=60
StartAngle=4.712
RotationAngle=6.283
LineLength=37
LineStart=30
LineColor=46,50,97,255
Solid=1
AntiAlias=1

[MeterDiskTextD]
Meter=String
MeasureName=MeasureFreeDiskD
Text="%1B"
FontFace=#font#
FontSize=12
FontColor=0,0,0,255
X=286
Y=35
AntiAlias=1
NumOfDecimals=1
AutoScale=1
StringAlign=Center

[MeterDiskLabelD]
Meter=String
Text="DISK D:"
FontFace=#font#
FontSize=10
FontColor=0,0,0,255
X=286
Y=1R
AntiAlias=1
StringAlign=Center


; ---------- BARRE CIRCULAIRE (CPU) ----------
;[MeterCPUOutline]
;Meter=Roundline
;X=256
;Y=18
;W=60
;H=60
;StartAngle=4.712
;RotationAngle=6.283
;LineLength=36
;LineStart=29
;LineColor=179,179,179,100
;Solid=1
;AntiAlias=1

;[MeterCPUFill]
;Meter=Roundline
;MeasureName=MeasureCPU
;X=0r
;Y=0r
;W=60
;H=60
;StartAngle=4.712
;RotationAngle=6.283
;LineLength=36
;LineStart=29
;LineColor=65,105,225,220
;Solid=1
;AntiAlias=1

;[MeterCPUText]
;Meter=String
;MeasureName=MeasureCPU
;Text="%1%"
;FontFace=#font#
;FontSize=12
;FontColor=0,0,0,255
;X=288
;Y=35
;AntiAlias=1
;StringAlign=Center

;[MeterCPULabel]
;Meter=String
;Text="CPU"
;FontFace=#font#
;FontSize=10
;FontColor=0,0,0,255
;X=286
;Y=1R
;AntiAlias=1
;StringAlign=Center
