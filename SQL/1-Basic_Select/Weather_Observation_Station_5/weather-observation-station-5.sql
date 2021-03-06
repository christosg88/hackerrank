(
    SELECT      DISTINCT STATION.CITY, CHAR_LENGTH(STATION.CITY)
    FROM        STATION
    ORDER BY    CHAR_LENGTH(STATION.CITY) DESC, STATION.CITY ASC
    LIMIT       1
)

UNION

(
    SELECT      DISTINCT STATION.CITY, CHAR_LENGTH(STATION.CITY)
    FROM        STATION
    ORDER BY    CHAR_LENGTH(STATION.CITY) ASC, STATION.CITY ASC
    LIMIT       1
);
