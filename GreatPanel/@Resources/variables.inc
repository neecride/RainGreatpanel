[Variables]
PlayerName=iTunes
Font=Bebas Neue
DefaultCover=#@#/Images/default.png
APIKey=1e5071d0fcf050f8bb1e062e5a54eab3
Ville=Cambrai 
Unites=metric  ; metric (°C) / imperial (°F)
URL=https://api.openweathermap.org/data/2.5/weather?q=#Ville#&appid=#APIKey#&lang=fr&units=metric
Regex="(?si).*\{.*"weather":.*\{.*"id":[\s]*([\d]+).*"main":[\s]*"([\w\s]+)".*"description":[\s]*"([\w\s]+)".*"icon":[\s]*"([\d]{2}[dn])".*"main":.*\{.*"temp":[\s]*([-]?[\d]+[\.]?[\d]*).*"feels_like":[\s]*([-]?[\d]+[\.]?[\d]*).*"pressure":[\s]*([-]?[\d]+[\.]?[\d]*).*"humidity":[\s]*([-]?[\d]+[\.]?[\d]*).*"wind":.*\{.*"speed":[\s]*([-]?[\d]+[\.]?[\d]*).*"deg":[\s]*([-]?[\d]+[\.]?[\d]*).*"clouds":.*\{.*"all":[\s]*([-]?[\d]+[\.]?[\d]*).*"sys":.*\{.*"country":[\s]*"([\w]{2})".*"sunrise":[\s]*([\d]+).*"sunset":[\s]*([\d]+).*"timezone":[\s]*([-]?[\d]+).*"name":[\s]*"([\w\s]+)".*\}.*"
UpdateRate=900  ; Actualisation toutes les 15 minutes (900 secondes)
;Test url api : https://api.openweathermap.org/data/2.5/weather?q=Paris&units=metric&lang=fr&appid=1e5071d0fcf050f8bb1e062e5a54eab3
