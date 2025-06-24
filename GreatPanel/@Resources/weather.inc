[Variables]
@IncludeVariables=#@#variables.inc

;============== 
;== Measures == 
;==============

[MeasureWeatherJSON]
Measure=WebParser
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

[MeasureTemperatureFeel]
Measure=WebParser
URL=[MeasureWeatherJSON]
StringIndex=6

[MeasureDec]
Measure=WebParser
URL=[MeasureWeatherJSON]
StringIndex=3

[MeasureCountry]
Measure=WebParser
URL=[MeasureWeatherJSON]
StringIndex=9

[MeasureTempRounded]
Measure=Calc
Formula=Round([MeasureTemperature:])
; Les ':' forcent la conversion numérique
DynamicVariables=1

[MeasureTempFeelRounded]
Measure=Calc
Formula=Round([MeasureTemperatureFeel:])
; Les ':' forcent la conversion numérique
DynamicVariables=1


;==============
;== Meters ==
;==============

; En cas d'erreur
[MeterErrorIcon]
Meter=Image
Group=ErrorMeters
ImageName=#@#Images\Meteo\light\unknown.png
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
ImagePath=#@#Images\Meteo\light
X=0r
Y=0r
W=35
H=35
Antialias=1
DynamicVariables=1
Hidden=0

[MeterTemperature]
Meter=String
MeasureName=MeasureTempRounded
MeasureName2=MeasureTempFeelRounded
Group=DisplayMeters
FontFace=#Font#
FontSize=10
FontColor=179,179,179,255
StringAlign=center
Text="%1 temp %2 Feel"
X=245
Y=95r
AntiAlias=1
DynamicVariables=1

;[MeterVille]
;Meter=String
;MeasureName=MeasureCountry
;Group=DisplayMeters
;FontFace=#Font#
;FontSize=10
;FontColor=179,179,179,255
;StringAlign=center
;X=0r
;Y=15r
;AntiAlias=1
;DynamicVariables=1

[MeterDec]
Meter=String
MeasureName=MeasureCountry
MeasureName2=MeasureDec
Text="%1 %2"
Group=DisplayMeters
FontFace=#Font#
FontSize=10
FontColor=179,179,179,255
StringAlign=center
X=0r
Y=15r
AntiAlias=1
DynamicVariables=1
