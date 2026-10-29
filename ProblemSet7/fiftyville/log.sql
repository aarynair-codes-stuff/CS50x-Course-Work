-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 1. Crime Scene Report
SELECT id, description FROM crime_scene_reports WHERE year = 2025 AND month = 7 AND day = 28 AND street = "Humphrey Street";

-- id = 295, 10:15am at the bakery, three witnesses present

-- 2. Interviews
SELECT name, transcript FROM interviews WHERE year = 2025 AND month = 7 AND day = 28;

-- Ruth: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Eugene: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Raymond: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- 3. Bakery Security Logs
SELECT id, activity, license_plate, hour, minute FROM bakery_security_logs WHERE year = 2025 AND month = 7 AND day = 28 AND hour = 10 ORDER BY hour, minute;

-- Reg that left after crime was called 5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55

-- 4. People
SELECT name, phone_number, passport_number FROM people WHERE license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');

-- Collected names and numbers.
-- Passport numbers: 2963008352, 7526138472, 7049073643, 1695452385, 1988161715, 8496433585, 3592750733, 8294398571, 5773159633

-- 5. Phone numbers
SELECT caller, receiver FROM phone_calls WHERE year = 2025 AND month = 7 AND day = 28 AND duration < 60;
-- Number pairs: | (130) 555-0289 | (996) 555-8899 |
-- | (499) 555-9472 | (892) 555-8872 |
-- | (367) 555-5533 | (375) 555-8161 |
-- | (499) 555-9472 | (717) 555-1342 |
-- | (286) 555-6063 | (676) 555-6554 |
-- | (770) 555-1861 | (725) 555-3243 |
-- | (031) 555-6622 | (910) 555-3251 |
-- | (826) 555-1652 | (066) 555-9701 |
-- | (338) 555-6650 | (704) 555-2131 |

-- Sofia, Diana, Kelsey, Bruce

-- 6. Airport Id
SELECT id from airports WHERE city = "Fiftyville";

-- Fiftyville airport id = 8

-- 7. Flight Ids
SELECT id, destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = 8 AND year = 2025 AND month = 7 AND day = 29 ORDER BY hour, minute;

-- Earliest flight ID is 36, destination id is 4

-- 8. Destination Airport Id
SELECT city from airports WHERE id = 4;

-- Thief escaped to New York City

-- 9. Passengers' passport numbers
SELECT name, passport_number FROM people WHERE name IN ('Sofia', 'Diana', 'Kelsey', 'Bruce');

-- Sofia   1695452385
-- Diana   3592750733
-- Kelsey  8294398571
-- Bruce   5773159633

-- 10. Passengers on the flight
SELECT passport_number, seat FROM passengers WHERE passport_number IN (1695452385, 3592750733, 8294398571, 5773159633) AND flight_id = 36;

-- Sofia, Bruce, Kelsey

-- 11. ATM Transactions
SELECT people.name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE atm_transactions.year = 2025 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw' AND people.name IN ('Sofia', 'Kelsey', 'Bruce');

-- Only Bruce made a transaction

-- 12. Receiver Number
SELECT people.name AS caller_name, phone_calls.receiver FROM phone_calls JOIN people ON phone_calls.caller = people.phone_number WHERE phone_calls.year = 2025 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60 AND people.name = 'Bruce';

-- Receiver number: (375) 555-8161

-- 13. Receiver Name
SELECT name FROM people WHERE phone_number = "(375) 555-8161";

-- Robin was the accomplice
