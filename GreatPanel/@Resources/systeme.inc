[measureCPU]
Measure=CPU
Processor=0

[measureRAM]
Measure=PhysicalMemory
UpdateDivider=20

[measureSWAP]
Measure=SWAPMemory
UpdateDivider=20

[styleBar]
BarColor=46,50,97,255
BarOrientation=HORIZONTAL
SolidColor=255,255,255,50

[styleLeftText]
FontFace=#Font#
FontSize=11
FontColor=179,179,179,255
AntiAlias=1
StringAlign=left

[styleRightText]
FontFace=#Font#
FontSize=11
FontColor=179,179,179,255
AntiAlias=1
StringAlign=right

[meterLabelCPU]
Meter=STRING
MeterStyle=styleLeftText
X=180
Y=170
Text="CPU Usage"

[meterValueCPU]
Meter=STRING
MeterStyle=styleRightText
MeasureName=measureCPU
X=322
Y=r
Text="%1%"

[meterBarCPU]
Meter=BAR
MeterStyle=styleBar
MeasureName=measureCPU
X=180
Y=15r
W=142
H=1

[meterLabelRAM]
Meter=STRING
MeterStyle=styleLeftText
X=180
Y=190
Text="RAM Usage"

[meterValueRAM]
Meter=STRING
MeterStyle=styleRightText
MeasureName=measureRAM
X=322
Y=r
Text="%1%"
Percentual=1

[meterBarRAM]
Meter=BAR
MeterStyle=styleBar
MeasureName=measureRAM
X=180
Y=15r
W=142
H=1

[meterLabelSWAP]
Meter=STRING
MeterStyle=styleLeftText
X=180
Y=210
Text="SWAP Usage"

[meterValueSWAP]
Meter=STRING
MeterStyle=styleRightText
MeasureName=measureSWAP
X=322
Y=r
Text="%1%"
Percentual=1

[meterBarSWAP]
Meter=BAR
MeterStyle=styleBar
MeasureName=measureSWAP
X=180
Y=15r
W=142
H=1