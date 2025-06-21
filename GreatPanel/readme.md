### Correspondance StringIndex pour la Regex OpenWeatherMap

| StringIndex | Donnée JSON                  | Chemin complet                  | Exemple de valeur |
|-------------|------------------------------|----------------------------------|-------------------|
| 1           | ID conditions météo          | `weather[0].id`                 | `804`             |
| 2           | Groupe météo principal       | `weather[0].main`               | `"Clouds"`        |
| 3           | Description météo            | `weather[0].description`        | `"couvert"`       |
| 4           | Icône météo                  | `weather[0].icon`               | `"04d"`           |
| **5**       | **Température actuelle**     | `main.temp`                     | `26.66`           |
| 6           | Température ressentie        | `main.feels_like`               | `26.66`           |
| 7           | Pression atmosphérique       | `main.pressure`                 | `1021`            |
| 8           | Humidité                     | `main.humidity`                 | `42`              |
| 9           | Vitesse vent                 | `wind.speed`                    | `4.49`            |
| 10          | Direction vent               | `wind.deg`                      | `63`              |
| 11          | Couverture nuageuse          | `clouds.all`                    | `100`             |
| 12          | Code pays                    | `sys.country`                   | `"FR"`            |
| 13          | Lever de soleil (timestamp)  | `sys.sunrise`                   | `1750390559`      |
| 14          | Coucher de soleil (timestamp)| `sys.sunset`                    | `1750449589`      |
| 15          | Décalage horaire             | `timezone`                      | `7200`            |
| 16          | Nom de la ville              | `name`                          | `"Ville"`         |