-- Searching for the crime report on Humphrey Street on July 28, 2023
SELECT * FROM crime_scene_reports
WHERE month = 7
  AND day = 28
  AND street = 'Humphrey Street'
ORDER BY time DESC;

-- Log: The crime report for Humphrey Street on July 28, 2023 has been found. Now searching for people related to this crime.
SELECT * FROM people

-- Finds all phone calls made on July 28, 2023, and checks if anyone from the `people` table was involved
SELECT * FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28
AND (caller IN (SELECT phone_number FROM people) OR receiver IN (SELECT phone_number FROM people));

SELECT phone_number FROM people;

SELECT * FROM interviews
WHERE name IN (SELECT name FROM people WHERE phone_number = 'número_do_telefone');
