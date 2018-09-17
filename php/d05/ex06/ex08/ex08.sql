SELECT last_name, first_name, DATE(birthdate) AS 'birthdate'
FROM user_card
//
ORDER BY last_name;