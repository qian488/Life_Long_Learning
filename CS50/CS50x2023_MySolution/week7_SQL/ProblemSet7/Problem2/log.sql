-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 先查看案子有什么
SELECT * FROM crime_scene_reports 
WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- 295|2021|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
-- 297|2021|7|28|Humphrey Street|Littering took place at 16:36. No known witnesses.
-- 295|2021|7|28|汉弗莱街|CS50鸭子在上午10:15在汉弗莱街面包店被盗。今天与三位在场的目击者进行了访谈——每个人的访谈记录都提到了面包店。
-- 297|2021|7|28|汉弗莱街|在16:36发生了乱丢垃圾。没有已知目击者。

-- 查询具体访谈内容
SELECT * FROM interviews 
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- 161|Ruth|2021|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from 
-- the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- 162|Eugene|2021|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- 163|Raymond|2021|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then 
-- asked the person on the other end of the phone to purchase the flight ticket. 
-- 161|露丝|2021|7|28|在盗窃发生后的十分钟内，我看到小偷上了面包店停车场的车然后开车走了。如果你有面包店停车场的监控录像，你可能想查看在那个时间框架内离开停车场的车辆。
-- 162|尤金|2021|7|28|我不知道小偷的名字，但我认出了那个人。今天早上，在我来艾玛面包店之前，我路过Leggett街的自动取款机时看到小偷在那里取钱。
-- 163|雷蒙德|2021|7|28|当小偷离开面包店的时候，他们打电话给某人，和他们聊了不到一分钟。在电话中，我听到小偷说明天打算乘坐最早一班飞机离开五十镇。然后小偷要求电话另一端的人购买机票。\

-- 针对Ruth的论述去查找 查看停车场监控录像
SELECT * FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25;

-- 260|2021|7|28|10|16|exit|5P2BI95
-- 261|2021|7|28|10|18|exit|94KL13X
-- 262|2021|7|28|10|18|exit|6P58WS2
-- 263|2021|7|28|10|19|exit|4328GD8
-- 264|2021|7|28|10|20|exit|G412CB7
-- 265|2021|7|28|10|21|exit|L93JTIZ
-- 266|2021|7|28|10|23|exit|322W7JE
-- 267|2021|7|28|10|23|exit|0NTHK55

-- 针对Eugene的论述查找 Leggett街 自动取款机 取钱 
SELECT * FROM atm_transactions 
WHERE year = 2021 AND month = 7 AND day = 28 
AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

-- 246|28500762|2021|7|28|Leggett Street|withdraw|48
-- 264|28296815|2021|7|28|Leggett Street|withdraw|20
-- 266|76054385|2021|7|28|Leggett Street|withdraw|60
-- 267|49610011|2021|7|28|Leggett Street|withdraw|50
-- 269|16153065|2021|7|28|Leggett Street|withdraw|80
-- 288|25506511|2021|7|28|Leggett Street|withdraw|20
-- 313|81061156|2021|7|28|Leggett Street|withdraw|30
-- 336|26013199|2021|7|28|Leggett Street|withdraw|35

-- 针对Raymond的论述的查找 明天打算乘坐最早一班飞机离开五十镇 小偷要求电话另一端的人购买机票
SELECT * FROM flights      
WHERE origin_airport_id = (SELECT id FROM airports WHERE city LIKE "Fiftyville")
AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1;

-- 36|8|4|2021|7|29|8|20

-- 梳理目前获得的信息
-- 根据三个访谈，可以获得离开停车场的车辆，取款机取钱账号，第二天最早的航班信息
-- 根据这些信息去查找相关的人

-- 车牌号属于谁
SELECT people.name,bakery_security_logs.license_plate FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE (year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25);

-- Vanessa|5P2BI95
-- Bruce|94KL13X
-- Barry|6P58WS2
-- Luca|4328GD8
-- Sofia|G412CB7
-- Iman|L93JTIZ
-- Diana|322W7JE
-- Kelsey|0NTHK55

-- 查找取款账号属于谁
SELECT people.name,atm_transactions.account_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE (year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street");

-- Bruce|49610011
-- Kaelyn|86363979
-- Diana|26013199
-- Brooke|16153065
-- Kenny|28296815
-- Iman|25506511
-- Luca|28500762
-- Taylor|76054385
-- Benista|81061156

-- 查看符合条件的机票的机场信息

SELECT airports.* FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.id = 36;

-- 4|LGA|LaGuardia Airport|New York City

-- 查机票购买信息
SELECT people.name, people.passport_number, people.phone_number FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = 36;

-- Doris|7214083635|(066) 555-9701
-- Sofia|1695452385|(130) 555-0289
-- Bruce|5773159633|(367) 555-5533
-- Edward|1540955065|(328) 555-1152
-- Kelsey|8294398571|(499) 555-9472
-- Taylor|1988161715|(286) 555-6063
-- Kenny|9878712108|(826) 555-1652
-- Luca|8496433585|(389) 555-5198

-- 取交集
SELECT people.name FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE (year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25)
INTERSECT
SELECT people.name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE (year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street")
INTERSECT
SELECT people.name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE (flight_id = 36);

-- Bruce
-- Luca

-- 小偷应该就是这两者？确定同伙是谁
-- 通话时间少于1分钟

SELECT people.name, phone_calls.* FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE (year = 2021 AND month = 7 AND day = 28 AND phone_calls.duration < 60
AND name IN ("Bruce","Luca"));

-- Bruce|233|(367) 555-5533|(375) 555-8161|2021|7|28|45

-- 查询Bruce打给了谁

SELECT name, phone_number FROM people
WHERE phone_number = "(375) 555-8161";

-- Robin|(375) 555-8161

-- 破案
-- The THIEF is: Bruce
-- The city the thief ESCAPED TO: New York City
-- The ACCOMPLICE is: Robin