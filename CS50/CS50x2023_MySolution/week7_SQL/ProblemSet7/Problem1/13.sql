SELECT DISTINCT people.name FROM people
JOIN stars AS s1 ON people.id = s1.person_id
JOIN movies ON s1.movie_id = movies.id
JOIN stars AS s2 ON movies.id = s2.movie_id
JOIN people AS p2 ON s2.person_id = p2.id AND p2.birth = 1958 AND p2.name = 'Kevin Bacon'
WHERE s1.person_id != (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958);