[Variables]
@IncludeVariables=#@#variables.inc

; --- Musique ---

; ---------- MESURES ITUNES ----------

[MeasurePlayer]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=STATUS

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


; --- AFFICHAGE COVER ---
[MeasureCover]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasurePlayer]
PlayerType=COVER
Substitute="":"#DefaultCover#"

[MeterCoverBackground]
Meter=Image
ImageName=#DefaultCover#
X=178
Y=273
W=145
H=145
BorderCrop=20,2,3,4
SolidColor=0,0,0,1

[MeterCover]
Meter=Image
MeasureName=MeasureCover
ImageName=[MeasureCover]
X=0r
Y=0r
W=145
H=145
PreserveAspectRatio=1
Container=MeterCoverBackground
DynamicVariables=1

; Bordure décorative
[MeterCoverBorder]
Meter=Shape
Shape=Rectangle 178,273,145,145 | StrokeWidth 4 | Stroke Color  46,50,97,255 | Fill Color 0,0,0,0

; ---------- INFOS TEXTUELLES ----------
[MeterTitle]
Meter=String
MeasureName=MeasureTitle
FontFace=#font#
FontSize=18
FontColor=179,179,179,255
X=85
Y=340
W=140
H=22
ClipString=2
StringAlign=Center
AntiAlias=1

[MeterArtist]
Meter=String
MeasureName=MeasureArtist
FontFace=#font#
FontSize=15
FontColor=46,50,97,255
X=0r
Y=23r
W=150
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
Y=23r
Text="%1 / %2"
StringAlign=Center
AntiAlias=1

; --- Contrôles iTunes avec PNG ---
[MeterPrev]
Meter=Image
ImageName=#@#/Images/prev.png
X=20
Y=283
W=20
H=20
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Previous"]
AntiAlias=1

[MeterPlayPause]
Meter=Image
ImageName=#@#Images/[mStateButton]
X=73
Y=283
W=20
H=20
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "PlayPause"]
AntiAlias=1
DynamicVariables=1
IfCondition=MeasurePlayer=2
IfTrueAction=[!SetVariable PlayIcon "#@#pause.png"][!UpdateMeter MeterPlayPause][!Redraw]
IfFalseAction=[!SetVariable PlayIcon "#@#play.png"][!UpdateMeter MeterPlayPause][!Redraw]

[MeterNext]
Meter=Image
ImageName=#@#/Images/next.png
X=122
Y=283
W=20
H=20
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Next"]
AntiAlias=1

; --- BARRE DE PROGRESSION MUSICALE ---
[MeterMusicProgressBG]
Meter=Image
X=178
Y=273
W=145
H=145
SolidColor=100,100,100,100
Shape=Rectangle 46,50,97,255 | Fill Color 100,100,100,100
AntiAlias=1

[MeterMusicProgress]
Meter=Bar
MeasureName=MeasureProgress
X=0r
Y=0r
W=145
H=145
BarColor=65,105,225,220
BarOrientation=Horizontal
Solid=1
Container=MeterMusicProgressBG
DynamicVariables=1
AntiAlias=1
