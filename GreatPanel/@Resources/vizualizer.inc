[Rainmeter]
Update=50  ; Réduit la fréquence de mise à jour (20 FPS au lieu de 60)
OnUnfocusAction=[!DisableMeasureGroup AudioMeasures][!HideMeterGroup Visualizer]
OnFocusAction=[!EnableMeasureGroup AudioMeasures][!ShowMeterGroup Visualizer]

[Variables]
BarCount=20  ; Réduit le nombre de bandes
BarWidth=12
BarGap=2
Height=80
Color=255,255,255,180
FFTSize=512  ; Taille FFT plus petite
FFTAttack=50  ; Lissage
FFTDecay=150  ; Lissage
Smoothing=1  ; Activation du lissage

[MeasureAudio]
Measure=Plugin
Plugin=AudioLevel
Port=Output
FFTSize=#FFTSize#
FFTAttack=#FFTAttack#
FFTDecay=#FFTDecay#
Sensitivity=35
Bands=#BarCount#
Group=AudioMeasures
Disabled=0

; Mesures des bandes (exemple pour 5 bandes, étendre jusqu'à 20)
[MeasureBand1]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=1
Group=AudioMeasures

[MeasureBand2]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudio
Type=Band
BandIdx=2
Group=AudioMeasures

; ... (ajouter jusqu'à MeasureBand20)

; Background
[MeterBackground]
Meter=Shape
Shape=Rectangle 0,0,(#BarCount#*(#BarWidth#+#BarGap#)),#Height#,2 | Fill Color 0,0,0,50 | StrokeWidth 0
Group=Visualizer

; Barres du visualiseur
[MeterBar1]
Meter=Bar
MeasureName=MeasureBand1
X=0
Y=0
W=#BarWidth#
H=#Height#
BarColor=#Color#
BarOrientation=Vertical
DynamicVariables=1
Group=Visualizer

[MeterBar2]
Meter=Bar
MeasureName=MeasureBand2
X=(#BarWidth#+#BarGap#)r
Y=0
W=#BarWidth#
H=#Height#
BarColor=#Color#
BarOrientation=Vertical
DynamicVariables=1
Group=Visualizer

; ... (ajouter jusqu'à MeterBar20)