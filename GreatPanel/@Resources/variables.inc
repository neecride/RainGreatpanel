[Variables]
Scale=1.3
ScrollMouseIncrement=0.1
Font=Bebas Neue
fontName=Roboto
textSize=10
colorBar=116,235,0,255
colorText=255,255,255,205
theme=light ; theme meteo
DefaultCover=#@#/Images/default.png
URL=https://api.openweathermap.org/data/2.5/weather?q=#Country#&appid=#APIKey#&lang=#Lang#&units=#Unites#
Regex=(?siU).*"weather":\[\{.*?"id":(\d+).*?"main":"(.*?)".*?"description":"(.*?)".*?"icon":"(.*?)".*?\}\],.*?"main":\{.*?"temp":([-]?\d+\.?\d*),.*?"feels_like":([-]?\d+\.?\d*),.*?"humidity":(\d+).*?\}.*?"wind":\{.*?"speed":([-]?\d+\.?\d*).*?\}.*?"name":"([^"]+)"
APIKey=yourapikey
Unites=metric
DynamicVariables=1
UpdateRate=600
Country=Paris
BackgroundChoice=3
Lang=Fr
PlayerName=iTunes