SELECT      DISTINCT STATION.CITY
FROM        STATION
WHERE
(
    STATION.CITY LIKE "a%" OR
    STATION.CITY LIKE "e%" OR
    STATION.CITY LIKE "i%" OR
    STATION.CITY LIKE "o%" OR
    STATION.CITY LIKE "u%"
)
AND
(
    STATION.CITY LIKE "%a" OR
    STATION.CITY LIKE "%e" OR
    STATION.CITY LIKE "%i" OR
    STATION.CITY LIKE "%o" OR
    STATION.CITY LIKE "%u"
);
