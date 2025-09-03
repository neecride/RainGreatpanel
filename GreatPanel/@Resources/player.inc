[Variables]
@IncludeVariables=#@#variables.inc

; --- Musique ---

[MeasureAudio]
Measure=Plugin
Plugin=AudioLevel
Port=Output
Bands=#BarCount#
FFTSize=3072
FFTAttack=40
FFTDecay=80
FreqMin=40
FFTOverlap=(3072/2)
FreqMax=10000
Sensitivity=30
DynamicVariables=1

; ---------- MESURES ITUNES ----------

[MeasurePlayer]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=PROGRESS

[MeasureProgress]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasurePlayer]
PlayerType=PROGRESS

[MeasurePosition]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasurePlayer]
PlayerType=POSITION
Substitute="0:00":""

[MeasureDuration]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasurePlayer]
PlayerType=DURATION

[MeasureTitle]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasurePlayer]
PlayerType=TITLE
Substitute="":"Aucun titre"

[MeasureArtist]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasurePlayer]
PlayerType=ARTIST
Substitute="":"Artiste inconnu"

[MeasureAlbum]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasurePlayer]
PlayerType=ALBUM
Substitute="":"Album inconnu"

[mStateButton]
Measure=PLUGIN
Plugin=NowPlaying.dll
PlayerName=[MeasurePlayer]
PlayerType=STATE
Substitute="0":"play.png","1":"pause.png","2":"play.png"

[MeasureCover]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasurePlayer]
PlayerType=COVER
Substitute="":"#DefaultCover#"

[MeterCoverBackground]
Meter=Image
MaskImageName=#@#Images/player/Mask.png
X=184
Y=265
W=150
H=150

[MeterAlbumArt]
Meter=Image
MeasureName=MeasureCover
MaskImageName=#@#Images/player/Mask.png
X=0r
Y=0r
W=150
H=150

; ---------- INFOS TEXTUELLES ----------

[MeterArtist]
Meter=String
MeasureName=MeasureArtist
FontFace=#font#
FontSize=18
FontColor=179,179,179,255
X=83
Y=330
W=140
H=22
ClipString=2
StringAlign=Center
AntiAlias=1

[MeterTitle]
Meter=String
MeasureName=MeasureTitle
FontFace=#font#
FontSize=15
FontColor=46,50,97,255
X=0r
Y=30r
W=140
H=22
ClipString=2
StringAlign=Center
AntiAlias=1

[MeterTime]
Meter=String
MeasureName=MeasurePosition
MeasureName2=MeasureDuration
FontFace=#font#
FontSize=10
FontColor=179,179,179,255
X=0r
Y=30r
Text="%1 / %2"
StringAlign=Center
AntiAlias=1

[MeterClick]
Meter=Image
SolidColor=255,255,255,0
W=#BarWidth#
H=#BarHeight#
X=0
Y=432
LeftMouseUpAction=[!CommandMeasure "MeasureProgress" "SetPosition $MouseX:%$"]

[MeterProgress]
Meter=Shape
Shape=Rectangle 0,0,([MeasurePlayer:%]/100*#BarWidth#),#BarHeight#,2/2 | Fill Color #ProgressColor# | StrokeWidth 0
X=0
Y=432
DynamicVariables=1

; --- Contrôles iTunes avec PNG ---
[MeterPlayPause]
Meter=Image
ImageName=#@#Images/player/[mStateButton]
X=15
Y=268
W=40
H=40
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "PlayPause"]
IfTrueAction=[!SetVariable PlayIcon "#@#Pause.png"][!UpdateMeter MeterPlayPause][!Redraw]
IfFalseAction=[!SetVariable PlayIcon "#@#Play.png"][!UpdateMeter MeterPlayPause][!Redraw]
AntiAlias=1
DynamicVariables=1
IfCondition=MeasurePlayer=2
ImageTint=15, 15, 15
MouseOverAction=[!SetOption MeterPlayPause ImageTint "18,160,230"][!Update]
MouseLeaveAction=[!SetOption MeterPlayPause ImageTint "15, 15, 15"][!Update]

[MeterPrev]
Meter=Image
ImageName=#@#/Images/player/Previous.png
X=60r
Y=279
W=20
H=20
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Previous"]
AntiAlias=1
ImageTint=15, 15, 15
MouseOverAction=[!SetOption MeterPrev ImageTint "18,160,230"][!Update]
MouseLeaveAction=[!SetOption MeterPrev ImageTint "15, 15, 15"][!Update]

[MeterNext]
Meter=Image
ImageName=#@#/Images/player/Next.png
X=40r
Y=0r
W=20
H=20
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Next"]
AntiAlias=1
ImageTint=15, 15, 15
MouseOverAction=[!SetOption MeterNext ImageTint "18,160,230"][!Update]
MouseLeaveAction=[!SetOption MeterNext ImageTint "15, 15, 15"][!Update]

; === Barre 1 ===
[MeterBar1]
Meter=Shape
; animation symétrique (haut et bas)
Shape=Rectangle 0,(#MaxHeight#/2 - (Max([MeasureAudio:1],#MinHeight#)*#MaxHeight#/2)),#BWidth#,(Max([MeasureAudio:1],#MinHeight#)*#MaxHeight#),#CornerRadius# | Fill LinearGradient MyGradient1 | StrokeWidth 0
MyGradient1=0 | 7,7,7,255 ; 0.0 | 7,7,7,255 ; 1.0
DynamicVariables=1
X=25
Y=439

; === Barre 2 ===
[MeterBar2]
Meter=Shape
Shape=Rectangle (#BWidth#),(#MaxHeight#/2 - (Max([MeasureAudio:2],#MinHeight#)*#MaxHeight#/2)),#BWidth#,(Max([MeasureAudio:2],#MinHeight#)*#MaxHeight#),#CornerRadius# | Fill LinearGradient MyGradient2 | StrokeWidth 0
MyGradient2=0 | 7,7,7,255 ; 0.0 | 7,7,7,255 ; 1.0
DynamicVariables=1
X=20r
Y=0r

; === Barre 3 ===
[MeterBar3]
Meter=Shape
Shape=Rectangle (#BWidth#*2),(#MaxHeight#/2 - (Max([MeasureAudio:3],#MinHeight#)*#MaxHeight#/2)),#BWidth#,(Max([MeasureAudio:3],#MinHeight#)*#MaxHeight#),#CornerRadius# | Fill LinearGradient MyGradient3 | StrokeWidth 0
MyGradient3=0 | 7,7,7,255 ; 0.0 | 7,7,7,255 ; 1.0
DynamicVariables=1
X=150
Y=0r

; === Barre 4 ===
[MeterBar4]
Meter=Shape
Shape=Rectangle (#BWidth#*3),(#MaxHeight#/2 - (Max([MeasureAudio:4],#MinHeight#)*#MaxHeight#/2)),#BWidth#,(Max([MeasureAudio:4],#MinHeight#)*#MaxHeight#),#CornerRadius# | Fill LinearGradient MyGradient4 | StrokeWidth 0
MyGradient4=0 | 7,7,7,255 ; 0.0 | 7,7,7,255 ; 1.0
DynamicVariables=1
X=20r
Y=0r