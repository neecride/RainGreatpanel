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

[MeasureCover]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasurePlayer]
PlayerType=COVER
Substitute="":"#DefaultCover#"

[MeterCoverBackground]
Meter=Image
MaskImageName=#DefaultCover#
X=178
Y=271
W=150
H=150

[MeterAlbumArt]
Meter=Image
MeasureName=MeasureCover
MaskImageName=#@#Images/Mask.png
X=0r
Y=0r
W=150
H=150

; ---------- INFOS TEXTUELLES ----------
[MeterTitle]
Meter=String
MeasureName=MeasureTitle
FontFace=#font#
FontSize=18
FontColor=179,179,179,255
X=80
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

[MeterBar]
Meter=Shape
X=2
Y=17r
Shape=Rectangle 0,0,(120*#Scale#),(1.5*#Scale#),0 | Fill Color 0,0,0,30 | StrokeWidth 0
Shape2=Rectangle 0,0,([MeasureProgress]*1.2*#Scale#),(1.5*#Scale#),0 | Fill Color 0,0,0 | StrokeWidth 0
Shape3=Ellipse ([MeasureProgress]*1.2*#Scale#),(0.8*#Scale#),(1.5*#Scale#) |Fill Color 0,0,0 | StrokeWidth 0
Shape4=Rectangle 0,(-1*#Scale#),(120*#Scale#),(3*#Scale#),0 | Fill Color 0,0,0,1 | StrokeWidth 0
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure "MeasureProgress" "SetPosition $MouseX:%$"]

; --- Contrôles iTunes avec PNG ---
[MeterPlayPause]
Meter=Image
ImageName=#@#Images/[mStateButton]
X=15
Y=272
W=40
H=40
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "PlayPause"]
IfTrueAction=[!SetVariable PlayIcon "#@#Pause.png"][!UpdateMeter MeterPlayPause][!Redraw]
IfFalseAction=[!SetVariable PlayIcon "#@#Play.png"][!UpdateMeter MeterPlayPause][!Redraw]
AntiAlias=1
DynamicVariables=1
IfCondition=MeasurePlayer=2
ImageTint=15, 15, 15

[MeterPrev]
Meter=Image
ImageName=#@#/Images/Previous.png
X=60r
Y=284
W=20
H=20
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Previous"]
AntiAlias=1
ImageTint=15, 15, 15

[MeterNext]
Meter=Image
ImageName=#@#/Images/Next.png
X=40r
Y=0r
W=20
H=20
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Next"]
AntiAlias=1
ImageTint=15, 15, 15