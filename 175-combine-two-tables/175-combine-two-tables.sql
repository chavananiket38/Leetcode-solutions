# Write your MySQL query statement below
SELECT Person.firstname, Person.lastname, Address.city, Address.state
FROM Address RIGHT JOIN Person ON Person.personId = Address.personId;