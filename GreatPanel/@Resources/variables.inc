[Variables]
PlayerName=iTunes
Font=Bebas Neue
theme=light ; theme meteo
DefaultCover=#@#/Images/default.png
APIKey= your api key
Ville=Paris
Unites=metric  ; metric (°C) / imperial (°F)
Lang=fr
URL=https://api.openweathermap.org/data/2.5/weather?q=Paris&appid=yourkeyhere&lang=fr&units=Metric
Regex=(?siU).*"weather":\[\{.*?"id":(\d+).*?"main":"(.*?)".*?"description":"(.*?)".*?"icon":"(.*?)".*?\}\],.*?"main":\{.*?"temp":([-]?\d+\.?\d*),.*?"feels_like":([-]?\d+\.?\d*),.*?"humidity":(\d+).*?\}.*?"wind":\{.*?"speed":([-]?\d+\.?\d*).*?\}.*?"name":"([^"]+)"
UpdateRate=1800  ; Actualisation toutes les 15 minutes (900 secondes)
