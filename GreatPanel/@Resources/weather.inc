;============== 
;== Measures == 
;==============

[MeasureWeatherJSON]
Measure=WebParser
UpdateRate=900
URL=#URL#
RegExp=#Regex#
FinishAction=[!HideMeterGroup ErrorMeters][!ShowMeterGroup DisplayMeters]

[MeasureIconCode]
Measure=WebParser
URL=[MeasureWeatherJSON]
StringIndex=4

[MeasureTemperature]
Measure=WebParser
URL=[MeasureWeatherJSON]
StringIndex=5

[MeasureTemperatureRessentie]
Measure=WebParser
URL=[MeasureWeatherJSON]
StringIndex=6

[MeasureDec]
Measure=WebParser
URL=[MeasureWeatherJSON]
StringIndex=3

[MeasureTempRounded]
Measure=Calc
Formula=Round([MeasureTemperature:])
; Les ':' forcent la conversion numérique
DynamicVariables=1

[MeasureTempRessentieRounded]
Measure=Calc
Formula=Round([MeasureTemperatureRessentie:])
; Les ':' forcent la conversion numérique
DynamicVariables=1

;==============
;== Meters ==
;==============

; En cas d'erreur
[MeterErrorIcon]
Meter=Image
Group=ErrorMeters
ImageName=#@#Images\Meteo\unknown.png
X=230
Y=110
W=35
H=35
Antialias=1

; Icône météo
[MeterIcon]
Meter=Image
Group=DisplayMeters
MeasureName=MeasureIconCode
ImageName=[MeasureIconCode].png
ImagePath=#@#Images\Meteo\
X=230
Y=110
W=35
H=35
Antialias=1
DynamicVariables=1
Hidden=0

[MeterTemperature]
Meter=String
MeasureName=MeasureTempRounded
Group=DisplayMeters
FontFace=#Font#
FontSize=10
FontColor=179,179,179,255
Text="%1 Deg"
StringAlign=center
X=245
Y=100r
AntiAlias=1
DynamicVariables=1

[MeterDec]
Meter=String
MeasureName=MeasureDec
Group=DisplayMeters
FontFace=#Font#
FontSize=10
FontColor=179,179,179,255
StringAlign=center
X=0r
Y=15r
AntiAlias=1
DynamicVariables=1

;[MeterRessentie]
;Meter=String
;MeasureName=MeasureTempRessentieRounded
;Group=DisplayMeters
;FontFace=#Font#
;FontSize=10
;FontColor=179,179,179,255
;Text="%1 Ressentie"
;StringAlign=center
;X=200
;Y=135
;AntiAlias=1
;DynamicVariables=1